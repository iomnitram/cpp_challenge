#!/bin/bash


i=1
while true; do
    if [ ! -d "challenge_$i"  ]; then
        break
    fi
    i=$((i + 1))
done

echo "Next = $i"
cp -r ./challenge_0 ./challenge_$i

find "./challenge_$i" -name "*\$NUM*" | sort -r | while read -r file; do
        dir=$(dirname "$file")
        basename=$(basename "$file")
        new_path="$dir/${basename//\$NUM/$i}"

        echo "rename: $file -> $dir -> $basename -> $new_path"
        mv "$file" "$new_path"
    done

find "./challenge_$i" -type f -exec sh -c 'echo "convert file $1"; sed -i "s/\$NUM/'$i'/g" "$1"' _ {} \;

./detect.sh
