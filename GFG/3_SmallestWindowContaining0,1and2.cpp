//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int i=0, j=0, c[3]={}, sz = S.size();
        int ans = INT_MAX;
        while(j<=sz && i<sz){
            if(c[0]==0 ||c[1]==0 || c[2]==0){
                c[S[j]-'0']++;
                j++;
            }
            else{
                ans = min(ans, j-i);
                c[S[i]-'0']--;
                i++;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
