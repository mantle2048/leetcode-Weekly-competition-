// name:�����ֱ�� 0 �Ĳ�������
// ǩ����
// tips: �ж�����ż��������ɵɵ��%2�� ֱ�� num & 1ȡ���һλ, ��������λ����
class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num != 0){
            ++ans;
            if(num & 1) num -= 1;
            else num = num >> 1;
        }
        return ans;
    }
};