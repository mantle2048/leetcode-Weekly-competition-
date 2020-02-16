// name:最多可以参加的会议数目
// 思路：贪心 + 优先队列 
//  贪心思路是按会议的开始时间排序，然后用priority_queue保存当前时间now可以参加的会议，参加end时间最靠前的一个会议
// 贪心的正确性是对你来说会议是等价的，参加了无论怎么样的会议都只会占用你一天的时间，你要做的就是用有限的天数尽可能多的参加会议，那么我只需要能参加尽可能早的参加，如果当前时刻有很多会议都能参加，那么我就选择一个马上要截至的会议赶紧参加了
// tips 类似这种安排活动的题目都是模板，优先队列默认为大顶堆即堆顶为最大值（即 < 号，后插入的大的值放到堆顶），如果要重载为小顶堆，那么只需要在结构体中重载小于号<
// tips set<T, Compare(重载了()的类)> s自定义排序  1.重载<：在自定义的数据结构中重载<即可，2.重载()新定义一个结构体，重载()传入两个对象定义排序规则
const int MAXN = 1e5 + 50;
struct Event{
    int start;
    int end;
    Event(){}
    Event(int s0, int e0){
        start = s0;
        end = e0;
    }
    bool operator < (const Event& T) const{
        return end > T.end; //重载为小顶堆，大顶堆为小于号，小顶堆为大于号
    }
}Eve[MAXN];
priority_queue<Event> que;
inline bool cmp(const Event& a, const Event& b){
    return a.start < b.start;
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int mi = events[0][0], ma = events[0][1];
        for(int i = 0; i < n; i++){
            mi = min(mi, events[i][0]);
            ma = max(ma, events[i][1]);
            Eve[i] = Event(events[i][0], events[i][1]);
        }
        sort(Eve + 0, Eve + n, cmp);
        while(!que.empty()) que.pop();
        int ans = 0;
        for(int i = mi, j = 0; i <= ma; i++){
            while(j < n && Eve[j].start <= i)
                que.push(Eve[j++]);
            while(!que.empty() && que.top().end < i)
                que.pop();
            if(!que.empty()) ans++, que.pop();
        }
        return ans;
    }
};