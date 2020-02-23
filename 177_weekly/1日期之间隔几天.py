# 人生苦短，我用python
class Solution:
    # 好吧 py太差劲了，我居然不知道py的函数参数还能这样定义
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        import datetime
        dayA = datetime.datetime.strptime(date1, '%Y-%m-%d')
        dayB = datetime.datetime.strptime(date2, '%Y-%m-%d')
        ans = (dayB - dayA).days
        if ans < 0: ans = -ans
        return ans
