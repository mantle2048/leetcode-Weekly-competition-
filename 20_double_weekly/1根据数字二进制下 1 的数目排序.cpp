// name：根据数字二进制下 1 的数目排序
// 思路：根据题意就可以
// tips: low_bit: x&-x求出二进制为1的最后一位 bcount 统计有多少位1
// 也可以 x & 1 取出二进制最后一位 ,不要再傻傻的 %2 /2了
inline int low_bit(int x){
    return x&-x;
}
inline int bcount(int x){
    int ret = 0;
    while(x > 0){
        x -= low_bit(x);
        ret++;
    }
    return ret;
}
// inline int bcount(int x){ //这样写也可以
//     int ret = 0;
//     while(x){
//         if(x & 1) ++ret;
//         x /= 2;
//     }
//     return ret;
// }
bool cmp(int a, int b){
    if(bcount(a) == bcount(b))
        return a < b;
    else
        return bcount(a) < bcount(b);
}
class Solution {
public:

    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        if(n == 0 || n == 1) return arr;
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};