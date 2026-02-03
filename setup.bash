#!/bin/bash

DIR="$(pwd)/eigen-5.0.0"

if [ -d $DIR ]; then
    echo "Eigen package found"
else
    echo "Eigen package not found"
    sudo apt-get update
    sudo apt-get install libeigen3-dev
fi