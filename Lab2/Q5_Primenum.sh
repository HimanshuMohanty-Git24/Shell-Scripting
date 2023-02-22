#Wap in shell script to generate all the prime number within a certain range

echo "Enter the range"
read range
i=2
while [ $i -le $range ]
do
j=2
flag=0
while [ $j -lt $i ]
do
if [ `expr $i % $j` -eq 0 ]
then
flag=1
fi
j=`expr $j + 1`
done
if [ $flag -eq 0 ]
then
echo $i
fi
i=`expr $i + 1`
done