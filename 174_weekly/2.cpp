// name:数组大小减半
// 贪心，不断删除出现次数最多的数字
// tips: 统计数组中每个数字的出现次数且不需要知道次数对应的数字是多少：先对原数字排序，然后一次遍历一对数字，看两者是否相等，终止条件为到达末尾或者两个数字不相等
// tips: map中的数据按照键值排序： 先用map<int,int>存储每个数字出现的次数，然后vector<pair<int, int>> tmp(map.begin(), map,end())拷贝过来，然后在sort一下 cmp函数如下：
// bool cmp(const pair<int, int>& a, const pair<int, int>& b){
//     return a.second > b.second;
// }
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> cnt;
        int cur_cnt = 0;
        for(int i = 0; i <= n - 1; i++){
            cur_cnt++; //终止条件，i 和 i + 1数字不同了 那么就代表当前统计的次数已经完毕了 || i下标已经到达末尾(i + 1 >=n)提交当前的统计次数次
            if(i + 1 >= n || arr[i] != arr[i + 1]) cnt.push_back(cur_cnt), cur_cnt = 0;
        }
        sort(cnt.begin(),cnt.end());
        reverse(cnt.begin(),cnt.end());
        int sum = 0, ans = 0;
        for(auto i : cnt){
            sum += i; ans++;
            if(sum * 2 >= n) break;
        }
        return ans;
    }
};