// name:每隔 n 个顾客打折
// 思路:按题意来
// map<int ,int>的好处，可以快速查找到key对应的val直接用map[key]就可以得到对应的值 map.count(key)记录有没有key这个键值
// tips:以后要是遇到要查找某个值对应的值的时候记得使用map
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
        cur++; //当前顾客的ID
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