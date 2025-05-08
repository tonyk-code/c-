/********************************************************************************
-This question is a leet code problem.https://leetcode.com/problems/remove-element/?envType=problem-list-v2&envId=array
-The question is: 
    Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
-Down below is the solution to the answer
*********************************************************************************/






#include <iostream>
#include <vector>
using namespace std;

// Function to remove all occurrences of 'val' from the vector 'nums'
int removeElement(vector<int>& nums, int val) {
    int count = 0;                       // Counter to track how many 'val' elements are removed
    int initial_size = nums.size();     // Save the original size of the array

    // Loop through the array
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            count++;  // We found a value to remove

            // Swap elements forward one by one to push 'val' to the end
            for (int j = i; j < nums.size() - 1; j++) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

            nums.pop_back(); // Remove the last (now duplicate or irrelevant) element

            i--; // Recheck the same index since we moved a new element into position i
        }
    }

    // Calculate how many valid (non-val) elements are left
    int k = initial_size - count;
    return k;
}

int main() {
    vector<int> array = {1, 2, 2, 4, 5, 5, 2, 6}; // Input array
    int val = 2;                                 // Value to remove

    int newLength = removeElement(array, val);   // Call your function

    // Print the resulting array (only first 'newLength' elements are valid)
    cout << "Modified array (first " << newLength << " elements): ";
    for (int i = 0; i < newLength; i++) {
        cout << array[i] << " ";
    }
    cout << "\nNew length: " << newLength << endl;

    return 0;
}
