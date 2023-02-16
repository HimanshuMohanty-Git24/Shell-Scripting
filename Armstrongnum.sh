#!/bin/sh
#Wap to find a number is  Armstrong number or not
echo "Enter a number"
read n
sum=0
temp=$n
while [ $n -gt 0 ]
do
r=`expr $n % 10`
sum=`expr $sum + $r \* $r \* $r`
n=`expr $n / 10`
done
if [ $sum -eq $temp ]
then
echo "Number is Armstrong"
else
echo "Number is not Armstrong"
fi