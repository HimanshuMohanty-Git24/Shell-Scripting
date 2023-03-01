#!/bin/bash

n=4


for ((i=1; i<=n; i++))
do
    
    for ((j=1; j<=n-i; j++))
    do
        echo -ne "   "
    done
    
    
    for ((j=1; j<=i; j++))
    do
        echo -ne "$j  "
    done
    
    
    for ((j=i-1; j>=1; j--))
    do
        echo -ne "$j  "
    done
    
    echo "" 
done
