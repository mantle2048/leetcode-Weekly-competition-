#include<iostream>
#include<queue>
using namespace std;


int main(){
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<>> Q;
    while(!Q.empty()) Q.pop();
    Q.push(make_pair(1, make_pair(2,3)));
    Q.push(make_pair(2, make_pair(3,4)));
    Q.push(make_pair(3, make_pair(4,5)));
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<>> P;
    P.push(make_pair(1,2));
    P.push(make_pair(2,3));
    P.push(make_pair(3,4));
    pair<int, pair<int, int>> tmp = Q.top();
    // cout << tmp.first << " ";
    // cout << tmp.second.first << " " << tmp.second.second << endl;
    pair<int ,int > k = P.top();
    cout << k.first << " " << k.second << endl;
    return 0;
}