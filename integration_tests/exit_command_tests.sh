#!/bin/sh

INPUTS=("cd . && cd /exit" "exitcd joe || mkdir test_dir" "exit ls -AA && joe -d"
        "cd .; cd . ; cd exit  - ;")

for input in "${INPUTS[@]}"
do
    echo "Executing ./rshell ${input}"
    ./rshell ${input}
done
