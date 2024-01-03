class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size(), n=bank[0].size();
        int count=0, prev=0, curr=0;

        for(int i=0; i<m; i++){
            curr=0;
            for(int j=0; j<n; j++){
                if(bank[i][j] == '1')
                    curr++;
            }

            count += (curr*prev);
            if(curr>0)
                prev = curr;
        }
        
        return count;
    }
};
