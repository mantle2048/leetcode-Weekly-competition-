// name:有效的快递序列数目
// 思路：组合数学问题 假设n个快递,一共 2n个空, 每次配送都从当前剩余位置x中组合选择两个位置安放P和D
// 例如 n = 3 则 ans = C(6,2) + C(4,2) + C(2,2)
#define ll long long
const ll MAXN = 1e9 + 7;
class Solution {
public:
    ll cal_c(int x){
        return x * (x - 1) / 2;
    }
    int countOrders(int n) {
        n *= 2;
        ll ans = 1;
        while(n > 0){
            ans *= cal_c(n);
            ans = ans % MAXN;
            n = n - 2;
        }
        return ans ;
    }
};