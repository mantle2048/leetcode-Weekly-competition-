#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
//思路：BFS取出 id 编号的人 距离为 level 的朋友, map 存储这些朋友看的Movie 的次数, 最后 sort 一下输出
//bfS DFS 的一个特点就是要 记录结点是否被访问过，记录前驱结点方便求路径
const int MAX = 150;
int dis[MAX];
queue<int> Q;
map<string,int> views;
inline bool cmp(const string& a, const string& b){
    if(views[a] != views[b]) return views[a] < views[b];
    else return a<b;
}

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        memset(dis, -1, sizeof(dis));
        while(!Q.empty()) Q.pop();
        dis[id] = 0;
        Q.push(id);
        while(!Q.empty()){
            int tmp = Q.front(); Q.pop();
            for(auto i : friends[tmp]){
                if(dis[i] == -1){
                    dis[i] = dis[tmp] + 1;
                    Q.push(i);
                }
            }
        }
        vector<string> ans; ans.clear();
        views.clear();
        for(int i = 0; i < n; i++){
            if(dis[i] != level) continue;
            for(auto m : watchedVideos[i]){
                if(views[m] == 0) ans.push_back(m);
                views[m]++;
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};

int main(){
    map<string,int> view;
    view.clear();
    if(views["A"]==0){
        view["A"]++;
    }
    pair<map<string,int>::iterator,bool> is_insert;
   is_insert =view.insert(pair<string,int> ("A",1));
   if(! is_insert.second){
       cout<<"插入失败"<<endl;
   }
    return 0;
}