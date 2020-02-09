// name: ��Ծ��Ϸ IV
// ����bfs����Сֵ
// ������Ծ��ʽ dp[i] -> dp[i - 1] | dp[i + 1] | dp[j] (dp[j] == dp[i])
// ��idx = 0��ʼ��Ծ��ÿһ������ͨ���е�������λ�ã���������1 <= arr.length <= 5 * 10^4������ĳ��Ⱥܳ�
// ֱ��bfs��ֱ�ӱ�T�����Ҫ�Ż�, ��Ծ�ķ�Ծ��������������д����������Ԫ�أ�����Ҫһ��һ���ж��Ƿ��Ѿ���������ǳ���ʱ
// ��ô������һ������flag�������ǰidx�Ƿ�Ծ�����ľ�ֱ��flag[idx] = 1 ����ô��idx�����Ͳ����ٿ��Ƿ�Ծ�����ˣ���Ϊ������arr[idx]��ȵ�Ԫ��һ������֮ǰ����idx��ȵ�ֵ��Ծ����
// tips: bfs �� dp��ôѡ�� bfs�ʺ��ڲ�ȷ������˳��ʱ������Сֵ��������һ�Σ� ���� idx ������Ӱ������Ԫ�� ͬʱҲ����Ӱ�� idx - 1����޷�ʹ��dp
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
            if(cur - 1 >= 0 && dp[cur - 1] == -1){//bfsҪ�жϽڵ��Ƿ��Ѿ����ʹ��ˣ����ֵ�Ѿ����¹��ˣ��϶��ͷ����� 
                dp[cur - 1]  = dp[cur] + 1;
                flag[cur - 1] = 0;
                que.push(cur - 1);
            } 
            if(cur + 1 < n && dp[cur + 1] == -1){
                dp[cur + 1] = dp[cur] + 1;
                flag[cur + 1] = 0;
                que.push(cur + 1);
            }
            if(flag[cur] == 0){ //key: ��������
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