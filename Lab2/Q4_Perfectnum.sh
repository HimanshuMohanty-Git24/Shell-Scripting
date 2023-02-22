#Wap in shell script to find whether inputted no is a perfect number or not
echo "Enter a number"
read num
sum=0
while [ $num -gt 0 ]
do
rem=`expr $num % 10`
sum=`expr $sum + $rem`
num=`expr $num / 10`
done
if [ $temp -eq $sum ]
then
echo "Number is perfect"
else
echo "Number is not perfect"
fi