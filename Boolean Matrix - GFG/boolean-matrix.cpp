//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
              //find the number of rows
        int a=matrix.size();
        // find the elements in one row
        int b=matrix[0].size();
        // flag_row to identify 1 in the row
        vector<int> row_flag(a,0);
        //flag column to set 1 in the column
        vector<int> column_flag(b,0);
        
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(matrix[i][j]==1){
                    row_flag[i]=1;
                    column_flag[j]=1;
                }
            }
        }
        
        for(int i=0;i<a;i++){
            if(row_flag[i]==1){
                for(int j=0;j<b;j++){
                    matrix[i][j]=1;
                }
            }
        }
        
        for(int j=0;j<b;j++){
            if(column_flag[j]==1){
                for(int i=0;i<a;i++){
                    matrix[i][j]=1;
                }
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
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends