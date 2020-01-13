#include<iostream>
#include<vector>
using namespace std;
//name: ��ͨ����Ĳ�������


const int MAX =  1e5 + 50;
int Tree[MAX];

//�Ժ󲢲鼯���������׼ģ����, ��������һ���Ҹ�, һ���ϲ�
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
    if(x == y) return false; //�ϲ�ʧ��
    if(x > y) swap(x, y); //����������, �Ա��ڻ�ø��õ�����
    Tree[x] = y;
    return true;
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m + 1 < n) return -1; //�������m ���ܹ���ͨ n ������, ֱ�ӷ��� -1
        for(int i = 0; i < n; i++) Tree[i] = -1;
        int ans = 0;
        int cnt = n; //��ʼ����ͨ��ĸ���Ϊn 
        for(auto con : connections){
            int a = con[0], b = con[1];
            if(mergeRoot(a, b)) cnt--;
        }
        return cnt - 1;
    }
};