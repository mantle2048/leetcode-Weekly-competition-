#include<iostream>
#include<string>
#include<vector>
using namespace std;
//name:��ֱ��ӡ����
// HOW ARE YOU
//    ---->
//    HAY
//    ORO
//    WEU
// ˼·:���ں��治�����пո����ǿ��ԴӺ���ǰ�������ʣ��Ȱ�YOU�������һ�еڶ��к͵����е�ĩβ��������֮���ٸ��ݸõ��ʳ���->maxLen��ʣ�µĿո�
// tips:trim������������string��ǰ��ո� s.erase(0,s.find_first_not_of(" ")) s.erase(0,s.find_last_not_of(" "))
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