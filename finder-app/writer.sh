#!/bin/bash

# Check if both arguments are provided
if [ $# -lt 2 ]; then
    echo "Error: Missing arguments"
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

writefile=$1
writestr=$2

# Get directory path from the full file path
dirpath=$(dirname "$writefile")

# Create directory path if it doesn't exist
mkdir -p "$dirpath"

# Check if directory creation was successful
if [ $? -ne 0 ]; then
    echo "Error: Could not create directory path $dirpath"
    exit 1
fi

# Write content to file (overwrite if exists)
echo "$writestr" > "$writefile"

# Check if file creation was successful
if [ $? -ne 0 ]; then
    echo "Error: Could not create file $writefile"
    exit 1
fi

exit 0
