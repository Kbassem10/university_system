#include <iostream>
#include "search.cpp"

using namespace std;

void test_search() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int linear_result = linear_search(arr, size, target);
    int binary_result = binary_search(arr, size, target);

    cout << "Linear Search Result: " << linear_result << endl;
    cout << "Binary Search Result: " << binary_result << endl;

    // Additional test cases
    target = 4;
    linear_result = linear_search(arr, size, target);
    binary_result = binary_search(arr, size, target);

    cout << "Linear Search Result (target 4): " << linear_result << endl;
    cout << "Binary Search Result (target 4): " << binary_result << endl;

    target = 11;
    linear_result = linear_search(arr, size, target);
    binary_result = binary_search(arr, size, target);

    cout << "Linear Search Result (target 11): " << linear_result << endl;
    cout << "Binary Search Result (target 11): " << binary_result << endl;
}

int main() {
    test_search();
    return 0;
}