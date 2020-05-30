#!/bin/bash

sum=0
function getdir() {
    for element in `ls $1`
    do
        f=$1"/"$element
        if [ -d $f ]
        then
            getdir $f
        else
            wc_res=`wc -l $f`
            nl=${wc_res% *}
            sum=`expr $sum + $nl`
        fi
    done
}

getdir $1
echo $1" total line = "$sum