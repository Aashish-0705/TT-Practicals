#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

std::vector<int> reverseArray(int arr[], int size) {
    std::stack<int> stack;

    // Reverse the array using the stack
    for (int i = 0; i < size; i++) {
        stack.push(arr[i]);
    }

    // Store the reversed array in a new vector
    std::vector<int> reversedArray;
    while (!stack.empty()) {
        reversedArray.push_back(stack.top());
        stack.pop();
    }

    return reversedArray;
}

std::vector<int> mergeArrays(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::vector<int> mergedArray;
    int i = 0, j = 0;
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Merge the two arrays in ascending order
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements from arr1, if any
    while (i < size1) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements from arr2, if any
    while (j < size2) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    const int size = 5;
    int arr1[size] = {10, 8, 6, 4, 2};
    int arr2[size] = {9, 8, 5, 3, 1};

    // Reverse the two arrays using a stack
    std::vector<int> reversed1 = reverseArray(arr1, size);
    std::vector<int> reversed2 = reverseArray(arr2, size);

    // Merge the reversed arrays in ascending order
    std::vector<int> merged = mergeArrays(reversed1, reversed2);

    std::cout << "Merged array in ascending order:" << std::endl;
    for (int i = 0; i < merged.size(); i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


