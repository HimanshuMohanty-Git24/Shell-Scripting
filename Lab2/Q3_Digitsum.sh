#wap in shell script to find out sum of digits of a inputted number
echo "Enter a number"
read num
sum=0
while [ $num -gt 0 ]
do
rem=`expr $num % 10`
sum=`expr $sum + $rem`
num=`expr $num / 10`
done
echo "Sum of digits is $sum"

