//name:6 �� 9 ��ɵ��������
// ˼·����ǰ�����ȡ����, ��ȡ��6��ֱ�ӱ�Ϊ9����
// tips: ��ǰ����������� num ����ȷ����ǰλ��Ȩ�� i(��ȷ������num��λ�� to_string(num))����ǰλ�� cur = num / i ÿ�� cur = cur % i�� i /= 10
//       �Ӻ���ǰ�������� num ��ǰλ�� cur = num % 10, num /= 10
class Solution {
public:
    int maximum69Number (int num) {
        for(int i = 1000, cur = num; i >0; i /= 10){
            int now = cur / i; cur = cur % i;
            if(now == 6) return num + (3 * i);
        }
        return num;
    }
};