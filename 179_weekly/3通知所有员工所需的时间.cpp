// BFS树算出每个节点的通知时间然后取最大值
const int MAXN = 1e5 + 50;
int dist[MAXN];
vector<int> edge[MAXN];
class Solution {
public:
    int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        ans = 0;
        for(int i = 0; i < n; i++) dist[i] = 0, edge[i].clear();
        for(int i = 0; i < n; i++)
            if(manager[i] != -1) edge[manager[i]].push_back(i);
        queue<int> Q; while(!Q.empty()) Q.pop();
        Q.push(headID); dist[headID] = 0;
        while(!Q.empty()){
            int tmp = Q.front(); Q.pop();
            ans = max(ans, dist[tmp]);
            for(auto e : edge[tmp]){
                dist[e] = dist[tmp] + informTime[tmp];
                Q.push(e); 
            }
        }
        return ans;
    }
};