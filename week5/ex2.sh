#!/bin/bash
touch ex2.txt
#while true
for (( i = 0; i < 10; i++ ));
do
last_num=$(tail -n 1 < ex2.txt)
let last_num=last_num+1
echo $last_num >> ex2.txt
done