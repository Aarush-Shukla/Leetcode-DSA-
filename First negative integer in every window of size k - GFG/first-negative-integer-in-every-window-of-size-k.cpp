//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


typedef pair<int,int> pi;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
    queue<pi>q;
    vector<long long>ans;
    
    int i;
    for( i=0; i<K-1; i++){
        if(A[i]<0)q.push({A[i],i});
    }
    
    pi p;
    
    int j =0;
    while(i<N){
        if(A[i]<0)q.push({A[i],i});
        
        if(q.empty())ans.push_back(0);
        
        else{
            p = q.front();
            ans.push_back(p.first);
            
            if(p.second<=j)q.pop();
        }
        j++;
        i++;
        
    }
    
    return ans;
 }