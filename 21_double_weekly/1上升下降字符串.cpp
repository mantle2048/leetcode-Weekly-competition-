// ˼·��cnt[26]ͳ����ĸ���ֵ�Ƶ�ʣ�Ȼ���ǰ�Ӻ����
int cnt[26] = {0};
class Solution {
public:
    string sortString(string s) {
        int len = s.length();
        for(int i = 0; i < len; i++){
            cnt[s[i]-'a']++;
        }
        int cur = 0; string ans = "";
        while(cur < len){
            for(int i = 0; i < 26; i++){
                if(cnt[i] != 0){
                    ans += 'a' + i;
                    cnt[i]--;
                    cur++;
                }
            }
            for(int i = 25; i >= 0; i--){
                if(cnt[i] != 0){
                    ans += 'a' + i;
                    cnt[i]--;
                    cur++;
                }
            }

        }
        return ans;
    }
};