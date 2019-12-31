// 题目名称：统计位数为偶数的数字
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(judge(nums[i]))
                ans++;
        }
        return ans;
    }
//小贴士：程序中尽量减少三目运算符，判定条件尽量能用数本身就用数本身，不要额外加等号或者不等号判定了
//小贴士：求 位数 的奇招，log10 log2 
    int judge(int x){//直接除10，保留，三目运算符会大大拖慢运行速度，因此尽量少使用 4ms Beat 97.76%
        int ret=0;
        while(x){//
            ret++;
            x=x/10;
        }
        return ret%2==0;//要减少三目运算符的运算！！！
    }
    // int judge(int x){//因为数据量不大于10位数，因此直接log10求位数，Time只能击败78.81%
    //     int ret=1+log10(x);
    //     return ret%2==0;
    // }
    // int judge(int x){// to_string转换成字符串求位数击败 78.81%
    //     int ret=0;
    //     string str = to_string(x);
    //     ret=str.length();
    //     return ret%2==0;
    // // }
    // int judge(int x){//直接判断法求一个数的位数，4ms Time击败97.76%
    //     int ret = 0;
    //     if(x == 100000) ret = 6;
    //     else if(x < 100000 && x >= 10000) ret = 5;
    //     else if(x < 10000 && x >= 1000) ret = 4;
    //     else if(x < 1000 && x>= 100) ret = 3;
    //     else if(x < 100 && x>=10) ret = 2;
    //     else ret = 1;
    //     return ret%2==0;
    // }

    // 如何截断浮点数小数部分,c++标准库的floor函数，double floor(2.6)=2.0
    // int findNumbers(vector<int>& nums) {//奇淫怪，一般想不起来，一行代码解决
    //     int ans = 0;
    //     for(int num : nums){
    //         ans += ((int)(log10(num) + 1) % 2 == 0) ;
    //     }
    //     return ans;
    // }
};