/*

vector <vecottr<bo;l>>   backTrack(int row, int arr){
    if(row == n){
        return true
    }

    for(0 -> n-1){
        if(issafec(i,row)){
            if(true== backTrack(row+1, arr)){
                arr[row][i] = "Q"
            }
            arr{row}{i} = "."
        }
    }

    return false
}

nQueen(){
    int list;
    list.add(backTrack(0, arr));
}

main(){
    array 4x4 with all false;
    nQuee(); //! this will give no of combination
}

*/
class Solution {
public:

    bool isSafe(vector<string> &singleSolution,int row, int col, int n)
    {
        for(int i=row;i>=0;i--)
        {
            if(singleSolution[i][col]=='Q') return false;
        }

        int i=row;
        int j=col;

        while(i>=0 && j>=0)
        {
            if(singleSolution[i][j]=='Q') return false;

            i--;
            j--;
        }

        
        i=row;
        j=col;

        while(i>=0 && j<n)
        {
             if(singleSolution[i][j]=='Q') return false;

            i--;
            j++;
        }

        return true;
    }

    void getSolutions(int n,vector<vector<string>> &solutions, vector<string> &singleSolution,int i)
    {
        if(i==n)
        {
            solutions.push_back(singleSolution);

            return ;
        }
        

        for(int j=0;j<n;j++)
        {
            if(isSafe(singleSolution,i,j,n))
            {
                singleSolution[i][j]='Q';
                getSolutions(n,solutions,singleSolution,i+1);
                singleSolution[i][j]='.';
            }
        }



        

        return ;
    }


    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> solutions;
        vector<string> singleSolution(n,string(n,'.'));

        getSolutions(n,solutions,singleSolution,0);

        return solutions;
        
    }
};
