// name:ͨ��ͶƱ���Ŷ�����
// ˼·���������� cnt[][]��¼ÿ��(����26������)�����õĵ�x����Ʊ����Ȼ����cmp��������
int cnt[26][30];
int len = 0;
bool cmp(char a, char b){
    for(int i = 0; i < len; i++){
        if(cnt[a-'A'][i] != cnt[b-'A'][i])
            return (cnt[a-'A'][i] > cnt[b-'A'][i]);
    }
    return a < b;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        len = votes[0].size();
        int m = votes.size();
        string ans = votes[0];
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < len; j++){
            for(int i = 0; i < m; i++){
                int cur = votes[i][j] - 'A';
                cnt[cur][j]++;
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};