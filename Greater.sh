#!/bin/bash
echo "Enter the first number"
read n1

echo "Enter the second number"
read n2

if [[ $n1 > $n2 ]]
then
	res=$((n1 * n2))
	echo $res
else 
	res=$((n2 / n1))
	echo $res
fi