#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//由于题目要求的范围不是很大10-10^9因此可以直接求出长度为2到9的所有的顺次数，题目的限定太高了所以直接求所有的数最快
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        ans.clear();
        for(int len = 2; len < 10; len++){
            for(int s = 1; s <= 10 - len; s++){
                int tmp = 0;
                for(int i = 1; i <= len; i++){
                    int ret = s + i -1;
                    tmp = tmp * 10 + ret;
                }
                if(tmp <= high && tmp >= low)
                    ans.push_back(tmp);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};