// name:最接近的因数
// 思路：num的因数一定在sqrt(num)以内, 在sqrt(num)以外的至多只能有一个
// 两个数num1和num2从sqrt(num2)开始，向前推移，对于同一个数i如果能被num1和num2整除，那么num1的两个因数之间的间隔肯定更小
// tips:因数<---->sqrt(num)
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