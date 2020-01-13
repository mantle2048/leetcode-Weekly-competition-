#include<iostream>
using namespace std;
//name: 或运算的最小翻转次数

//快速转换2进制 >> 位运算 << 对于一个数tmp,  >> 1 除以2 再将其 & 1 取出最后一位
//快速转换8进制 >> 位运算 << 对于一个数tmp,  >> 3 除以8 再将其 & 7 取出最后三位
//快速转换16进制 >> 位运算 << 对于一个数tmp,  >> 4 除以16 再将其 & 15 取出最后一位   
class Solution {
public:
    int minFlips(int a, int b, int c) {
        if(a + b == c) return 0;
        int ans = 0;
        for(int i = 0; i <= 30; i++){ //最多就30位, 依次枚举 i = 0 是数据本身 i = 1 是原数据 /2
        int Flib_a = (a >> i) & 1;
        int Flib_b = (b >> i) & 1;
        int Flib_c = (c >> i) & 1; //一次迭代, 取出三个数的一位
        if((Flib_a | Flib_b) == Flib_c) continue;
        if(Flib_c == 1) ans++;
        else ans += Flib_a + Flib_b;
        }
        return ans;
    }
};