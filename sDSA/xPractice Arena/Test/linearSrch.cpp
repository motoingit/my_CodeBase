// Question : Random No
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int linearSearch(const string& fileName,int key) {
    ifstream fin(fileName);
    if (!fin) {
        cout << "File not found! Returning to main\n";
        return -1;
    }

    int value;
    int lineNo = 1;
    while (fin >> value) { //! throw EOF on end
        if (value == key){
            //fileClose ?
            return lineNo;   // element found
        }
        lineNo++;
    //fileClose ?
    }
return -1;}          // element not found

int main(){

    string fileName = "data.txt";

    int key = 100;
    int idx = linearSearch(fileName, key);

    cout << idx;
return 0;}
