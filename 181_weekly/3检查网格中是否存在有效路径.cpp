#define pii pair<int, int>
const int MAXN = 350;
bool mark[MAXN][MAXN];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pii> Q;
        memset(mark, false, sizeof(mark));
        mark[0][0] = true;
        Q.push(make_pair(0,0));
        while(!Q.empty()){
            pii tmp = Q.front();
            Q.pop();
            int x = tmp.first, y = tmp.second;
            int now = grid[x][y];
            mark[x][y] = true;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(mark[nx][ny]) continue;
                int next = grid[nx][ny];
                if(i == 0 && (now == 1 || now == 3 || now == 5) && (next == 4 || next == 6 || next == 1)) Q.push(make_pair(nx, ny));
                if(i == 1 && (now == 1 || now == 4 || now == 6) && (next == 3 || next == 5 || next == 1)) Q.push(make_pair(nx, ny));
                if(i == 2 && (now == 2 || now == 5 || now == 6) && (next == 3 || next == 4 || next == 2)) Q.push(make_pair(nx, ny));
                if(i == 3 && (now == 2 || now == 3 || now == 4) && (next == 5 || next == 6 || next == 2)) Q.push(make_pair(nx, ny));
            }
        }
        return mark[m - 1][n - 1];
        
    }
};