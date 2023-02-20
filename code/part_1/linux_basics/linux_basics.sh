#!/bin/bash

cd
mkdir "my_new_folder"
cd "my_new_folder"
echo "some text" >> my_new_file.txt
nano my_new_file.txt
grep -rnw './my_new_file.txt' -e 'asdfjklö'
touch "second_file.txt"
rm "second_file.txt"
cd ..
rm -rf my_new_folder