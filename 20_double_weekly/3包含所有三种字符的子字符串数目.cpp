// name: 包含所有三种字符的子字符串数目
// 思路：三指针a b c 每个指针从 -1 开始每次移动最前面的一个指针，比如移动a，把a从上一个'a'移动到下一个'a',每次移动都更新ans，每次更新abc三个指针最后一个指针到字串末尾的数量
// tips:遇到这种字串三个字母的要考虑 双指针 或者三指针
// tips: 字串只含有两种字母可以考虑 两者求 & 或者互逆之类的思路
#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
class Solution {
public: //三指针做法
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

// 双指针复杂度要高一些
// 思路: tri记录abc出现了几个了 cnt记录abc在当前[i, j)序列各自出现的次数
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), tri = 0, ans = 0;
        map<char,int> cnt; cnt.clear(); //map初始键值为0
        for(int i = 0, j = 0; i < n; i++){ //要注意是[i, j) 左闭右开
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