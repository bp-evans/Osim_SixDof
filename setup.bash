#!/bin/bash

# Function to check if Eigen is installed
is_eigen_installed() {
    # Common paths where Eigen's main directory might be installed
    local eigen_base_paths=(
        "/usr/include/eigen3"
        "/usr/local/include/eigen3"
        "/opt/homebrew/include/eigen3" # For Homebrew on Apple Silicon
    )

    for base_path in "${eigen_base_paths[@]}"; do
        if [ -d "$base_path/Eigen" ]; then
            return 0 # Found the Eigen directory
        fi
    done
    return 1 # Not found
}

if is_eigen_installed; then
    echo "Eigen package found on system."
else
    echo "Eigen package not found on system."
    echo "Eigen package not found"
    OS=$(uname -s)
    if [ "$OS" = "Linux" ]; then
        echo "Detected Linux. Installing Eigen using apt-get..."
        sudo apt-get update
        sudo apt-get install libeigen3-dev
    elif [ "$OS" = "Darwin" ]; then
        echo "Detected macOS. Installing Eigen using brew..."
        # Check if Homebrew is installed
        if ! command -v brew &> /dev/null; then
            echo "Homebrew is not installed. Please install Homebrew (https://brew.sh/) and rerun this script."
            exit 1
        fi
        brew install eigen
    else
        echo "Unsupported operating system: $OS"
        exit 1
    fi
fi