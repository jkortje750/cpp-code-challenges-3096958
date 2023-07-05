// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>


// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
void swap(int * arr, int left, int right) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
}

int partition(int * arr, int left, int right) {
    int pivotOffset = left + (right - left) / 2;
    int pivotValue = arr[pivotOffset];
    int i = left - 1;
    int j = right + 1;
    while (1) {
        while (arr[++i] < pivotValue);
        while (arr[--j] > pivotValue);
        if (i >= j) break;
        swap(arr, i, j);
    }
    return j;
}
void qsort(int * arr, int left, int right) {
    if (left >= right) {
        return;
    } else {
        int pivot = partition(arr, left, right);
        qsort(arr, left, pivot);
        qsort(arr, pivot+1, right);
    }
}

bool sort_array(int *arr, int n){

    // Write your code here
    qsort(arr, 0, n - 1);
    return true;
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 7; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}
