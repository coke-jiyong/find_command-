#!/bin/bash



valgrind --leak-check=full --log-file=memcheck.txt --show-leak-kinds=all ./File_Explorer / memcheck.sh

