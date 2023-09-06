#! /bin/bash

read -p "Enter The Range: " range

check_prime() {
    num=$1
    if [ $num -lt 3 ]; then
        return 1
    fi
    for ((i = 2; i <=num/2; i++));do
        if [ $((num % i)) == 0 ]; then
            return 1
        fi
    done
    return 0
}

count=1
echo "Prime Numbers upto $range:"
while [ $count -lt $range ]
do
    if check_prime $count; then
        echo "$count"
    fi
    count=$((count + 1))
done