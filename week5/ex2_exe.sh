#!/bin/bash
for ((i = 0; i < 10; i++))
do
./ex2.sh | ./ex2.sh&
done