#include<iostream>
using namespace std;
//name: ���������С��ת����

//����ת��2���� >> λ���� << ����һ����tmp,  >> 1 ����2 �ٽ��� & 1 ȡ�����һλ
//����ת��8���� >> λ���� << ����һ����tmp,  >> 3 ����8 �ٽ��� & 7 ȡ�������λ
//����ת��16���� >> λ���� << ����һ����tmp,  >> 4 ����16 �ٽ��� & 15 ȡ�����һλ   
class Solution {
public:
    int minFlips(int a, int b, int c) {
        if(a + b == c) return 0;
        int ans = 0;
        for(int i = 0; i <= 30; i++){ //����30λ, ����ö�� i = 0 �����ݱ��� i = 1 ��ԭ���� /2
        int Flib_a = (a >> i) & 1;
        int Flib_b = (b >> i) & 1;
        int Flib_c = (c >> i) & 1; //һ�ε���, ȡ����������һλ
        if((Flib_a | Flib_b) == Flib_c) continue;
        if(Flib_c == 1) ans++;
        else ans += Flib_a + Flib_b;
        }
        return ans;
    }
};