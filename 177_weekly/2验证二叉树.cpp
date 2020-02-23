// name:��֤������
// ˼·: ���鼯�ж��Ƿ��л����Լ��ж��Ƿ�ֻ��һ����ͨ��
// tips: ���鼯�Ժ������д һ��find_root һ�� merge_root
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
        if(rx > ry) swap(rx, ry); //�涨һ��˳��Ҫ�ú�ֽ->root
        root[rx] = ry;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i < n; i++) root[i] = -1;
        int cnt = n;
        for(int i = 0; i < n; i++){
            int lc = leftChild[i], rc = rightChild[i];
            if(lc != -1)
                if(merge_root(i, lc)) cnt--; else return false; //����ϲ�ʧ��Ҳ����i��lc֮ǰ�Ѿ���ͨ�б��ˣ�Ȼ���ֶ���һ���ߣ������Ͳ�������
            if(rc != -1)
                if(merge_root(i,rc)) cnt--; else return false;
        }
        return cnt == 1;
    }
};