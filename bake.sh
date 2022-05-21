#!/bin/bash

PROJECT_NAME="sfml-platformer"
COMPILER="g++"
SRC_DIR="src"
BUILD_DIR="build"

if [[ $1 == "" ]]
then
    $COMPILER -c $SRC_DIR/Main.cpp
    mkdir -p $BUILD_DIR
    $COMPILER *.o -o $BUILD_DIR/$PROJECT_NAME
    rm *.o
elif [[ $1 == "run" ]]
then
    ./$BUILD_DIR/$PROJECT_NAME
fi
