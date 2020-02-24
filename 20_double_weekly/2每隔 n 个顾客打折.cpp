// name:ÿ�� n ���˿ʹ���
// ˼·:��������
// map<int ,int>�ĺô������Կ��ٲ��ҵ�key��Ӧ��valֱ����map[key]�Ϳ��Եõ���Ӧ��ֵ map.count(key)��¼��û��key�����ֵ
// tips:�Ժ�Ҫ������Ҫ����ĳ��ֵ��Ӧ��ֵ��ʱ��ǵ�ʹ��map
#define ll long long

class Cashier {
public:
    int cur,total;
    int discount;
    map<int,int> pric;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->cur = 0;
        this->total = n;
        this->discount = discount;
        this->pric.clear();
        for(int i = 0; i < prices.size(); i++){
            this->pric[products[i]] = prices[i];
        }
    }
    double getBill(vector<int> product, vector<int> amount) {
        cur++; //��ǰ�˿͵�ID
        bool flag = false;
        if(cur == total) flag = true, cur = 0;
        ll sum = 0; int size = product.size();
        for(int i = 0; i < size; i++){
            int price = pric[product[i]];
            sum += amount[i] * price;
        }
        if(flag) return sum - double(discount * sum) / 100;
        else return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */