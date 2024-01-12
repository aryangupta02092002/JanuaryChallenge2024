//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        
        while(k){
            int tmp = q.front();
            q.pop();
            s.push(tmp);
            k--;
        }
        
        queue<int> res;
        
        while(!s.empty()){
            int tmp = s.top();  
            s.pop();
            res.push(tmp);
        }
        
        while(q.size() != 0){
            int tmp = q.front();    
            q.pop();
            res.push(tmp);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
