python 自带高精度
class Solution:
    def numSteps(self, s: str) -> int:
        num = 0;
        for d in s:
            num = num * 2 + ord(d) - ord('0')
        cnt = 0
        while num > 1:
            if num % 2 == 0:
                num //= 2
            else:
                num += 1
            cnt += 1
        return cnt