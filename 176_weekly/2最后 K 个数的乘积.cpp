// name:最后 K 个数的乘积
// tips:类似求后面k个数的乘积或者加法 都可以用总体的减去前缀的来求 k ~ n = 1 ~ n / 1 ~ k - 1
// vector<pair<int, int> >的妙用
class ProductOfNumbers {
    public:
    int mult[40010],isZeroPos,n;//mult存储的是前缀连乘积, isZeroPos存储的是最后一个0的位置
    ProductOfNumbers() {
        n = 0;//当前添加的数的下标
        isZeroPos = 0;//若包含该下标 则连乘积为0
        mult[0] = 1;
    }
    void add(int num) {
        ++n;
        if(num == 0) 
            isZeroPos = n, mult[n] = 1;//更新0点,因为该点对后面的数的乘积无影响故令此处连乘积为 1
        else mult[n] = mult[n-1]*num; 
    }
    int getProduct(int k) {
        k = n-k+1;//也就是从前往后数的第n-k+1个数
        if(k <= isZeroPos) return 0;//包含了0 所以连乘积一定为0
        else return mult[n]/mult[k-1];//若不包含0 则为k~n的连乘积=1~n的连乘积/1~k-1的连乘积
    }
};


/*坑哥做法： 利用32-bit的特点，最多只能做32次乘法，因此一定会有非常多的1，我们就可以对序列进行压缩，
 如果是 1111111 22 1111 32 11 可以压缩成 {1:7, 22:1, 1:4, 32:1, 1:2}然后从后向前遍历就可
 思路清晰 
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