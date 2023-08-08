//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        unordered_map<string,int> map;


int solve(int i,int j,string S,bool isTrue)
{
  if(i>j){
      return false;
  }
    
    if(i==j)
    {
        if(isTrue)
        return S[i]=='T';
        else
        return S[i]=='F';
    }
   string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
    if(map.find(temp)!=map.end())
    return map[temp];
    int count=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
       
        
        int lt=solve(i,k-1,S,true);
        int lf=solve(i,k-1,S,false);
        int rt=solve(k+1,j,S,true);
        int rf=solve(k+1,j,S,false);
        
        
        if(S[k]=='&')
        {
            if(isTrue==true) //calculate the no of trues
            {
               
               count=count+lt*rt;
            }
            else            //calculate the no of false
            {
                
                count=count+(lt*rf)+(lf*rf)+(lf*rt);
            }
        }
        else if(S[k]=='^')
        {
            if(isTrue==true)
            {
               
                count=count+lt*rf+lf*rt;
            }
            else
            {
                
                count=count+lf*rf+lt*rt;
            }
        }
        else if(S[k]=='|')
        {
             if(isTrue==true)
             {
                 
                 count=count+lt*rt+lt*rf+lf*rt;
             }
             else
             {
              
                 count=count+lf*rf;
             }
        }
        count=count%((int)(1e9+7));
       
    }
   
 
   
    return map[temp]=count%1003;
}
    int countWays(int N, string S){
        // code here
        map.clear();
        return solve(0,N-1,S,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends