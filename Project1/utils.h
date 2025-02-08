#include <iostream>
#include <tuple>;
using namespace std;

// Modify value of int when called with index of int in the array
// return new value and old value back to the user
int entry_checker(int num);

// Modify value of int when called with index of int in the array
// return new value and old value back to the user
tuple<int, int> modify_entry(int num);

// Adds new integer to end of array
void add_entry(int num);

// intake index of array, removes int at index from array
void remove_entry(int num);