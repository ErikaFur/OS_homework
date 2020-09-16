#!/bin/bash
touch ex2_fixed.txt

#while true
for (( i = 0; i < 10; i++ ));

do
  while true
  do
    if ln ex2_fixed.txt file.lock
    then
      NUMBER=$(tail -n 1 < ex2_fixed.txt)
      let NUMBER=$NUMBER+1
      echo $NUMBER >> ex2_fixed.txt
      rm file.lock
      break
    fi
  done
done

#while one process in run, there is file.lock. Because of this file, other thread wait till this file will be delete
#