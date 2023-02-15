#!/bin/sh
echo "Enter two numbers"
read a b
if [ $a -gt $b ]
then
    echo "$a is greater than $b"
else
    echo "$b is greater than $a"
fi
