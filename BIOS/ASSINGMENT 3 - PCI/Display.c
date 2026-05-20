/*
*  Program to display PCI BAR Address, Memory Type and Memory Size
*  Author   : MUTHUGANESH S
*  Date     : 19/05/2026
*  Filename : Scan.c
*  retval   : void
*/


//Header files
#include <stdio.h>
#include <stdint.h>

//Function to read dword from PCI configuration space
uint32_t pciConfigReadDword(
    uint8_t bus,
    uint8_t device,
    uint8_t function,
    uint8_t offset)
{
    uint32_t address;
    uint32_t data;

    address =
        (1U << 31) |
        ((uint32_t)bus << 16) |
        ((uint32_t)device << 11) |
        ((uint32_t)function << 8) |
        (offset & 0xFC);

    __asm__ volatile (
        "outl %0, %%dx"
        :
        : "a"(address), "d"(0xCF8)
    );

    __asm__ volatile (
        "inl %%dx, %0"
        : "=a"(data)
        : "d"(0xCFC)
    );

    return data;
}

//Function to write dword to PCI configuration space
void pciConfigWriteDword(
    uint8_t bus,
    uint8_t device,
    uint8_t function,
    uint8_t offset,
    uint32_t value)
{
    uint32_t address;

    address =
        (1U << 31) |
        ((uint32_t)bus << 16) |
        ((uint32_t)device << 11) |
        ((uint32_t)function << 8) |
        (offset & 0xFC);

    __asm__ volatile (
        "outl %0, %%dx"
        :
        : "a"(address), "d"(0xCF8)
    );

    __asm__ volatile (
        "outl %0, %%dx"
        :
        : "a"(value), "d"(0xCFC)
    );
}

//Main function
int main()
{
    uint8_t bus;
    uint8_t device;
    uint8_t function;
    uint8_t bar;

    uint16_t vendorId;
    uint16_t deviceId;

    uint32_t data;

    uint32_t barAddress;
    uint32_t originalValue;
    uint32_t sizeMask;
    uint32_t size;

    printf("\nPCI BAR INFORMATION\n\n");

    printf("BUS DEV FUN VENDOR DEVICE BAR ADDRESS      TYPE   SIZE(Bytes) SIZE(KB)\n");
    printf("-----------------------------------------------------------------------\n");

    for (bus = 0; bus < 256; bus++)
    {
        for (device = 0; device < 32; device++)
        {
            for (function = 0; function < 8; function++)
            {
                data = pciConfigReadDword(
                    bus,
                    device,
                    function,
                    0x00);

                vendorId = data & 0xFFFF;

                if (vendorId == 0xFFFF)
                {
                    continue;
                }

                deviceId = (data >> 16) & 0xFFFF;

                for (bar = 0; bar < 6; bar++)
                {
                    uint8_t offset = 0x10 + (bar * 4);

                    originalValue = pciConfigReadDword(
                        bus,
                        device,
                        function,
                        offset);

                    if (originalValue == 0x00000000)
                    {
                        continue;
                    }

                    pciConfigWriteDword(
                        bus,
                        device,
                        function,
                        offset,
                        0xFFFFFFFF);

                    sizeMask = pciConfigReadDword(
                        bus,
                        device,
                        function,
                        offset);

                    pciConfigWriteDword(
                        bus,
                        device,
                        function,
                        offset,
                        originalValue);

                    if (originalValue & 0x1)
                    {
                        barAddress = originalValue & 0xFFFFFFFC;

                        size = ~(sizeMask & 0xFFFFFFFC) + 1;

                        printf(
                            "%02X  %02X  %02X   %04X   %04X    BAR%d  %08X   IO     %10u %8u\n",
                            bus,
                            device,
                            function,
                            vendorId,
                            deviceId,
                            bar,
                            barAddress,
                            size,
                            size / 1024);
                    }
                    else
                    {
                        barAddress = originalValue & 0xFFFFFFF0;

                        size = ~(sizeMask & 0xFFFFFFF0) + 1;

                        printf(
                            "%02X  %02X  %02X   %04X   %04X    BAR%d  %08X   MMIO   %10u %8u\n",
                            bus,
                            device,
                            function,
                            vendorId,
                            deviceId,
                            bar,
                            barAddress,
                            size,
                            size / 1024);
                    }
                }
            }
        }
    }

    return 0;
}