#!/bin/bash


output_file="list_challenge.txt"
echo "" > "$output_file"

i=1
while true; do
    if [ -d "challenge_$i" ]; then
        echo "add_subdirectory(challenge_$i)" >> "$output_file"
        i=$((i + 1))
    else
        break
    fi
done
