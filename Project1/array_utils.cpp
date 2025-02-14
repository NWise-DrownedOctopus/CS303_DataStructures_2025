#include <array_utils.h>
#include <iostream>
#include <ostream>

// display array in console
void display_array(int num_array[], int size) {
    cout << "Current array: ";
    for (int i = 0; i < size; i++) {
        cout << num_array[i] << " ";
    }
    cout << endl;
}

// return index if value is present, -1 if not
int entry_checker(int num_array[], int size, int num) {
    for (int i = 0; i < size; i++) {
        // cout << num_array[i] << endl;
        if (num == num_array[i]) {
            return i;
        }
    }
    return -1;
}

// Modify value of int when called with index of int in the array
// return new value and old value back to the user
tuple<int, int> modify_entry(int num_array[], int size, int index, int new_num) {
    if (index >= size || index < 0) {
        cout << "index out of bounds" << endl;
        return make_tuple(-1, -1);
    }
    int old_value = num_array[index];
    num_array[index] = new_num;
    return make_tuple(num_array[index], old_value);
}

// Adds new integer to end of array
void add_entry(int*& arr, int& size, int& capacity, int new_entry) {
    if (size >- capacity) {
        // Doubles Capacity of Array
        int new_capacity = capacity * 2;
        int* new_arr = new int[new_capacity];

        // Copy old array into new array
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }

        delete[] arr;

        arr = new_arr;
        capacity = new_capacity;
    }

    // Add new entry
    arr[size] = new_entry;
    size++;
}

// intake index of array, removes int at index from array
void remove_entry(int*& arr, int& size, int index) {
    if (index >= size || index < 0) {
        cout << "index out of bounds" << endl;
        return;
    }
    cout << "Removing " << arr[index] <<" at index " << index << endl;

    // If index is last entry, we don't need to resize
    if (index == size - 1) {
        size--;
        return;
    }

    // If index is not at the end, move all values after index back one
    for (int i = index; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
