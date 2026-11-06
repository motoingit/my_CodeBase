// Question :  
/*
    Tile size : 1 x m
    Floor size : n x m
*/
#include <iostream>
using namespace std;

int possible(int n, int m){
    if(n == m){
        return 2;
    }else if( n < m){
        return 1;
    }

    //verticle way
    int way1 = possible(n-m, m);
    int way2 = possible(n-1,m);

    return way1 + way2;
}

int main(){
    int n = 10, m = 3;
    int comb = possible(n,m);
    cout << comb;
return 0;}
