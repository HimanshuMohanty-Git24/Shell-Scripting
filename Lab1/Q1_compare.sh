#!/bin/sh
# Script to compare a to 60
read a
if [ $a -gt 60 ]
then
    echo "Greater than 60"
else
    echo "Less than 60"
fi