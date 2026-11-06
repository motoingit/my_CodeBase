// Question : Random No
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int fucn(int min, int max){
    std::random_device rd;
    int randomNum = rd();
    randomNum = randomNum % (max+1) + min;
    return (randomNum >= 0) ? (randomNum) : -randomNum ;
}

int main(){
    int n = 100;
    int max = 999;
    int min = 10;

    ofstream fout("data.txt");   // open file in write mode
    if (!fout) {
        cout << "File not opened !, Termination Program\n";
        return 1;
    }

    
    for(int i = 0; i < n; i++) {
        fout << fucn(min, max) << endl;
    }

    fout.close();  // always close file
return 0;}
