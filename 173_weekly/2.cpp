// name:餐厅过滤器
// 模拟 按照他说的做就行 不难
struct Buf{
    int id; 
    int rating;
};
bool cmp(Buf a, Buf b){
    if(a.rating != b.rating) return a.rating > b.rating;
    return a.id > b.id;
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<Buf> ans; ans.clear();
        for(auto cur : restaurants){
            if(veganFriendly == 1 && cur[2] != veganFriendly) continue;
            if(maxPrice < cur[3] || maxDistance < cur[4]) continue;
            Buf tmp; tmp.id = cur[0]; tmp.rating = cur[1];
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int> ret; ret.clear();
        for(auto cur : ans){
            ret.push_back(cur.id);
        }
        return ret;
    }
};