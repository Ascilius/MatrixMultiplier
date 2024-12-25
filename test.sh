#!/bin/bash
make all

echo -e "\n-------------------------\nTest 1:\n-------------------------\n"
build/mm tests/test1.txt 1

echo -e "\n-------------------------\nTest 2:\n-------------------------\n"
build/mm tests/test2.txt 1

echo -e "\n-------------------------\nTest 3:\n-------------------------\n"
build/mm tests/test3.txt 1

echo -e "\n-------------------------\nTest 4:\n-------------------------\n"
build/mm tests/test4.txt 1

echo -e "\nAll tests ran successfully."