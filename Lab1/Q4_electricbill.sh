#write a program to generate electric bill by taking units consumed as input 
#0-100 -3rs/unit 101-200 5rs/unit 210-300 6rs/unit greater than 300 7rs/unit
#!/bin/bash
echo "Enter the units consumed"
read units
temp=0
n=0
if [ $units -le 100 ]
then
bill=`expr $units \* 3`
echo The bill is $bill
elif [ $units -le 200 ]
then
n=`expr $units - 100`
temp=`expr $n \* 5`
bill=`expr 300 + $temp`
echo The bill is $bill
elif [ $units -le 300 ]
then
n=`expr $units - 200`
temp=`expr $n \* 6`
bill=`expr 800 + $temp`
echo The bill is $bill
else
n=`expr $units - 300`
temp=`expr $n \* 7`
bill=`expr 1400 + $temp`
echo The bill is $bill
fi

