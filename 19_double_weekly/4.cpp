// name: 跳跃游戏 IV
// 经典bfs求最小值
// 三种跳跃方式 dp[i] -> dp[i - 1] | dp[i + 1] | dp[j] (dp[j] == dp[i])
// 从idx = 0开始跳跃，每一跳都打通所有的能跳的位置，但是由于1 <= arr.length <= 5 * 10^4，数组的长度很长
// 直接bfs会直接爆T，因此要优化, 跳跃的飞跃操作中如果数组中大量出现相等元素，总是要一个一个判断是否已经到达过，非常费时
// 那么就设立一个数组flag，如果当前idx是飞跃过来的就直接flag[idx] = 1 ，那么从idx出发就不用再考虑飞跃操作了，因为其他与arr[idx]相等的元素一定都被之前的与idx相等的值飞跃到了
// tips: bfs 和 dp怎么选择 bfs适合于不确定遍历顺序时，求最小值，比如这一次， 对于 idx 它可以影响后面的元素 同时也可以影响 idx - 1因此无法使用dp
const int MAXN = 5e4 + 50;
int dp[MAXN], flag[MAXN];
map<int, vector<int> > edge;
queue<int> que;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            dp[i] = -1; flag[i] = 0;
        }
        edge.clear();
        for(int i = 0; i < n; i++){
            edge[arr[i]].push_back(i);
        }
        while(!que.empty()) que.pop();
        dp[0] = 0; flag[0] = 0;
        que.push(0);
        while(!que.empty()){
            int cur = que.front(); que.pop();
            if(cur - 1 >= 0 && dp[cur - 1] == -1){//bfs要判断节点是否已经访问过了，如果值已经更新过了，肯定就访问了 
                dp[cur - 1]  = dp[cur] + 1;
                flag[cur - 1] = 0;
                que.push(cur - 1);
            } 
            if(cur + 1 < n && dp[cur + 1] == -1){
                dp[cur + 1] = dp[cur] + 1;
                flag[cur + 1] = 0;
                que.push(cur + 1);
            }
            if(flag[cur] == 0){ //key: 防爆精髓
                for(auto i : edge[arr[cur]]){
                    if(dp[i] == -1){
                        dp[i] = dp[cur] + 1;
                        flag[i] = 1;
                        que.push(i);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};