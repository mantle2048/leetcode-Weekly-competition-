// 思路：反向思维 假设每行都能放满两个，然后逐一排除，妙啊~
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> buf = reservedSeats;
        sort(buf.begin(), buf.end(),cmp);
        int ans = 2 * n; //假设每行都能放满两个，然后逐一排除
        int  vis[15];
        for(int i = 0; i < 15; i++) vis[i] = 1;
        for(int i = 0; i < buf.size(); i++){
            vis[buf[i][1]] = 0;
            if(i == buf.size() - 1 || buf[i][0] != buf[i + 1][0]){ //这一行被占用了
                // 处理当前行
                int tmp = 0; //tmp记录当前行与最多能放的家庭数的差值
                int a = vis[2] && vis[3];
                int b1 = vis[4] && vis[5];
                int b2 = vis[6] && vis[7];
                int c = vis[8] && vis[9];
                if(a && c && b1 && b2) tmp += 0; // 当前行能放2个
                else if(a && b1) tmp += 1; // 1个 与预想的1个差了1个
                else if(b2 && c) tmp += 1; // 1个
                else if(b1 && b2) tmp += 1; // 1个
                else tmp += 2; // 当前行能放0个，与预想的2个差了两个
                ans -= tmp;
                for(int i = 0; i < 15; i++) vis[i] = 1;
            }
        }
        return ans;
    }
};
