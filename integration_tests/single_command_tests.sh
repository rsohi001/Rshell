#!/bin/sh

INPUTS=("cd ." "cd /" "cd - " "mkdir test_dir" "ls -AA")

for input in "${INPUTS[@]}"
do
    echo "Executing ./rshell ${input}"
    ./rshell ${input}
done
