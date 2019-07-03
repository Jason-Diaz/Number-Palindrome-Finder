// Lab06BCS230.cpp : Defines the entry point for the console application.
// Jason Diaz

#include "stdafx.h"
#include <iostream>
#include <string>

int getIntLength(int x);
bool checkIfPal(char stringNum[], int length);

using namespace std;


int main()
{
	int num1 = 999,num2 = 999,testNum, length;
	char stringNum[7] = { "\0" };
	bool found = false;

	do {
		testNum = num1 * num2;
		length = getIntLength(testNum); // to get the length of the number stored in the array
		sprintf_s(stringNum, "%d", testNum); // stores the number in the array

		found = checkIfPal(stringNum, length); // stores in boolean if the current number is a palindrome

		if (!found) {
			// since we want the highest number we must assume that we cannot go lower than 800
			if (num1 > 800) 
				num1--;
			else {
				num1 = 999;
				num2--;
			}
		}
	} while (!found);

	// prints result
	cout << num1 << " * " << num2 << endl;
	cout << stringNum << endl;

	system("pause");
    return 0;
}

/*
 getIntLenght - accepts an integer, returns the 
 amount of numbers the integer consists of
*/
int getIntLength(int x) {
	if (x >= 100000) return 6;
	if (x >= 10000) return 5;
	if (x >= 1000) return 4;
	if (x >= 100) return 3;
	if (x >= 10) return 2;
	return 1;
}

/*
 checkIfPal- a function that accepts a c-string, and the
 length of the number as an integer. Returns a boolean
 value determaning if the c-string is a palindrome
*/
bool checkIfPal(char stringNum[], int length) {
	// accept char string

	bool check = false; 

	//check
	for (int i = 0; i < length; i++) {
		if (stringNum[i] == stringNum[length - i - 1]) { // comparing the first and last number
			if (i == (length - 1)) { // if the check has reached the final number and it is a match the number is a palindrome
				check = true;
			}
		}
		else { // if the numbers do not match terminate the loop
			i = length;
		}
	}
	// returning bool
	return check;
}