// name:推文计数
// 思路：大模拟 跟着题意做就行， 灵活使用map 和 multiset<int>, 要注意调整区间为左闭右开
// void upper_bound(int l,int r,int x){
//       while(l<r）{
//         int mid=(r-l)/2;
//         if(x < a[mid]) r=mid; //两者仅仅有这一点不同
//         else  l=mid+1;
//     }
// }

//两者都要求数组有序，因为是二分查找....
// upper二分查找5的时候，比如碰到 5 5 5 5 四个相同的元素 会不断的向后移动，l的位置为5后的第一个位置，而r不动，始终指向5后的第一个位置，返回 >5的第一个位置
// lower二分查找5的时候，比如碰到 5 5 5 5 四个元素，一旦遇到第一个 r就会卡在第一个5的位置，返回 >=5的第一个位置

// void lower_bound(int l,int r,int x){
//    while(l<r){
//        int mid=(r-l)/2;
//        if(a[mid]>=x) r=mid; //两者仅仅有这一点不同
//        else l=mid+1;
//     }
// }


// map.insert的两种插入方式，insert插入相同的键值会忽略，而不会覆盖，因此如果要覆盖需要先判断是否存在(map.count(key) or map.find(key))再删除erase(iter)
//  maps.insert(pair<int, int> (10, 15)); insert的返回值为pair<iterator, bool>
//  maps.insert(make_pair(10, 15));

class TweetCounts {
public:
    map<string, multiset<int>> store;
    int i;
    int delta;
    TweetCounts() {
        store.clear();
        i = 0;
        delta = 0;
    }

    void recordTweet(string tweetName, int time) {
        store[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans; ans.clear();  ++endTime; //变成左闭右开
        if(freq == "minute") delta = 60;
        if(freq == "hour") delta = 3600;
        if(freq == "day") delta = 86400;
        for(i = 0; startTime + delta * i < endTime; i++){
            int s = startTime + delta * i, e = min(startTime + delta * (i + 1), endTime);
            multiset<int>::iterator it = store[tweetName].lower_bound(s); //返回 >= startTime的第一个位置
            multiset<int>::iterator ed = store[tweetName].upper_bound(e - 1); //返回 > endTime - 1 的第一个位置
            int tmp = 0;
            for(it; it != ed; it++){
                if(*it >= s && *it < e)
                    tmp++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */