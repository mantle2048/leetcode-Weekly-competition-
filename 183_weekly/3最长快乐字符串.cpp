class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
            typedef pair<int, char> IC;
            struct cmp {
                bool operator()(IC ic1, IC ic2){
                    return ic1.first < ic2.first;
                }
            };
        char prev = 'd', prevprev = 'd'; //关键是要记录 上一次和上上次的添加的字符
        priority_queue<IC, vector<IC>, cmp> pq;
        if (a)
            pq.push(make_pair(a, 'a'));
        if (b)
            pq.push(make_pair(b, 'b'));
        if (c)
            pq.push(make_pair(c, 'c'));
        string ans;
        while (!pq.empty()) {
            IC t = pq.top();
            pq.pop();
            if (t.second == prev && t.second == prevprev) {
                if (pq.empty())
                    break;
                IC a = pq.top();
                pq.pop();
                pq.push(t);
                t = a;
            }
            ans += t.second;
            t.first--;
            prevprev = prev;
            prev = t.second;
            if (t.first > 0)
                pq.push(t);
        }
        return ans;
    }
};