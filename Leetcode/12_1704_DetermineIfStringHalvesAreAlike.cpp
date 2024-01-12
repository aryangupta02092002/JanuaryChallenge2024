class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int left = 0;
        int right = s.length()-1;
        
        int cnt_A = 0;
        int cnt_B = 0;
        
        while(left < right){
            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u' || s[left]=='A' || s[left]=='E' || s[left]=='I' || s[left]=='O' || s[left]=='U'){
                cnt_A++;
            }
            
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || s[right]=='o' || s[right]=='u' || s[right]=='A' || s[right]=='E' || s[right]=='I' || s[right]=='O' || s[right]=='U'){
                cnt_B++;
            }
            
            left++;
            right--;
        }
        
        return cnt_A == cnt_B;
    }
};
