#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//ע�������ͷ��ʼ�����Ƿ���ģ����� 1->0->1 ��101ת��ʮ���Ƶ���1*2^2+0*2^1+1*2^0
//�൱��ÿ����һ��Node�Ͱ�ֵ����ans�м������������Ұ�֮ǰ��ֵ����2
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head){
            ans=ans*2+head->val;
            head=head->next;
        }
        return ans;
    }
};