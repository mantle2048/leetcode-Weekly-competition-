#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//������ĿҪ��ķ�Χ���Ǻܴ�10-10^9��˿���ֱ���������Ϊ2��9�����е�˳��������Ŀ���޶�̫��������ֱ�������е������
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