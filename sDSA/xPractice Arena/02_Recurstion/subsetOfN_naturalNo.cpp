// Question : 
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &subSet){
    cout << "{ ";
    for (int x : subSet) {
        cout << x << " ";
    }
    cout << "}"<< endl;
}

void printSubset(int n, vector<int> subSet){
    if(n == 0){
        printArr(subSet);
        return;
    }

    subSet.push_back(n);
    printSubset(n-1, subSet);

    subSet.pop_back();
    printSubset(n-1, subSet);
}

int main(){
    int n = 3;
    vector <int> subSet;
    printSubset(n, subSet);
return 0;}
