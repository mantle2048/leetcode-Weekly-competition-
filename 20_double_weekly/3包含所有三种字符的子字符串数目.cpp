// name: �������������ַ������ַ�����Ŀ
// ˼·����ָ��a b c ÿ��ָ��� -1 ��ʼÿ���ƶ���ǰ���һ��ָ�룬�����ƶ�a����a����һ��'a'�ƶ�����һ��'a',ÿ���ƶ�������ans��ÿ�θ���abc����ָ�����һ��ָ�뵽�ִ�ĩβ������
// tips:���������ִ�������ĸ��Ҫ���� ˫ָ�� ������ָ��
// tips: �ִ�ֻ����������ĸ���Կ��� ������ & ���߻���֮���˼·
#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
class Solution {
public: //��ָ������
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        int n = s.length();
        int ans = 0;
        while(max(a, b, c) < n){
            if(a == min(a, b, c)){
                a++;
                while(s[a] != 'a' && a < n) a++;
            }
            else if(b == min(a, b, c)){
                b++;
                while(s[b] != 'b' && b < n) b++;
            }
            else if(c == min(a, b, c)){
                c++;
                while(s[c] != 'c'&& c < n) c++;
            }
            if(max(a, b, c) >= n) break;
            if(a != -1 && b != -1 && c != -1) ans += n - max(a, b, c);
        }
        return ans;
    }
};

// ˫ָ�븴�Ӷ�Ҫ��һЩ
// ˼·: tri��¼abc�����˼����� cnt��¼abc�ڵ�ǰ[i, j)���и��Գ��ֵĴ���
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), tri = 0, ans = 0;
        map<char,int> cnt; cnt.clear(); //map��ʼ��ֵΪ0
        for(int i = 0, j = 0; i < n; i++){ //Ҫע����[i, j) ����ҿ�
            if(i > 0){
                if(cnt[s[i- 1]] == 1)  tri--;
                cnt[s[i - 1]]--;
            }
            while(tri < 3 && j < n){
                cnt[s[j]]++;
                if(cnt[s[j]] == 1) tri++;
                j++;
            }
            if(tri == 3) ans += n - j + 1;
        }
        return ans;
    }
};