#!/bin/bash
while true
do
NUMBER=$(tail -n 1 < ex2.txt)
let NUMBER=$NUMBER+1
echo $NUMBER >> ex2.txt
done