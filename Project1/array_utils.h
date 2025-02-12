#pragma once
#include <tuple>;
using namespace std;

int entry_checker(int num_array[], int size, int num);

tuple<int, int> modify_entry(int num_array[], int size, int index, int new_num);

void add_entry(int*& num_array, int size, int new_num);

void remove_entry(int num_array[], int size, int index, int new_num);