// ��Ŀ���ƣ�ͳ��λ��Ϊż��������
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
//С��ʿ�������о���������Ŀ��������ж������������������������������Ҫ����ӵȺŻ��߲��Ⱥ��ж���
//С��ʿ���� λ�� �����У�log10 log2 
    int judge(int x){//ֱ�ӳ�10����������Ŀ������������������ٶȣ���˾�����ʹ�� 4ms Beat 97.76%
        int ret=0;
        while(x){//
            ret++;
            x=x/10;
        }
        return ret%2==0;//Ҫ������Ŀ����������㣡����
    }
    // int judge(int x){//��Ϊ������������10λ�������ֱ��log10��λ����Timeֻ�ܻ���78.81%
    //     int ret=1+log10(x);
    //     return ret%2==0;
    // }
    // int judge(int x){// to_stringת�����ַ�����λ������ 78.81%
    //     int ret=0;
    //     string str = to_string(x);
    //     ret=str.length();
    //     return ret%2==0;
    // // }
    // int judge(int x){//ֱ���жϷ���һ������λ����4ms Time����97.76%
    //     int ret = 0;
    //     if(x == 100000) ret = 6;
    //     else if(x < 100000 && x >= 10000) ret = 5;
    //     else if(x < 10000 && x >= 1000) ret = 4;
    //     else if(x < 1000 && x>= 100) ret = 3;
    //     else if(x < 100 && x>=10) ret = 2;
    //     else ret = 1;
    //     return ret%2==0;
    // }

    // ��νضϸ�����С������,c++��׼���floor������double floor(2.6)=2.0
    // int findNumbers(vector<int>& nums) {//�����֣�һ���벻������һ�д�����
    //     int ans = 0;
    //     for(int num : nums){
    //         ans += ((int)(log10(num) + 1) % 2 == 0) ;
    //     }
    //     return ans;
    // }
};