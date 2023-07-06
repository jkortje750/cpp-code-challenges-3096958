// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    
    // Write your code here
    // First check if all elements have same value)
    int ascendingCount = 0;
    int decendingCount = 0;
    bool ascending = false;
    bool decending = false;
    bool bitonic = false;
    bool all_same = true;
    for (auto x : v) {
        if (all_same) {
            all_same = (x == v[0]);
        }
    }
    if (!all_same) {
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i+1] > v[i]) {
                if (!ascending) {
                    ascendingCount++;
                    ascending = true;
                    decending = false;
                }
            } else if (v[i+1] < v[i]) {
                if (!decending) {
                    decendingCount++;
                    ascending = false;
                    decending = true;
                }
            }
        }
        if (((ascendingCount == 1) && (decendingCount == 0)) ||
            ((decendingCount == 1) && (ascendingCount == 0))) {
            bitonic = true;
        } else if ((decendingCount + ascendingCount) > 3) {
            // Only allow 3 or less slopes
            bitonic = false;
        } else if ((decendingCount > 1) || (ascendingCount > 1)) {
            if (ascending && (v[(v.size() - 1)] <= v[0])) {
                bitonic = true;
            }
            if (decending && (v[(v.size() - 1)] >= v[0])) {
                bitonic = true;
            }
        } 
    } else {
        // All were the same value
        bitonic = true;
    }
    return bitonic;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    // std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    // std::vector<int> myvec = {1, 1, 1, 1, 1};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 2};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 4};  // No
    // std::vector<int> myvec = {1, 2, 3, 4, 5};  // Yes
    // std::vector<int> myvec = {1, 2, 3, 1, 2};  // No
    // std::vector<int> myvec = {5, 4, 6, 2, 6};  // No
    // std::vector<int> myvec = {5, 4, 3, 2, 1};  // Yes
    // std::vector<int> myvec = {5, 4, 3, 2, 6};  // Yes
    // std::vector<int> myvec = {5, 4, 6, 5, 4};  // No
    // std::vector<int> myvec = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
