#include<iostream>
#include<string>
using namespace std;

//思路：从后向前读,比较容易求解,遇到  #  就向前读 2 位
class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int n  = s.length();
        for(int i = n - 1; i >= 0; i--){
            int cur = 0;
            if(s[i] == '#'){
                cur += 10*(s[i - 2]-'0') + (s[i - 1] - '0');
                i -= 2;
            }
            else
                cur += s[i] - '0';
            ans = char(cur - 1 + 'a') + ans;
        }
        return ans;
    }
};
int main(){
        Solution tmp;
        string ans = tmp.freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#");
        cout<< ans <<endl;
        return 0;
}