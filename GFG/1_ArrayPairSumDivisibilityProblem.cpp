//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n%2 != 0)
            return 0;
            
        unordered_map<int, int> mp;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            int r = (nums[i] % k);

            if(mp.find(abs(k-r)) != mp.end()){
                cnt++;
                mp[abs(k-r)]--;
                
                if(mp[abs(k-r)] == 0)
                    mp.erase(abs(k-r));
            }
            else{
                if(r == 0)
                    mp[k]++;
                else 
                    mp[r]++;
            }
        }
        if(cnt == n/2)
            return 1;
       
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
