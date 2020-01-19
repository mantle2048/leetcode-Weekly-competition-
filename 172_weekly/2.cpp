#include<iostream>
#include<string>
#include<vector>
using namespace std;
//name:竖直打印单词
// HOW ARE YOU
//    ---->
//    HAY
//    ORO
//    WEU
// 思路:由于后面不允许有空格，我们可以从后向前遍历单词，先把YOU分配给第一行第二行和第三行的末尾，分配完之后再根据该单词长度->maxLen补剩下的空格
// tips:trim可以用来消除string的前后空格 s.erase(0,s.find_first_not_of(" ")) s.erase(0,s.find_last_not_of(" "))
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> tmp; tmp.clear();
        string ret = "";
        int maxLen = 0;
        for(int i = 0; i <= s.length(); i++){
            if(i == s.length() || s[i] == ' '){
                if(maxLen < ret.length()) maxLen = ret.length();
                tmp.push_back(ret);
                ret.clear();
            }
            else{
                ret += s[i];
            }
        }
        vector<string> ans; ans.clear();
        for(int i = 0; i < maxLen; i++) ans.push_back("");
        int n = tmp.size();
        for(int i = n - 1; i >= 0; i--){
            int l = tmp[i].length();
            for(int j = 0; j < l; j++)
                ans[j] = tmp[i][j] + ans[j];
            for(int j = l; j < maxLen; j++)
                if(ans[j].length() > 0) ans[j] = " " + ans[j];
        }
        return ans;
    }

};
void trim(string &s)
{
    if( !s.empty() )
    { 
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
}
int main(){
    string s = "  123456  ";
    int t = s.find_first_not_of(" ");
    cout << t <<endl;
    return 0; 
}