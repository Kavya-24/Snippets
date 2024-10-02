#!/bin/bash

# Function to display the directory structure
display_tree() {
    local dir="$1"
    local prefix="$2"

    # List all files and directories in the current directory
    local files=("$dir"/*)

    for file in "${files[@]}"; do
        # Check if the item is a directory
        if [ -d "$file" ]; then
            echo "${prefix}├───$(basename "$file")"
            # Call the function recursively for the subdirectory
            display_tree "$file" "$prefix  "
        else
            # Replace unexpected characters in the prefix line
            echo "${prefix//│/|   }$(basename "$file")"
        fi
    done
}

# Starting point for the tree structure
echo "Snippets"
display_tree "." "│   "
