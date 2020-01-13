#include<iostream>
#include<vector>
using namespace std;
//name: ��ָ����ĵ���С����
//���ݺ���ֱ�ӱ���
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int lo = 1; int hi = n - 1;
        while(lo <= hi){
            if(not_0(lo) && not_0(hi))
                return {lo, hi};
            lo++; hi--;
        }
        return {0, 0};
    }
    bool not_0(int a){
        if(a == 0) return false;
        while(a != 0){
            int tmp = a % 10;
            if(tmp == 0) return false;
            a /= 10;
        }
        return true;
    }
};