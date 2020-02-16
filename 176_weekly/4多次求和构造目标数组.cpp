// name: �����͹���Ŀ������
// ˼·�����ֱ任����࿼������˼ά�������������-->[1,1,1,1,1,1,1] rest + max = sum ; pre = max - rest; sum = max; ��ֹ����Ϊ���ֵΪ1����sum< n
// tips:Ҳ����
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

/*�Ӹ�����
#define ll long long
class Solution {
public:
    priority_queue<ll> Q; ���ȶ��б������ֵ
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