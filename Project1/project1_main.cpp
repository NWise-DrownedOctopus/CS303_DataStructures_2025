///////////////////////////
// Nicholas Wise
// Project #1 - Arrays
///////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <array_utils.h>

int main() {
    cout << "Hello, welcome to N Wise Project 1" << endl;
    int data[100];

    // Open Data File, and load data into a two dimensional array
    ifstream inputFile("A1input.txt");
    if (!inputFile) {
        cout << "Error opening input file" << endl;
        return -1;
    }

    string line;

    for (int i = 0; i < 100; i++) {
        inputFile >> data[i]; // Read each integer into the array
    }

    inputFile.close();

    // Test 1 //
    // A function to check if a certain integer exists in the array if the number is
    // present return the index where the number is present.
    int num_to_check = 303;
    int test1_value = entry_checker(data, 100, num_to_check);
    if (test1_value == -1) {
        cout << "Error: Unable to find value in array" << endl;
    }
    else {
        cout << "Test value index is: " << test1_value << endl;
    }

    // Test 2 //
    // A function that can modify the value of an integer when called with the index of
    // the integer in the array and return the new value and old value back to the user.
    int test2_index = 23;
    int test2_replacment_num = 333;
    tuple<int, int> test2_value = modify_entry(data, 100, test2_index, test2_replacment_num);
    if (get<0>(test2_value) == -1) {
        cout << "Error: Unable to find value at provided array index" << endl;
    }
    else {
        cout << "New value is: " << get<0>(test2_value) << endl;
        cout << "Old Value is: " << get<1>(test2_value) << endl;
    }

    // Test 3 //
    // A function that adds a new integer to the end of the array
    int test3_new_num = 333;
    add_entry(data, 100, test3_new_num);
    cout << "The new int that is on the list is: " << data[100];



    return 0;
}

