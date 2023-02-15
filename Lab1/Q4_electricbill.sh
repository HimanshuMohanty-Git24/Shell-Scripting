#write a program to generate electric bill by taking units consumed as input 
#0-100 -3rs/unit 101-200 5rs/unit 210-300 6rs/unit greater than 300 7rs/unit
#!/bin/bash
echo "Enter the units consumed"
read units
if [ $units -le 100 ]
then
    bill=`expr $units \* 3`
    echo "The bill is $bill"
elif [ $units -le 200 ]
then
    bill=`expr $units \* 5`
    echo "The bill is $bill"
elif [ $units -le 300 ]
then
    bill=`expr $units \* 6`
    echo "The bill is $bill"
else
    bill=`expr $units \* 7`
    echo "The bill is $bill"
fi
