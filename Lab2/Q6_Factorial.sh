#wap in shell script to find factorail of a number
echo "Enter the number"
read num
fact=1
while [ $num -gt 1 ]
do
fact=`expr $fact \* $num`
num=`expr $num - 1`
done
echo "Factorial is $fact"