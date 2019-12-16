#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
//��ά����͵���һ��Ҫ�ᣬ�ȸ���ԭ����Ȼ����������ӣ��ٰ����������
//ע���ά������vector��ʾ��Ҫ��ȷ���ڼ���vector����ȷ��vector�ĵڼ���������Ҫ�㷴��
//�����ξ����ֵ��Ϊ�������½�����x0,y0 ���Ͻ�����x,y ��������ȥ����һ�������Σ���ȥ���һ�������Σ��ټ��������������ص��Ĳ��ּ���
int sum[350][350];
class Solution {
public:
    int get_num(int x,int y,int l){
        //����ģ�x,y��Ϊ�������Ӿ�������Ͻǵĵ㣬��������½ǵĵ�
        int x0=x+l-1;int y0=y+l-1;
        return sum[x0][y0]-sum[x0][y-1]-sum[x-1][y0]+sum[x-1][y-1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat[0].size();int n=mat.size();
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=mat[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]+=sum[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]+=sum[i-1][j];
            }
        }
        for(int l=min(m,n);l>=1;l--){
            for(int i=1;i+l-1<=n;i++){
                for(int j=1;j+l-1<=m;j++){
                    //(i,j)���������Ӿ�������Ͻǵĵ�
                    if(get_num(i,j,l)<=threshold)  return l;
                }
            }
        }
        return 0;
    }
};