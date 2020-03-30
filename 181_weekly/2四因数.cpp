class Solution {
public:
    int cal_num(int x){
        set<int> buf;
        int ret = 0;
        int n = sqrt(x) + 1;
        for(int i = 1; i < n; i++){
            if(x % i == 0){
                buf.insert(i);
                buf.insert(x / i);
                ret += i + x / i;
            }
        }
        if(buf.size() == 4) return ret;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums) ans += cal_num(i);
        return ans;
    }
};