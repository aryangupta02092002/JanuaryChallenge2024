class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return 0;
        }
        
        vector<int> freq1(26, 0), freq2(26, 0), chr1(26, 0), chr2(26,  0);
        for(auto i : word1){
            freq1[i-'a']++;
            chr1[i-'a'] = 1;
        }
        
        for(auto i : word2){
            freq2[i-'a']++;
            chr2[i-'a'] = 1;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2 && chr1 == chr2;
    }
};
