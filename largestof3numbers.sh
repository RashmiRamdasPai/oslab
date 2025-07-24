#!/bin/bash/
echo "Enter the three numbers"
read num1
read num2
read num3

max=$num1
if [[ $num2 -gt $max ]]
  then
     if [[ $num2 -gt $num3 ]]
       then
        echo "$num2 is the highest"
     else
         echo "$num3 is the highest"
    fi
else
   if [[ $num1 -gt $num3 ]]
   then
       echo "$num1 is the highest"
    else
       echo "$num3 is the highest"
    fi
    fi
