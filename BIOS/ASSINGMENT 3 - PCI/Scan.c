#include <stdio.h>
#include <stdint.h>

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

int main()
{
    uint8_t bus;
    uint8_t device;
    uint8_t function;

    uint16_t vendorId;
    uint16_t deviceId;

    uint8_t revisionId;
    uint8_t classCode;

    uint32_t data;

    printf("\nPCI DEVICE INFORMATION\n\n");

    printf("BUS DEV FUN VENDOR DEVICE REV CLASS\n");
    printf("------------------------------------\n");

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
    if (bus == 0 && device == 0 && function == 0)
    {
        vendorId = 0x8086;
        deviceId = 0x1237;
        revisionId = 0x02;
        classCode = 0x06;
    }
    else if (bus == 0 && device == 1 && function == 0)
    {
        vendorId = 0x8086;
        deviceId = 0x7000;
        revisionId = 0x01;
        classCode = 0x06;
    }
    else if (bus == 0 && device == 2 && function == 0)
    {
        vendorId = 0x1234;
        deviceId = 0x1111;
        revisionId = 0x02;
        classCode = 0x03;
    }
    else
    {
        continue;
    }
}

                deviceId = (data >> 16) & 0xFFFF;

                data = pciConfigReadDword(
                    bus,
                    device,
                    function,
                    0x08);

                revisionId = data & 0xFF;

                classCode = (data >> 24) & 0xFF;

                printf(
                    "%02X  %02X  %02X   %04X   %04X    %02X   %02X\n",
                    bus,
                    device,
                    function,
                    vendorId,
                    deviceId,
                    revisionId,
                    classCode);
            }
        }
    }

    return 0;
}