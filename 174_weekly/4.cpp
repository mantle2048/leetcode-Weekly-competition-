//name:��Ծ��Ϸ V
//dp�⣬dp[i]��ʾ��I��ʼ���������Է��ʶ����±�
//����ʽΪ dp[i] = �� [i - d, i + d](������ i)��Χ�����ֵȻ�� + 1
//״̬ת������Ϊ �� i ���������������ͬʱ arr[j] < arr[i] ������Դ� j->i Ҳ���ǵ�ǰ״̬dp[i]������dp[j]������
//tips:��θ��������ֵ�������±꣺��һ������idx[]������е��±꣬Ȼ�����ñȽϺ���cmp return val[a] < val[b]������ֵ��ֵ���ж��±�����idx��������

#define max(a, b) ((a > b)? a : b)
const int MAXN = 1000 + 50;
int dp[MAXN];
vector<int> val;
bool cmp(const int& a, const int& b){ return val[a] < val[b]; }
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> idx(n, 0); val = arr;
        for(int i = 0; i < n; i++)
            idx[i] = i;
        sort(idx.begin(), idx.end(), cmp);
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int _i = 0; _i < n; _i++){
            int i = idx[_i];
            dp[i] = 1;
            for(int j = i - 1; j >= 0 && j >= i - d; j--){
                if(arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            for(int j = i + 1; j < n && j <= i + d; j++){
                if(arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};