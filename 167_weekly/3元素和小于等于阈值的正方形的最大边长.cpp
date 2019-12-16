#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
//二维矩阵和的求法一定要会，先复制原矩阵，然后按行依次相加，再按列依次相加
//注意二维矩阵用vector表示，要先确定第几个vector，在确定vector的第几个数，不要搞反了
//正方形矩阵的值就为矩阵右下角坐标x0,y0 左上角坐标x,y 整个大块减去上面一个长方形，减去左边一个长方形，再加上两个长方形重叠的部分即可
int sum[350][350];
class Solution {
public:
    int get_num(int x,int y,int l){
        //输入的（x,y）为正方形子矩阵的左上角的点，求出其右下角的点
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
                    //(i,j)是正方形子矩阵的左上角的点
                    if(get_num(i,j,l)<=threshold)  return l;
                }
            }
        }
        return 0;
    }
};