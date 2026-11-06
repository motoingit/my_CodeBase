// Question : 
#include <iostream>
using namespace std;

int possible(int n){
    if(n == 1){
        return 1;
    }

    int way1 = possible(n-1);
    int way1 = (n-1) * possible(n-2);
}

int main(){
    int n = 3;
    int pos = possible(n);

    cout << possible(n);
    
return 0;}
