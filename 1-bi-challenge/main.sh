#!/bin/bash

n=1

while [ $n -le 1000000000 ]
do
    n=$(( $n + 1 ))
done

echo $n