#!/bin/bash



valgrind --leak-check=full --log-file=memcheck.txt --show-leak-kinds=all ./a.out "$1" "$2"


