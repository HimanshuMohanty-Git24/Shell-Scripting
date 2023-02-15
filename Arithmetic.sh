#!/bin/sh
val=`expr 2 + 2` # 2 + 2 is an expression expression is evaluated and the result is assigned to val
echo "Total value : $val"
echo 'enter value of a and b'
read a b
val=`expr $a + $b`
echo "Total value : $val"
echo 'enter value of a and b'
read a b
val=`expr $a - $b`
echo "Total value : $val"
echo 'enter value of a and b'
read a b
val=`expr $a \* $b` # \* is used to escape the * character
echo "Total value : $val"
echo 'enter value of a and b'
read a b
val=`expr $a / $b` 
echo "Total value : $val"
echo 'enter value of a and b'
read a b
val=`expr $a % $b`
echo "Total value : $val"
