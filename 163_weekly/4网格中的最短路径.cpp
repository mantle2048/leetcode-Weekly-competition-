#include<utility>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define M(x,y,z) make_pair(make_pair(x,y),z)
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int bfs[50][50][2000];
queue<pair<pair<int,int>,int>> Q;
//pair的用法 make_pair 产生一个 first和second组成的pair，map里面的元素就是pair，map是存储pair的容器
//BFS的用法，所有的求最短路，是否可达等等问题都适用）
// 回溯和DFS
// 回溯搜索是深度优先搜索（DFS）的一种
// 对于某一个搜索树来说（搜索树是起记录路径和状态判断的作用），回溯和DFS，其主要的区别是，回溯法在求解过程中不保留完整的树结构，而深度优先搜索则记下完整的搜索树。
// 为了减少存储空间，在深度优先搜索中，用标志的方法记录访问过的状态，这种处理方法使得深度优先搜索法与回溯法没什么区别了。
// BFS和DFS
// DFS（深度优先搜索）
// 是两个搜索中先理解并使用的，其实就是暴力把所有的路径都搜索出来，它运用了回溯，保存这次的位置，深入搜索，都搜索完了便回溯回来，搜下一个位置，直到把所有最深位置都搜一遍，要注意的一点是，搜索的时候有记录走过的位置，标记完后可能要改回来；
// BFS（广度优先搜索）
// 从某点开始，走四面可以走的路，然后在从这些路，在找可以走的路，直到最先找到符合条件的，这个运用需要用到队列(queue)。=
// 区别
// 其实有时候两个都可以用，不过需要其他的东西来记录什么的，各自有各自的优势
// bfs是用来搜索最短径路的解是比较合适的，比如求最少步数的解，最少交换次数的解，因为bfs搜索过程中遇到的解一定是离最初位置最近的，所以遇到一个解，一定就是最优解，此时搜索算法可以终止，而如果用dfs，会搜一些其他的位置，需要搜很多次，然后还要一个东西来记录这次找的位置，之后找到的还要和这次找到的进行比较，这样就比较麻烦
// dfs适合搜索全部的解，因为要搜索全部的解，在记录路径的时候也会简单一点，而bfs搜索过程中，遇到离根最近的解，并没有什么用，也必须遍历完整棵搜索树。
// bfs是舍弃时间换取空间，bfs是舍去空间换取时间。因为dfs要走很多的路径，可能都是没用的，（做有些题目的时候要进行剪枝，就是确定不符合条件的就可以推出，以免浪费时间，否则有些题目会TLE）；而bfs可以走的点要存起来，需要队列，因此需要空间来储存，但是快一点。
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();int n=grid[0].size();
        while(Q.empty()==false) Q.pop();
        memset(bfs,-1,sizeof(bfs));
        Q.push(M(0,0,0));
        bfs[0][0][0]=0;
        while(Q.empty()==false){
            int x=Q.front().first.first;int y=Q.front().first.second;int p=Q.front().second;
            Q.pop();
            for(int kk=0;kk<4;kk++){
                int nx=x+dx[kk];int ny=y+dy[kk];//nx=next_x
                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                int np=p+grid[nx][ny];
                if(np<=k&&bfs[nx][ny][np]==-1){
                    bfs[nx][ny][np]=bfs[x][y][p]+1;
                    Q.push(M(nx,ny,np));
                }
            }
        }
        int ans=-1;
        for(int i=0;i<=k;i++){
            if(bfs[m-1][n-1][i]!=-1){
                if(ans==-1||ans>bfs[m-1][n-1][i]) ans=bfs[m-1][n-1][i];
            }
        }
        return ans;
    }
};