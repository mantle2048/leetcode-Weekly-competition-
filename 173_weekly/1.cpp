//name: ɾ������������
// ���������У�ע�ⲻ���Ӵ�����һ��Ҫ���������� �м�����м���� �����Һþá����������
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s == "") return 0;
        int n = s.length();
        bool flag = true;
        int i = 0, j = n - 1;
        for(int i = 0; i < n; i++)
            if(s[i] != s[n - 1 - i]) flag = false; // ����ʹ��˫ָ�룬ֱ��һ����� i ��ͷ����
        return flag ? 1 : 2;
    }
};