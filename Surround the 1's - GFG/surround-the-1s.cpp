//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
         int ans = 0,cnt = 0;
        int n = matrix.size(), m = matrix[0].size();
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(matrix[row][col] == 1){
                    for(int delrow = -1; delrow <= 1; delrow++){
                        for(int delcol = -1; delcol <= 1; delcol++){
                            int nrow = row + delrow;
                            int ncol = col + delcol;
                            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and matrix[nrow][ncol]==0){
                                cnt++;
                            }
                        }
                    }
                    if(cnt > 0 and cnt%2==0){
                        ans++;
                    }
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends