//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int countFractions(int N, int numerator[], int denominator[]) {
    map<pair<int,int>,int> frac;
    
    int count = 0;
    
    for (int i = 0; i < N; ++i) {
        int num = numerator[i];
        int den = denominator[i];
        int g = gcd(num, den);
        num = num/g, den = den/g;
        pair<int,int> p = make_pair(den-num, den);
        
        if(frac[p]!=0) count+=frac[p];
        frac[{num, den}]++;
}
return count; 
    
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends