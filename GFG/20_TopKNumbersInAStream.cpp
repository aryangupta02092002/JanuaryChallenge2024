//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
struct myCmp{
        bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
            if(p1.second != p2.second)
                return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        
        set<pair<int,int>,myCmp> s;
        
        vector<vector<int>> res(N);
        unordered_map<int,int> um;
        
        for(int i = 0; i < N; i++){
            //int temp2;
            if(um.find(arr[i]) == um.end()){
                um.insert({arr[i],1});
                s.insert({arr[i],1});
            }
            else{
                um[arr[i]]++;
                s.erase({arr[i],um[arr[i]] - 1});
                s.insert({arr[i],um[arr[i]]});
            }
            auto it = s.begin();
            for(int j = 0; it != s.end() && j < K; j++,it++){
                
                res[i].push_back(it->first);
            }
            
            
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends
