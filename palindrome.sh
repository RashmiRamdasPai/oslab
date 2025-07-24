echo "Enter the word"
read str
length=${#str}

for((i=length-1;i>=0;i--))
    do
    reverse=$reverse${str:$i:1};
    done

if [[ $reverse == "$str" ]]
  then
   echo "Palindrome"
 else
  echo "Not palindrome"
fi
