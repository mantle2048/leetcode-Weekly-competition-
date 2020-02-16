// name: 多次求和构造目标数组
// 思路：这种变换的题多考虑逆向思维，把数组从现在-->[1,1,1,1,1,1,1] rest + max = sum ; pre = max - rest; sum = max; 终止条件为最大值为1或者sum< n
// tips:也可以
#define ll long long
multiset<ll, greater<ll>> s;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        ll n = target.size();
        ll sum = 0; bool flag = true;
        s.clear();
        for(ll i = 0; i < n; i++){
            sum += target[i];
            s.insert(target[i]);
        }
        sum -= *s.begin();
        while(*s.begin() != 1){
            ll cur = *s.begin() - sum;
            if(cur <= 0){ flag = false; break;}
            s.erase(s.begin()); s.insert(cur);
            sum = sum - *s.begin() + cur;
        }
        return flag;
    }
};

/*坑哥做法
#define ll long long
class Solution {
public:
    priority_queue<ll> Q; 优先队列保存最大值
    bool isPossible(vector<int>& target) {
        while(!Q.empty()) Q.pop();
        int n = target.size();
        ll sum = 0;
        for(auto v : target) Q.push(v), sum += v;
        
        while(sum > n){
            ll cur = Q.top(); Q.pop();
            ll rest = sum - cur;
            ll pre = cur - rest;
            if(rest < 1 || pre < 1) return false;
            sum = cur;
            Q.push(pre);
        }
        return true;
    }
};
*/