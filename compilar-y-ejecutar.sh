#!/bin/bash

clear

FILE_NAME="mlfq"

if [[ $1 == "" ]]; then
    ARG1="out.txt"

else
    ARG1=$1

fi

if [[ $2 == "" ]]; then
    ARG2="5"

else
    ARG2=$2

fi

echo -e "\033[33;1mMake clean\033[0m"
make clean

echo -e "\033[33;1mMake all\033[0m"
make all

echo -e "\033[33;1mHaciendo ejecutable\033[0m"
chmod +x "./$FILE_NAME"

echo -e "\033[33;1mCorriendo con valgrind\033[0m"
valgrind --leak-check=full -s "./$FILE_NAME" "./example.txt" "$ARG2" "$ARG3"
echo -e "\033[33;1mFin\033[0m"
