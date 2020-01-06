#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
//˼·��BFSȡ�� id ��ŵ��� ����Ϊ level ������, map �洢��Щ���ѿ���Movie �Ĵ���, ��� sort һ�����
//bfS DFS ��һ���ص����Ҫ ��¼����Ƿ񱻷��ʹ�����¼ǰ����㷽����·��
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
       cout<<"����ʧ��"<<endl;
   }
    return 0;
}