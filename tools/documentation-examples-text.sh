#!/bin/bash

MYPATH=`dirname $0`
cd "$MYPATH/../examples"

for path in *; do
    [ -d "${path}" ] || continue
    ls $path/*.apx >/dev/null 2>/dev/null || continue

    echo $path

    for file in $path/*.apx; do
        printf "%8s%-60s %s\n" "" "$file" "$(grep "@what" "$file" | sed "s/.*@what://")"
    done
done
