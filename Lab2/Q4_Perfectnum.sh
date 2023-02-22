#Wap in shell script to find whether inputted no is a perfect number or not
#A perfect number is a positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself.
#For example, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number.
#The first perfect number is 6, because 1, 2, and 3 are its proper positive divisors, and 1 + 2 + 3 = 6.ss

echo "Enter a number"
read num
sum=0
for (( i=1; i<num; i++ ))
do
rem=`expr $num % $i`
if [ $rem -eq 0 ]
then
sum=`expr $sum + $i`
fi
done
if [ $sum -eq $num ]
then
echo "Perfect number"
else
echo "Not a perfect number"
fi  