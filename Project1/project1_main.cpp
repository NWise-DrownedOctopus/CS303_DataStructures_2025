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
    int capacity = 100; // Initial capacity
    int size = 100;
    int* data = new int[capacity];

    // Open Data File, and load data into a two dimensional array
    ifstream inputFile("A1input.txt");
    if (!inputFile) {
        cout << "Error opening input file" << endl;
        return -1;
    }

    string line;

    for (int i = 0; i < size; i++) {
        inputFile >> data[i]; // Read each integer into the array
    }

    inputFile.close();

    try {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Check if an entry exists\n";
            cout << "2. Modify an entry\n";
            cout << "3. Add an entry\n";
            cout << "4. Remove an entry\n";
            cout << "5. Display array\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    // Test 1 //
                    // A function to check if a certain integer exists in the array if the number is
                    // present return the index where the number is present.
                    int num;
                    cout << "Enter number to check: ";
                    cin >> num;
                    int test1_value = entry_checker(data, size, num);
                    if (test1_value == -1) {
                        cout << "Error: Unable to find value in array" << endl;
                    }
                    else {
                        cout << "Number found at index is: " << test1_value << endl;
                    }
                    break;

                }
                case 2: {
                    // Test 2 //
                    // A function that can modify the value of an integer when called with the index of
                    // the integer in the array and return the new value and old value back to the user.
                    int index, new_num;
                    cout << "Enter index to modify: ";
                    cin >> index;
                    cout << "Enter new number: ";
                    cin >> new_num;
                    tuple<int, int> test2_value = modify_entry(data, size, index, new_num);
                    if (get<0>(test2_value) == -1) {
                        cout << "Error: Unable to find value at provided array index" << endl;
                    }
                    else {
                        cout << "New value is: " << get<0>(test2_value) << endl;
                        cout << "Old Value is: " << get<1>(test2_value) << endl;
                    }
                    break;
                }
                case 3: {
                    // Test 3 //
                    // A function that adds a new integer to the end of the array
                    int newEntry;
                    cout << "Enter number to add: ";
                    cin >> newEntry;
                    add_entry(data, size, capacity, newEntry);
                    cout << "The new int that is on the list is: " << data[100] << endl;
                    break;
                }
                case 4: {
                    // Test 4//
                    // A function which intakes an index of an array and removes the integer altogether
                    int index;
                    cout << "Enter index to remove: ";
                    cin >> index;
                    remove_entry(data, size, index);
                    break;
                }
                case 5: {
                    display_array(data, size);
                    break;
                }
                case 6: {
                    cout << "Exiting program.\n";
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 6);
    }
    catch (...) {
        cout << "Invalid choice." << endl;
    }

    delete[] data;
    return 0;
}

