#!/bin/bash

# Compile the C++ program
c++ -std=c++17 ../main.cpp -o replace

# Test case 1: Valid case
echo "Running Test 1: Valid Case"
./replace valid.txt ex04 EX04
if diff -q valid.replace.txt <(echo -e "This is EX04. In EX04 you have to check newline in s1.\nI found EX04 quite interesting.") > /dev/null; then
	echo "Test 1 Passed"
else
	echo "Test 1 Failed"
	diff valid.replace.txt <(echo -e "This is EX04. In EX04 you have to check newline in s1.\nI found EX04 quite interesting.")
fi

# Test case 2: Empty file (should not modify anything)
echo "Running Test 2: Empty File"
./replace empty.txt hi hello
if diff -q empty.replace.txt <(echo -n "") > /dev/null; then
	echo "Test 2 Passed (no content in the output file)"
else
	echo "Test 2 Failed"
	diff empty.replace.txt <(echo -n "")
fi

# Test case 3a: Newlines in file (testing multiple replacements)
echo "Running Test 3: Newlines in File"
./replace newlines.txt $'\n' ""
if diff -q newlines.replace.txt <(echo -n "123456789") > /dev/null; then
	echo "Test 3a Passed"
else
	echo "Test 3a Failed"
	diff newlines.replace.txt <(echo -n "123456789")
fi

# Test case 3b: Newlines in file (testing multiple replacements)
echo "Running Test 3: Newlines in File"
./replace newlines2.txt Hi$'\n'Hive ""
if diff -q newlines2.replace.txt <(echo "!Try to find me!Hi Hive!") > /dev/null; then
	echo "Test 3b Passed"
else
	echo "Test 3b Failed"
	diff newlines2.replace.txt <(echo "!Try to find me!Hi Hive!")
fi

# Test case 4: Recursion (test multiple replacements in a line)
echo "Running Test 4: Recursion (is replaced with this multiple times)"
./replace recursion.txt is this
if diff -q recursion.replace.txt <(echo "Ththis this a recursion.") > /dev/null; then
	echo "Test 4 Passed"
else
	echo "Test 4 Failed"
	diff recursion.replace.txt <(echo "Ththis this a recursion.")
fi

# Test case 5: Error when file doesn't exist
echo "Running Test 5: File doesn't exist"
./replace non_existent_file.txt foo bar
if [ $? -ne 0 ]; then
	echo "Test 5 Passed (expected error)"
else
	echo "Test 5 Failed"
	diff non_existent_file.txt <(echo "")
fi

# Test case 6: Empty `s1`
echo "Running Test 6: Empty s1"
./replace valid.txt "" bar
if [ $? -eq 1 ]; then
	echo "Test 6 Passed (expected error)"
else
	echo "Test 6 Failed"
	diff valid.replace.txt <(echo -e "This is EX04. In EX04 you have to check newline in s1.\nI found EX04 quite interesting.\n")
fi

# rm replace empty.replace.txt valid.replace.txt newlines.replace.txt newlines2.replace.txt recursion.replace.txt
