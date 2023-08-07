//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    
 bool isSafe(int row,int col,int grid[][N],int val){
        //int n = sizeof(grid)/sizeof(grid[0]);
        int n=9;
        for(int i=0;i<n;i++){
            //check row
            if(grid[row][i]==val)
            return false;
            //check col
            if(grid[i][col]==val)
            return false;
            //check 3*3 matrix
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3] == val)
            return false;
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])
    { 
        int n=9;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                //empty cell
                if(grid[row][col] == 0){
                    //try inserting 1-9 values
                    for(int val=1;val<=9;val++){
                        if(isSafe(row,col,grid,val)){
                            grid[row][col] = val;
                            //solve other possibilities(recursion)
                            bool nextPossibleSol = SolveSudoku(grid);
                            if(nextPossibleSol){
                                return true;
                            }else{
                                //backtrack
                                grid[row][col] = 0;
                            }
                            
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
       for(int i=0;i<N;i++){
           for(int j=0;j<N;j++){
               cout<<grid[i][j]<<" ";
           }
       } 
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends