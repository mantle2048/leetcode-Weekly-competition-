// ˼·�������ͷ���ȫa ż���ͷ���n - 1�� a ��һ�� b
class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(n & 1){ //����
            for(int i = 0; i < n; i++) ans += 'a';
            return ans;
        }
        else{//ż��
            for(int i = 0; i < n - 1; i++) ans += 'a';
            ans +='b';
            return ans;
        }
    }
};