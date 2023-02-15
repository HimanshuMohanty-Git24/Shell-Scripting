#!/bin/sh
echo $$ # PID of the current process
echo $0 # Name of the current script
echo $# # Number of arguments
echo $* # All arguments
echo $? # Exit status of the last command
echo "File Name: $0"
echo "First Parameter : $1"
echo "Second Parameter : $2"
echo "Quoted Values: $@"
echo "Quoted Values: $*"
echo "Total Number of Parameters : $#"