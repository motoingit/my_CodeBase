// Question : Remove Duplicate elements in the string
#include <iostream>
#include <string>
using namespace std;

void removeDuplicates(string &str, bool *arr, int idx){
    if(idx == str.length()){
        return;
    }

    int tempIdx = str[idx] - 'a';
    if(arr[tempIdx] == false){
        arr[tempIdx] = true;
        removeDuplicates(str, arr, idx+1);
    }else{
        str.erase(idx, 1);
        removeDuplicates(str, arr, idx);
    }
}

int main(){
    bool flagArr[26] = {false};
    string str = "phillipins";

    cout << str << endl;
    removeDuplicates(str, flagArr, 0);
    cout << str;
return 0;}
