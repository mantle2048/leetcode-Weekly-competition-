// �����ϵ�˼·�������ǰ���ŵĵƵı�ŵĺ�sum�Ƿ���ڵ�ǰʱ��i(1,2,3,4.....i + 1)�ĵȲ����к�
// ���˼·����¼���Ƶ�maxλ�ã���¼����������������Ⱦͼ�¼��ǰʱ�̣�ʵ����̫���ˣ���
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        ll sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int cur = light[i];
            sum += cur;
            if(sum * 2 == (ll)(1 + (i + 1)) * (i + 1)) ans++;
        }
        return ans;
    }
};