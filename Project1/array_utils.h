#pragma once
#include <tuple>;
using namespace std;

void display_array(int num_array[], int size);

int entry_checker(int num_array[], int size, int num);

tuple<int, int> modify_entry(int num_array[], int size, int index, int new_num);

void add_entry(int*& arr, int& size, int& capacity, int newEntry);

void remove_entry(int*& arr, int& size, int index);