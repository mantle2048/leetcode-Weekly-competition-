// name:时钟指针的夹角
// 很简单的数学问题
// tips: 如何一目了然的把Int的除法转换为double 那么就直接在分子或者分母的常量int例如30 变为30.0
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