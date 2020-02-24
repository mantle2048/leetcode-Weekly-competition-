// name���������ֶ������� 1 ����Ŀ����
// ˼·����������Ϳ���
// tips: low_bit: x&-x���������Ϊ1�����һλ bcount ͳ���ж���λ1
// Ҳ���� x & 1 ȡ�����������һλ ,��Ҫ��ɵɵ�� %2 /2��
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
// inline int bcount(int x){ //����дҲ����
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