int dp[10][1 << 8];
// dp[i][xxxxxxxx]��ʾǰi���е�i���Ų�Ϊ"xxxxxxxx"����������������
// ״̬ѹ��dp
class Solution {
public:

    int lowbit(int x){ //lowbit(x)��x�Ķ����Ʊ��ʽ�����λ��1����Ӧ��ֵ��
        return x & -x;
    }
    int bcount(int x){ //bcount(x)ͳ������x�Ķ��������ж���λΪ1
        int ret = 0;
        while(x > 0){
            x -= lowbit(x);
            ret++;
        }
        return ret;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(); int m = seats[0].size();
        
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;

        int lim = 1 << m; //һ��һ��Ҫ��¼mλ
        for(int i = 1; i <= n; i++){ //����ÿһ��
            for(int cur = 0; cur < lim; cur++){ // 0 -> 255 ��Ӧ�� 00000000 -> 11111111 ��������ǰ����λ���Ų� 
                for(int pre = 0; pre < lim; pre++){//0 -> 255 ��Ӧ�� 00000000 -> 11111111 ��������һ����λ���Ų� 
                    if(dp[i - 1][pre] == -1) continue; //�����һ�е�û�и��� pre�Ų���ʽ��״̬ ֱ������
                    bool flag = true; //�������־��¼�Ƿ���Ҫ���µ�ǰ״̬dp[i][cur]
                    for(int j = 0; j < m; j++){ //���� cur �� pre ��ÿһλ�鿴�Ƿ�������ĿҪ��
                        if(((cur>>j) & 1) == 0) continue; //cur��jλ����������ͼ�����һλ
                        if(seats[i - 1][j] == '#') flag = false; //�����i��ʵ�ʵ�seats�е�jλ����������ô
                        if(j >= 1 && ((cur>>(j - 1))&1)) flag ==false; //jλ�õ�����ܲ�����
                        if(j + 1 < m && ((cur>>(j + 1))&1)) flag = false; //jλ�õ��ұ�
                        if(j >= 1 && ((pre>>(j - 1))&1)) flag = false; //��ǰ��
                        if(j + 1 < m && ((pre>>(j + 1))&1)) flag = false; //���
                    }
                    if(flag == false) continue;
                    dp[i][cur] = max(dp[i][cur], dp[i - 1][pre] + bcount(cur));
                }
            }
        }
        int ans = 0;
        for(int s = 0; s < lim; s++) ans = max(ans, dp[n][s]);
        return ans;
    }
};


        // for(int i = 0; i < n; i++){
        //     int cur = 0;
        //     for(int j = 0; j < m; j++){
        //         cur = cur * 2 + seats[i];
        //     }
        //     buf.push_back(cur);
        // }
        // for(int i = 1; i <= n; i++){
        //     int cur = buf[i]; int pre = buf[i - 1];
        //     bool flag = false;
        //     for(int j = 0; j < m; j++){
        //         if(((cur>>j) & 1) == 0) continue; //cur��jλ����������ͼ�����һλ
        //         if(seats[i - 1][j] == '#') flag = false; //�����i��ʵ�ʵ�seats�е�jλ����������ô
        //         if(j >= 1 && ((cur>>(j - 1))&1)) flag ==false; //jλ�õ�����ܲ�����
        //         if(j + 1 < m && ((cur>>(j + 1))&1)) flag = false; //jλ�õ��ұ�
        //         if(j >= 1 && ((pre>>(j - 1))&1)) flag = false; //��ǰ��
        //         if(j + 1 < m && ((pre>>(j + 1))&1)) flag = false; //���
        //     }
        // }