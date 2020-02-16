// name:�����ԲμӵĻ�����Ŀ
// ˼·��̰�� + ���ȶ��� 
//  ̰��˼·�ǰ�����Ŀ�ʼʱ������Ȼ����priority_queue���浱ǰʱ��now���ԲμӵĻ��飬�μ�endʱ���ǰ��һ������
// ̰�ĵ���ȷ���Ƕ�����˵�����ǵȼ۵ģ��μ���������ô���Ļ��鶼ֻ��ռ����һ���ʱ�䣬��Ҫ���ľ��������޵����������ܶ�Ĳμӻ��飬��ô��ֻ��Ҫ�ܲμӾ�������Ĳμӣ������ǰʱ���кܶ���鶼�ܲμӣ���ô�Ҿ�ѡ��һ������Ҫ�����Ļ���Ͻ��μ���
// tips �������ְ��Ż����Ŀ����ģ�壬���ȶ���Ĭ��Ϊ�󶥶Ѽ��Ѷ�Ϊ���ֵ���� < �ţ������Ĵ��ֵ�ŵ��Ѷ��������Ҫ����ΪС���ѣ���ôֻ��Ҫ�ڽṹ��������С�ں�<
// tips set<T, Compare(������()����)> s�Զ�������  1.����<�����Զ�������ݽṹ������<���ɣ�2.����()�¶���һ���ṹ�壬����()���������������������
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
        return end > T.end; //����ΪС���ѣ��󶥶�ΪС�ںţ�С����Ϊ���ں�
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