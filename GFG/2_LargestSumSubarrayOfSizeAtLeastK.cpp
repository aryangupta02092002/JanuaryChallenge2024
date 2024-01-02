//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int maxi=-1e9, frontSum=0, currSum=0, j=0;
        for(int i=0; i<k; i++)
        {
            currSum += a[i];
        }
        
        maxi = currSum;
        
        for(int i=k; i<n; i++){
            currSum += a[i];
            frontSum += a[j];
            j++;
            
            if(frontSum < 0)
            {
                currSum = currSum - frontSum;
                frontSum=0;
            }
          
            maxi = max(maxi, currSum);
            
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
