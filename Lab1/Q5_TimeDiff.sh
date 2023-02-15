#write a shell script to find the diffrence between two time(hr:min:sec) with all the constrains of subtracting time using conditional statement
#!/bin/bash

# Read the first time input
echo "Enter the first time (in the format of hours:minutes:seconds): "
read time1

# Read the second time input
echo "Enter the second time (in the format of hours:minutes:seconds): "
read time2

# Convert the time inputs into seconds
seconds1=$(date -d "$time1" +%s)
seconds2=$(date -d "$time2" +%s)

# Calculate the difference in seconds
difference=$((seconds1 - seconds2))

# Convert the difference back to the format of hours:minutes:seconds
result=$(date -u -d@$((difference)) +%H:%M:%S)

echo "The difference between $time1 and $time2 is $result"
