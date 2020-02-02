// spfa版本
// 所谓spfa就是bfs带权版，利用队列和邻接表 从 单源点s出发一直走走走遍历起点为s的所有边，更新距离矩阵，在把边 的另一个顶点入队，反复直到队列为控
// 邻接表的实现简化版 vector<pair<int,int> > edges[n]
#define MAXN 150
class Solution {
public:
    int dis[MAXN], inQue[MAXN];
    queue<int> Q;
    vector<pair<int,int> > edge[MAXN];
    int bfs(int s, int threshold, int n){
        while(!Q.empty()) Q.pop();
        memset(dis, -1, sizeof(dis));
        memset(inQue, 0, sizeof(inQue));

        dis[s] = 0; inQue[s] = 1; Q.push(s); //首元素放进去

        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for(auto cur : edge[x]){
                int t = cur.first; int w = cur.second;
                if(dis[t] == -1 || dis[t] > dis[x] + w){
                    dis[t] = dis[x] + w;
                    if(!inQue[t]){ //t还没入队的话就把t入队
                        inQue[t] = 1;
                        Q.push(t);
                    }
                }
            }
            inQue[x] = 0;
        }
        int ret = 0;
        for(int i = 0; i < n; i++){
            if(dis[i] == -1) continue;
            if(i != s && dis[i] <= threshold) ret++;
        }
        return ret;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i = 0; i < n; i++) edge[i].clear();
        for(auto cur : edges){
            int a = cur[0], b = cur[1], c = cur[2];
            edge[a].push_back(make_pair(b, c));
            edge[b].push_back(make_pair(a, c));
        }
        int ans = -1, min = n + 1;
        for(int s = 0; s < n; s++){
            int cur_city = bfs(s, distanceThreshold, n);
            if(min >= cur_city) min = cur_city, ans = s;
        }
        return ans;
    }
};