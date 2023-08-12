//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    
   //It may happen that 2 strings are Anagram but not scrambled.
    //Anagrams are produced of random shuffle, where as scrambling involves a procedural shuffle, in this case swapping adjacent sub strings parititions..
  unordered_map<string, bool> map;
    bool solve(string S1, string S2){
        string key=S1+" "+S2;
        if(S1.compare(S2)==0) return map[key]= true;
        if(S1.size()<=1 || S2.size()<=1) return false;
        if(map.find(key)!=map.end()) return map[key];
        bool flag=false;
        for(int i=1; i<S1.size(); i++){
            bool cond1= solve(S1.substr(0, i), S2.substr(S2.length()-i)) && solve(S1.substr(i), S2.substr(0, S2.size()-i));
            bool cond2= solve(S1.substr(0, i), S2.substr(0, i)) && solve(S1.substr(i), S2.substr(i));
            if(cond1 or cond2){
                flag=true;
                break;
            }
        }
        return map[key]= flag;
    }
    
    bool isScramble(string S1, string S2){
        vector<int> cnt(26, 0);
        map=unordered_map<string, bool>(false);
        for(int i=0; i<S1.size(); i++){
            cnt[S1[i]-'a']++;
            cnt[S2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]!=0) return false;
        }
        return solve(S1, S2);
    }
      

};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends