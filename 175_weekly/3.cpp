// name:���ļ���
// ˼·����ģ�� �������������У� ���ʹ��map �� multiset<int>, Ҫע���������Ϊ����ҿ�
// void upper_bound(int l,int r,int x){
//       while(l<r��{
//         int mid=(r-l)/2;
//         if(x < a[mid]) r=mid; //���߽�������һ�㲻ͬ
//         else  l=mid+1;
//     }
// }

//���߶�Ҫ������������Ϊ�Ƕ��ֲ���....
// upper���ֲ���5��ʱ�򣬱������� 5 5 5 5 �ĸ���ͬ��Ԫ�� �᲻�ϵ�����ƶ���l��λ��Ϊ5��ĵ�һ��λ�ã���r������ʼ��ָ��5��ĵ�һ��λ�ã����� >5�ĵ�һ��λ��
// lower���ֲ���5��ʱ�򣬱������� 5 5 5 5 �ĸ�Ԫ�أ�һ��������һ�� r�ͻῨ�ڵ�һ��5��λ�ã����� >=5�ĵ�һ��λ��

// void lower_bound(int l,int r,int x){
//    while(l<r){
//        int mid=(r-l)/2;
//        if(a[mid]>=x) r=mid; //���߽�������һ�㲻ͬ
//        else l=mid+1;
//     }
// }


// map.insert�����ֲ��뷽ʽ��insert������ͬ�ļ�ֵ����ԣ������Ḳ�ǣ�������Ҫ������Ҫ���ж��Ƿ����(map.count(key) or map.find(key))��ɾ��erase(iter)
//  maps.insert(pair<int, int> (10, 15)); insert�ķ���ֵΪpair<iterator, bool>
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
        vector<int> ans; ans.clear();  ++endTime; //�������ҿ�
        if(freq == "minute") delta = 60;
        if(freq == "hour") delta = 3600;
        if(freq == "day") delta = 86400;
        for(i = 0; startTime + delta * i < endTime; i++){
            int s = startTime + delta * i, e = min(startTime + delta * (i + 1), endTime);
            multiset<int>::iterator it = store[tweetName].lower_bound(s); //���� >= startTime�ĵ�һ��λ��
            multiset<int>::iterator ed = store[tweetName].upper_bound(e - 1); //���� > endTime - 1 �ĵ�һ��λ��
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