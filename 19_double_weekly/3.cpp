// name:ʱ��ָ��ļн�
// �ܼ򵥵���ѧ����
// tips: ���һĿ��Ȼ�İ�Int�ĳ���ת��Ϊdouble ��ô��ֱ���ڷ��ӻ��߷�ĸ�ĳ���int����30 ��Ϊ30.0
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_h = 30.0 * hour + 30.0 / 60.0 *minutes;
        double angle_m = 360.0 / 60.0 *minutes;
        double ans = abs(angle_h - angle_m);
        if(ans > 180.0) return 360 - ans;
        return ans;
    }
};