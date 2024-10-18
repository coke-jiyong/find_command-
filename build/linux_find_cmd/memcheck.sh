#!/bin/bash

time valgrind --leak-check=full --log-file=memcheck.txt --show-leak-kinds=all find / -name abcde.txt

