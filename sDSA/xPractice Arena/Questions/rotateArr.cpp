// Question : 
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void rotateArrStep(vector <int> &arr,int  k){
    if (arr.empty()) return;
    k = k%arr.size();
    if (k == 0) return;

    // Rotate one by one to show steps
    for (int r = 0; r < k; r++) {
        int first = arr[0];
        for (int i = 0; i < arr.size() - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[arr.size() - 1] = first;

        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }

}

void rotateArrOnce(vector<int> &arr, int nR){
    if(arr.size() <= 1){
        return;
    }
    

    nR = nR%arr.size();
    if(nR == 0){
        return;
    }

    for(int i = arr.size() - nR, j = arr.size()-1; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
    for(int i = 0, j = arr.size() - nR - 1; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }

    for(int i = 0, j = arr.size() -1; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
    
    for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;


}

int main(){
    int k; cin >> k;
    vector<int> arr = {1,2,3,4};
    rotateArrOnce(arr, k);
return 0;}
