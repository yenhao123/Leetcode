class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0 for _ in range(n)]
        dp[0] = 1 if s[-1] != "0" else 0
        if n == 1:
            return dp[0]

        if s[-2] == "0":
            dp[1] = 0
        elif self.can_aggregate(s[-2:]):
            dp[1] = dp[0] + 1
        else:
            dp[1] = dp[0]

        if dp[1] == 0 and dp[0] == 0:
            return 0

        for i in range(2, n):
            if s[n - i - 1] == "0":
                dp[i] = 0
            elif self.can_aggregate(s[n - i - 1 : n - i + 1]):
                dp[i] = dp[i - 1] + dp[i - 2]
            else:
                dp[i] = dp[i - 1]

            if dp[i] == 0 and dp[i - 1] == 0:
                return 0

        return dp[n - 1]

    def can_aggregate(self, s):
        if 10 <= int(s) <= 26:
            return True
        else:
            return False
