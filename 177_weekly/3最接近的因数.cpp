// name:��ӽ�������
// ˼·��num������һ����sqrt(num)����, ��sqrt(num)���������ֻ����һ��
// ������num1��num2��sqrt(num2)��ʼ����ǰ���ƣ�����ͬһ����i����ܱ�num1��num2��������ônum1����������֮��ļ���϶���С
// tips:����<---->sqrt(num)
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num + 1, num2 = num + 2;
        for(int i = sqrt(num2); i > 0; i--){
            if(num1 % i == 0) return {i, num1/i};
            if(num2 % i == 0) return {i, num2/i};
        }
        return {0,0};
    }
};