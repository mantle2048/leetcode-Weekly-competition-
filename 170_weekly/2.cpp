#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//����������Ŀ, ����һά��[0,0][0,1][0,2],[0,3] ��ô [1,3] = [0,3] - [0,1], �ؼ����� ͬһ������ ��� Ϊ 0 
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> buf = {arr[0]};
        int n = arr.size();
        for( int i = 1; i < n; i++){
            buf.push_back(buf.back() xor arr[i]);
        }
        vector<int> ret; ret.clear();
        for( auto q : queries){
            if(q[0] >= 1)
                ret.push_back( buf[q[1]] xor buf[q[0]-1]);
            else
                ret.push_back(buf[q[1]]);
        }
        return ret;
    }
};
int main(){
    vector<int> buf;
    buf.clear();
    buf.push_back(buf.back() xor 12);
    cout<<buf[0]<<endl;
    return 0;
}