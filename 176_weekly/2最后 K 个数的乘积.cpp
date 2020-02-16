// name:��� K �����ĳ˻�
// tips:���������k�����ĳ˻����߼ӷ� ������������ļ�ȥǰ׺������ k ~ n = 1 ~ n / 1 ~ k - 1
// vector<pair<int, int> >������
class ProductOfNumbers {
    public:
    int mult[40010],isZeroPos,n;//mult�洢����ǰ׺���˻�, isZeroPos�洢�������һ��0��λ��
    ProductOfNumbers() {
        n = 0;//��ǰ��ӵ������±�
        isZeroPos = 0;//���������±� �����˻�Ϊ0
        mult[0] = 1;
    }
    void add(int num) {
        ++n;
        if(num == 0) 
            isZeroPos = n, mult[n] = 1;//����0��,��Ϊ�õ�Ժ�������ĳ˻���Ӱ�����˴����˻�Ϊ 1
        else mult[n] = mult[n-1]*num; 
    }
    int getProduct(int k) {
        k = n-k+1;//Ҳ���Ǵ�ǰ�������ĵ�n-k+1����
        if(k <= isZeroPos) return 0;//������0 �������˻�һ��Ϊ0
        else return mult[n]/mult[k-1];//��������0 ��Ϊk~n�����˻�=1~n�����˻�/1~k-1�����˻�
    }
};


/*�Ӹ������� ����32-bit���ص㣬���ֻ����32�γ˷������һ�����зǳ����1�����ǾͿ��Զ����н���ѹ����
 ����� 1111111 22 1111 32 11 ����ѹ���� {1:7, 22:1, 1:4, 32:1, 1:2}Ȼ��Ӻ���ǰ�����Ϳ�
 ˼·���� 
class ProductOfNumbers {
public:
    vector<pair<int, int> > buf;
    ProductOfNumbers() {
        buf.clear();
    }
    
    void add(int num) {
        if(buf.size() == 0 || num != 1)
            buf.push_back(make_pair(num, 1));
        else{
            if(buf.back().first != 1)
                buf.push_back(make_pair(num, 1));
            else{
                int cnt = buf.back().second + 1;
                buf.pop_back();
                buf.push_back(make_pair(num, cnt));
            }
        }
    }
    
    int getProduct(int k) {
        int n = buf.size(), ret = 1;
        for(int i = n - 1; i >= 0 && k > 0; i--){
            if(buf[i].first == 0) return 0;
            if(buf[i].first == 1){
                k -= buf[i].second;
            }
            else{
                k -= 1;
                ret *= buf[i].first;
            }
        }
        return ret;
    }
};
*/

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */