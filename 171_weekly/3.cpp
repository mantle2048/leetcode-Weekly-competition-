#include<iostream>
#include<vector>
using namespace std;
//name: 连通网络的操作次数


const int MAX =  1e5 + 50;
int Tree[MAX];

//以后并查集就用这个标准模板了, 两个函数一个找根, 一个合并
int findRoot(int x){
    if(Tree[x] == -1)
        return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}
bool mergeRoot(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    if(x == y) return false; //合并失败
    if(x > y) swap(x, y); //让数据有序, 以便于获得更好的性能
    Tree[x] = y;
    return true;
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m + 1 < n) return -1; //如果边数m 不能够连通 n 个顶点, 直接返回 -1
        for(int i = 0; i < n; i++) Tree[i] = -1;
        int ans = 0;
        int cnt = n; //初始的连通块的个数为n 
        for(auto con : connections){
            int a = con[0], b = con[1];
            if(mergeRoot(a, b)) cnt--;
        }
        return cnt - 1;
    }
};