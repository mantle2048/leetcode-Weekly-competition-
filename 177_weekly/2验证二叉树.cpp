// name:验证二叉树
// 思路: 并查集判断是否有环，以及判断是否只有一个连通体
// tips: 并查集以后就这样写 一个find_root 一个 merge_root
const int MAXN = 1e4 + 50;
int root[MAXN];
class Solution {
public:
    int find_root(int x){
        if(root[x] == -1)
            return x;
        else{
            int tmp = find_root(root[x]);
            root[x] = tmp;
            return tmp;
        }
    }
    bool merge_root(int x, int y){
        int rx = find_root(x), ry = find_root(y);
        if(rx == ry) return false;
        if(rx > ry) swap(rx, ry); //规定一下顺序，要让孩纸->root
        root[rx] = ry;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i < n; i++) root[i] = -1;
        int cnt = n;
        for(int i = 0; i < n; i++){
            int lc = leftChild[i], rc = rightChild[i];
            if(lc != -1)
                if(merge_root(i, lc)) cnt--; else return false; //如果合并失败也就是i和lc之前已经连通有边了，然而又多了一条边，这样就不是树了
            if(rc != -1)
                if(merge_root(i,rc)) cnt--; else return false;
        }
        return cnt == 1;
    }
};