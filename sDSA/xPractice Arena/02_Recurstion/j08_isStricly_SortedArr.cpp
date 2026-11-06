// Question : check if the array is sorted in increasing order
#include <iostream>
using namespace std;

bool helperFuction(int arr[], int curr, int size){
    // base case: reached end
    if (curr == size - 1) {
        return true;
    }

    // check current pair
    if (arr[curr] >= arr[curr + 1]) {
        return false;
    }

    // recurse for next index
    return helperFuction(arr, curr + 1, size);
}

bool checkStrictSort(int arr[], int size){

    //todo:      what if arr is empty then ?
    //! WRONG >>>>>>>> int size = sizeof(arr)/sizeof(arr[0]);

    if(size == 1){
        return true;
    }

    return helperFuction(arr, 0, size); // 0 se init
}

int main(){
    int arr1[] = {1,3,4,6,9};
    // int arr2[] = {1,3,3,6,9};
    // int arr3[] = {1,3,2,6,0};
    // int arr4[] = {9,5,3,2};

    int size = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Status of arr1 : "<< checkStrictSort(arr1, size) << endl; // 1
return 0;}
