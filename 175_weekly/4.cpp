int dp[10][1 << 8];
// dp[i][xxxxxxxx]表示前i行中第i行排布为"xxxxxxxx"的最多可以坐的人数
// 状态压缩dp
class Solution {
public:

    int lowbit(int x){ //lowbit(x)是x的二进制表达式中最低位的1所对应的值。
        return x & -x;
    }
    int bcount(int x){ //bcount(x)统计数字x的二进制中有多少位为1
        int ret = 0;
        while(x > 0){
            x -= lowbit(x);
            ret++;
        }
        return ret;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(); int m = seats[0].size();
        
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;

        int lim = 1 << m; //一行一共要记录m位
        for(int i = 1; i <= n; i++){ //遍历每一行
            for(int cur = 0; cur < lim; cur++){ // 0 -> 255 对应着 00000000 -> 11111111 遍历出当前行座位的排布 
                for(int pre = 0; pre < lim; pre++){//0 -> 255 对应着 00000000 -> 11111111 遍历出上一行座位的排布 
                    if(dp[i - 1][pre] == -1) continue; //如果上一行的没有更新 pre排布方式的状态 直接跳过
                    bool flag = true; //用这个标志记录是否需要更新当前状态dp[i][cur]
                    for(int j = 0; j < m; j++){ //遍历 cur 和 pre 的每一位查看是否满足题目要求
                        if(((cur>>j) & 1) == 0) continue; //cur的j位如果不能坐就继续下一位
                        if(seats[i - 1][j] == '#') flag = false; //如果第i行实际的seats中第j位不能坐，那么
                        if(j >= 1 && ((cur>>(j - 1))&1)) flag ==false; //j位置的左边能不能行
                        if(j + 1 < m && ((cur>>(j + 1))&1)) flag = false; //j位置的右边
                        if(j >= 1 && ((pre>>(j - 1))&1)) flag = false; //左前方
                        if(j + 1 < m && ((pre>>(j + 1))&1)) flag = false; //左后方
                    }
                    if(flag == false) continue;
                    dp[i][cur] = max(dp[i][cur], dp[i - 1][pre] + bcount(cur));
                }
            }
        }
        int ans = 0;
        for(int s = 0; s < lim; s++) ans = max(ans, dp[n][s]);
        return ans;
    }
};


        // for(int i = 0; i < n; i++){
        //     int cur = 0;
        //     for(int j = 0; j < m; j++){
        //         cur = cur * 2 + seats[i];
        //     }
        //     buf.push_back(cur);
        // }
        // for(int i = 1; i <= n; i++){
        //     int cur = buf[i]; int pre = buf[i - 1];
        //     bool flag = false;
        //     for(int j = 0; j < m; j++){
        //         if(((cur>>j) & 1) == 0) continue; //cur的j位如果不能坐就继续下一位
        //         if(seats[i - 1][j] == '#') flag = false; //如果第i行实际的seats中第j位不能坐，那么
        //         if(j >= 1 && ((cur>>(j - 1))&1)) flag ==false; //j位置的左边能不能行
        //         if(j + 1 < m && ((cur>>(j + 1))&1)) flag = false; //j位置的右边
        //         if(j >= 1 && ((pre>>(j - 1))&1)) flag = false; //左前方
        //         if(j + 1 < m && ((pre>>(j + 1))&1)) flag = false; //左后方
        //     }
        // }