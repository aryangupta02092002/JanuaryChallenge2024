class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        for(int i=0; i<matches.size(); i++){
            if(!m.count(matches[i][0])){
                m[matches[i][0]] = 0;
            }
            m[matches[i][1]]++;
        }
        
        vector<int> zero, one;
        for(auto [key, val] : m){
            if(val == 0){
                zero.push_back(key);
            }
            if(val == 1){
                one.push_back(key);
            }
        }
        return {zero, one};
    }
};
