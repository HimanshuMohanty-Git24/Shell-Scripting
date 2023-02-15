#write a shell script to find the diffrence between two time(hr:min:sec)
#!/bin/sh
echo "Enter the first time in hr:min:sec"
read hr1 min1 sec1
echo "Enter the second time in hr:min:sec"
read hr2 min2 sec2
hr=`expr $hr1 - $hr2`
min=`expr $min1 - $min2`
sec=`expr $sec1 - $sec2`
echo "The difference is $hr:$min:$sec"