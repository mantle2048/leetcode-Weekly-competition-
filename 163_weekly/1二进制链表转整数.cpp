#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//注意链表从头开始遍历是反序的，比如 1->0->1 把101转换十进制等于1*2^2+0*2^1+1*2^0
//相当于每遍历一个Node就把值放入ans中继续遍历，并且把之前的值都×2
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