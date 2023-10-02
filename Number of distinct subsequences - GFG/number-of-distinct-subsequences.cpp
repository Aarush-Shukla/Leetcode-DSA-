//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	        int ans = 1;
    int m = 1e9 + 7;
    int mp[26] = {0};
    for (char i : s)
    {
        int seq = mp[i - 'a']; // repeating sub-sequence
        mp[i - 'a'] = ans;
        ans = (1LL * ans * 2 - seq + m) % m;
    }
    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends