// name:��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ
// ��������
// tips: ѧ��ѳ�����ɳ˷���
// ������һ��ӵ�� n - k + 1 ��
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0; int n = arr.size();
        threshold *= k;
        int ret = 0;
        for(int j = 0; j <  k; j++) ret += arr[j];          
        if(ret >= threshold) ++ans;
        for(int i = k; i  < n; i++){
            ret = ret - arr[i - k] + arr[i];
            if(ret >= threshold) ans++;
        }
        return ans;
    }
};