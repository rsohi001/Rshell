#!/bin/sh

INPUTS=("cd . && cd /" "cd joe || mkdir test_dir" "ls -AA && joe -d"
        "cd .; cd . ; cd   - ;")

for input in "${INPUTS[@]}"
do
    echo "Executing ./rshell ${input}"
    ../rshell ${input}
done
