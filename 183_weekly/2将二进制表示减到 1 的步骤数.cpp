class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        if(n == 1) return 0;
        int k = n - 1;
        int cnt = 0;
        while(k > 0){
            if(s[k] == '0') cnt++, k--;
            else{
                while(k >= 0 && s[k] == '1' ) cnt++, k--;
                cnt++;
                if(k >= 0) s[k] = '1';
            }
        }
        return cnt;
    }
};