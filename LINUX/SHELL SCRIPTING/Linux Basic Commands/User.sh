#!/bin/bash

#Giving value to variable
USERNAME=$1
PASSWORD=$2

#New username created and added
sudo useradd $USERNAME

#Set user Password
echo "$USERNAME:$PASSWORD"|sudo chpasswd

#checking the password
grep "^$USERNAME:" /etc/passwd

#file open checking
if [ $? -eq 0 ]
then
    echo "User $USERNAME successfully created."
else
    echo "User creation failed."
fi


