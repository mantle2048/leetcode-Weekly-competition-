// name:�����С����
// ̰�ģ�����ɾ�����ִ�����������
// tips: ͳ��������ÿ�����ֵĳ��ִ����Ҳ���Ҫ֪��������Ӧ�������Ƕ��٣��ȶ�ԭ��������Ȼ��һ�α���һ�����֣��������Ƿ���ȣ���ֹ����Ϊ����ĩβ�����������ֲ����
// tips: map�е����ݰ��ռ�ֵ���� ����map<int,int>�洢ÿ�����ֳ��ֵĴ�����Ȼ��vector<pair<int, int>> tmp(map.begin(), map,end())����������Ȼ����sortһ�� cmp�������£�
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
            cur_cnt++; //��ֹ������i �� i + 1���ֲ�ͬ�� ��ô�ʹ���ǰͳ�ƵĴ����Ѿ������ || i�±��Ѿ�����ĩβ(i + 1 >=n)�ύ��ǰ��ͳ�ƴ�����
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