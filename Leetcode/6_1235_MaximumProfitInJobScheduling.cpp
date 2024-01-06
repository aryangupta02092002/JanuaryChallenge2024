class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int sz = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0; i<sz; i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        
        for(auto &j : jobs){
            int current = prev(dp.upper_bound(j[1]))->second + j[2];
            if(current > dp.rbegin()->second){
                dp[j[0]] = current;
            }
        }
        return dp.rbegin()->second;
    }
};
