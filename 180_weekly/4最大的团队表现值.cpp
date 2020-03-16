// 思路：先按照效率值排序，然后维护一个大小最大为K的小顶堆和堆中的速度和Sum，每次取一个新的值，其效率一定是之前所有人中效率最低的，因此可以当作乘积的右侧
// 然后这个新取的值，如果堆没满就入堆，堆满了就踢掉最小的Q.top()然后计算 (Sum-Q.top() + Speed[new]) * efficiency[new] 取最大值
// tips: 二维vector sort排序 
// {{1,2,3},{1,2,4},{1,2,5},{1,2,6},{1,2,7},{1,2,8}} 会按照每一行的第一个值排序，第一个值相同再比较第二个值，和vector<pair<>>的道理是一样的
// vector 从大到小排序 sort(tmp.begin(), tmp.end(), greater<vector<int>>()) || sort(tmp.rbegin(),tmp.rend())
// 乘方函数 pow（x,y) x^y
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
typedef long long ll;
const int mod = 1e9 + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int> > buf;
        for(int i = 0; i < n; i++)
            buf.push_back({efficiency[i],speed[i]});
        sort(buf.rbegin(), buf.rend());
        priority_queue<int,vector<int>,greater<int>> Q;
        ll sum = 0;
        ll result = 0;
        for(int i = 0; i < n; i++){
            sum += buf[i][1];
            Q.push(buf[i][1]);
            if(i >= k){
                if(buf[i][1] < Q.top()) continue;
                sum -= Q.top();
                Q.pop();
            }
            result = max(result, sum * buf[i][0]);
        }
        ll ans = result % mod;
        return ans;
    }
};