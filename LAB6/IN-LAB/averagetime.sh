#name: Eza Rasheed
#id: er6qt
#date: 03-05-19
#filename: averagetime.sh

#!/bin/bash

# Prompt the user for the dictionary and grid file names used by my word puzzle executable
echo "Please enter your dictionary file name: "
read dictionary 
echo "Please enter your grid file name: "
read grid

# Run the program(a.out) 5 times using the ^^above parameters
# This runs the same program 5 times with the same parameters
run_1=`./a.out $dictionary $grid | tail -1`
run_2=`./a.out $dictionary $grid | tail -1`
run_3=`./a.out $dictionary $grid | tail -1`
run_4=`./a.out $dictionary $grid | tail -1`
run_5=`./a.out $dictionary $grid | tail -1`

# Total is equal to the sum of the 5 run times
total=$((run_1+run_2+run_3+run_4+run_5))

# Get the average of the running times by dividing the number of runs(5) by the total sum of the runs, and then print it
echo "The average run time is: " $(((total)/(5))) "milliseconds"


