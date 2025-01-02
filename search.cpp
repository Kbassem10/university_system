#include <iostream>

using namespace std;

int linear_search(int* arr,int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binary_search(int* arr,int size, int target){
    int start = 0;
    int end = size - 1;

    while (start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == target){
            return mid;
        }

        if(target > arr[mid]){
            start = mid + 1;
        }

        if(target < arr[mid]){
            end = mid - 1;
        }
    }

    return -1;
}