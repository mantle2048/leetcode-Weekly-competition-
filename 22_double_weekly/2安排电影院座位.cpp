// ˼·������˼ά ����ÿ�ж��ܷ���������Ȼ����һ�ų����~
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> buf = reservedSeats;
        sort(buf.begin(), buf.end(),cmp);
        int ans = 2 * n; //����ÿ�ж��ܷ���������Ȼ����һ�ų�
        int  vis[15];
        for(int i = 0; i < 15; i++) vis[i] = 1;
        for(int i = 0; i < buf.size(); i++){
            vis[buf[i][1]] = 0;
            if(i == buf.size() - 1 || buf[i][0] != buf[i + 1][0]){ //��һ�б�ռ����
                // ����ǰ��
                int tmp = 0; //tmp��¼��ǰ��������ܷŵļ�ͥ���Ĳ�ֵ
                int a = vis[2] && vis[3];
                int b1 = vis[4] && vis[5];
                int b2 = vis[6] && vis[7];
                int c = vis[8] && vis[9];
                if(a && c && b1 && b2) tmp += 0; // ��ǰ���ܷ�2��
                else if(a && b1) tmp += 1; // 1�� ��Ԥ���1������1��
                else if(b2 && c) tmp += 1; // 1��
                else if(b1 && b2) tmp += 1; // 1��
                else tmp += 2; // ��ǰ���ܷ�0������Ԥ���2����������
                ans -= tmp;
                for(int i = 0; i < 15; i++) vis[i] = 1;
            }
        }
        return ans;
    }
};
