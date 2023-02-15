#!/bin/bash

# Get the first time from the user
read -p "Enter the first time (HH:MM:SS): " time1

# Get the second time from the user
read -p "Enter the second time (HH:MM:SS): " time2

# Convert the times to seconds
seconds1=$(date -d "$time1" +%s)
seconds2=$(date -d "$time2" +%s)

# Calculate the difference between the times in seconds
diff=$((seconds2 - seconds1))

# Convert the difference back to a formatted time string
printf "The difference between %s and %s is %02d:%02d:%02d\n" "$time1" "$time2" $((diff/3600)) $((diff%3600/60)) $((diff%60))
