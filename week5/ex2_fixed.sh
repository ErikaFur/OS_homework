#!/bin/bash
touch file.txt
while true
do
  if ln file.txt file.lock
  then
    NUMBER=$(tail -n 1 < file.txt)
    let NUMBER=$NUMBER+1
    echo $NUMBER >> file.txt
    rm file.lock
  fi
done

#while one process in run, there is file.lock. Because of this file, other thread wait till this file will be delete
#