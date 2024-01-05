//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int helper(long long int n, vector<long long int> &dp){
	    if(n==1){
	        return 2;
	    }
	    if(n==2){
	        return 3;
	    }
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    return dp[n] = (helper(n-1, dp) + helper(n-2, dp)) % 1000000007;
	}
	int TotalWays(int N)
	{
	    // Code here
	    vector<long long int> dp(N+1, -1);
	    long long int tmp = helper(N, dp);
	    return ((tmp * tmp) % 1000000007);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
