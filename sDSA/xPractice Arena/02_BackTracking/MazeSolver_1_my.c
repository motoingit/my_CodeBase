//only down and right
// start any, stop n-1 m-1

#include <stdio.h>

int printPos(int n, int m, int i, int j){
    
    if(i == n || j == m){ //todo: Base Condition
        return 0;
    }
    
    if(i == n-1 && j == m-1){ //* Fond it
        // print("(%d, %d) - > ",i , j);
        return 1;
    }

    int down = printPos(n,m,i+1,j);
    int right = printPos(n,m,i,j+1);

    return down + right;
}
/*
from (i,j) to (n-1,m-1)
 */
int main() {
    int n = 10, m = 10;
    int i = 8, j = 8;
    int nPath = printPos(n,m,i,j);
    printf("%d",nPath);
return 0;}
