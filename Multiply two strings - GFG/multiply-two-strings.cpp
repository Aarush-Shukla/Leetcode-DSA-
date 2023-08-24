//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
       // Steps wise solutions
    // Just Follow 
  
    string f(string &s1, int num) {
        
        // multiple given numbers with, a given string
        int carry = 0; 
        string res; 
        for(int i = 0; i < s1.size(); i++) {
            int ans = (s1[i]-'0') * num + carry; 
            res.push_back(ans % 10 + '0'); 
            carry = ans / 10; 
        }
        
        if(carry > 0) 
            res.push_back(carry + '0'); 
        
        //You can avoid multiple reverses, 
        //But when I try to solve this problem 
        //I am happy to reverse the string
        reverse(res.begin(), res.end()); 
        return res; 
    }
    
    string addToNum(string s1, string s2) {
        string res; 
       
        //Start from the back side
        int i = s1.size()-1; 
        int j = s2.size()-1;
        
        int carry = 0; 
        while(i >= 0 || j >= 0) {
            int ans = 0; 
            
            //If both indexes ok, then add values
            if(i >= 0 && j >= 0) {
                ans = (s1[i]-'0') + (s2[j]-'0') + carry; 
                i--, j--; 
            }
            
            //If one of them is ok, take and add it
            else if(i >= 0) {
                ans = (s1[i]-'0') + carry; 
                i--; 
            } else if(j >= 0) {
                ans = (s2[j]-'0') + carry; 
                j--; 
            }
    
            // add rem and store carry, +'0' because, 
            // we need char 0, not integer 0
            res.push_back(ans%10 + '0'); 
            carry = ans / 10; 
        }
        
        // in last, if we have carry > 0
        // then add it
        if(carry > 0)  
            res.push_back(carry + '0'); 
        return res; 
    }
    
    string removeLeadingZero(string &str, bool &isNeg) {
        string temp; 
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '-') {
                isNeg = !isNeg; 
            } 
            //Consider, only which string has first
            // starting non-zero value
            else if(str[i] != '0') {
                temp = str.substr(i); 
                break; 
            }
        }
        return temp; 
    }
    
    string multiplyStrings(string s1, string s2) {
      
        //This variable used for the answer should be Neg or not 
        bool isNeg = false; 
        
        //We remove leading zero, separately
        string str1, str2; 
        str1 = removeLeadingZero(s1, isNeg); 
        str2 = removeLeadingZero(s2, isNeg); 
     
        //We reverse both the string because we normally
        // multiply number from right to left, 
        // and i comfortable with 0-based index, 
        // you can multiply n-1 index to 0 index also
        reverse(str1.begin(), str1.end()); 
        reverse(str2.begin(),str2.end()); 
        
        // Initially, we have empty result string
        // who contains only 0's
        string res; 
        for(int i = 0; i < str1.size(); i++) 
            res.push_back('0'); 
        
        // now iterate on second string
        for(int i = 0; i < str2.size(); i++) {
            
            // multiply this number, to whole string one, 
            // and return 
            string temp = f(str1, str2[i]-'0');
            
            // we equalize both the string with fill-up 0's
            for(int j = 0; j < i; j++) 
                temp.push_back('0'); 
          
            // add both the string
            res = addToNum(temp, res); 
            
            //Now reverse them, because we need a reverse answer
            // If you do not understand, Bro take a pen & paper
            // and lag jao dry run karne me
            reverse(res.begin(), res.end()); 
           
        }
        
        // In last, check result should contain neg sign or not
        if(isNeg) 
            res = '-' + res; 
        return res;
    }

    /* TC-O(n+m + n+m + n + n*(n+m) - overall n*m) 
       SC-O(n+m+n - overall n) 
    */

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends