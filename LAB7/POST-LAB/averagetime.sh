#!/bin/bash
#name: Eza Rasheed
#id: er6qt
#date: 03-20-19
#filename: averagetime.sh

# variable set to equal number of times to iterate through the for loop
c=5

# Ask for input
echo "Please enter an exponent value for counter.cpp: "
read input

# if input is "quit", the script should exit
if [[ "$input" == "quit" ]] ; then 
    exit 0; # everything executed successfully
fi

# Run the program(a.out) 5 times, print which run is being done, and then print the time it took
for (( i = 1 ; i <= c ; ++i )) ; do 
    echo "Running iteration $i..."
    run=`./a.out $input | tail -1`
    echo "time taken: $run ms"
    total=$((total + run))
done

# Print the total time it took to do 5 iterations 
echo "5 iterations took $total ms"

# calculate average time
average=$(((total) / (5)))

# print out the average time it took to do the 5 runs
echo "Average time was $average ms"



    











