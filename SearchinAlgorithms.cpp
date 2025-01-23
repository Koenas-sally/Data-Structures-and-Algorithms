#include <iostream>
#include <vector>
using namespace std;

//Binary Search
int binarySearch(vector<int>& arr, int search_key){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == search_key){
            return mid;
        }
        else if(arr[mid] < search_key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

//Linear Search
int linearSearch(vector<int>& arr, int search_key){
    for(size_t i = 0; i < arr.size(); ++i){
        if(arr[i] == search_key){
            return i;
        }
    }
    return -1;
}