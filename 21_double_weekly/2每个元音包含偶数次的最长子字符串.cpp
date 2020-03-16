// a e i o u ÿ�ֳ��ֵĴ���Ϊ������ż����������ĸһ����32��״̬��������뵽״̬ѹ��
// �����ַ���
// ÿ��һ��λ�þͼ�¼�µ�ǰ�ַ���λ��p��Ԫ����ĸ���ֵ���ż(����1,0,1,0,1)
// �����������λ��q��������ͬ����ż״̬(1,0,1,0,1)������q - p ����һ����Ԫ����ĸһ����������ż����
// 0 ------ p -------- q
// �е����Ƽ�¼����ǰ׺��Ȼ���������һ��

// tips����Ҫ�����޸���ĸ�����ֵ����޸�״̬ʱ��Ҫ�ǵ����뵽״̬ѹ������
// tips: �ַ������ʹ��ǰ׺��
class Solution {
public:
    int c2i(char c){
        if(c == 'a') return 0;
        if(c == 'e') return 1;
        if(c == 'i') return 2;
        if(c == 'o') return 3;
        if(c == 'u') return 4;
        return -1;
    }
    int findTheLongestSubstring(string s) {
        int State[32]; // State��¼״̬��һ�γ��ֵ�λ�� cnt��¼ÿ��Ԫ����ĸ���ֵĴ���
        int n = s.length(), ans = 0;
        int cnt[5] = {0};
        for(int i = 0; i < 32; i++) State[i] = n;
        State[0] = -1; // ��ʼ���ܹؼ���������ĸ������ż����(0,0,0,0,0)��״̬��ʼΪ-1
        for(int i = 0; i < n; i++){
            if(c2i(s[i]) != -1) cnt[c2i(s[i])]++;
            int cur = 0;
            for(int k = 0; k < 5; k++){
                cur += (1<<k) * (cnt[k] & 1);
            }
            if(State[cur] == n) State[cur] = i;
            else
                ans = max(ans, i - State[cur]);
        }
        return ans;
    }
};