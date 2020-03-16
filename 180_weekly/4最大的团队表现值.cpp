// ˼·���Ȱ���Ч��ֵ����Ȼ��ά��һ����С���ΪK��С���ѺͶ��е��ٶȺ�Sum��ÿ��ȡһ���µ�ֵ����Ч��һ����֮ǰ��������Ч����͵ģ���˿��Ե����˻����Ҳ�
// Ȼ�������ȡ��ֵ�������û������ѣ������˾��ߵ���С��Q.top()Ȼ����� (Sum-Q.top() + Speed[new]) * efficiency[new] ȡ���ֵ
// tips: ��άvector sort���� 
// {{1,2,3},{1,2,4},{1,2,5},{1,2,6},{1,2,7},{1,2,8}} �ᰴ��ÿһ�еĵ�һ��ֵ���򣬵�һ��ֵ��ͬ�ٱȽϵڶ���ֵ����vector<pair<>>�ĵ�����һ����
// vector �Ӵ�С���� sort(tmp.begin(), tmp.end(), greater<vector<int>>()) || sort(tmp.rbegin(),tmp.rend())
// �˷����� pow��x,y) x^y
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