def get_floor_top_down(n):
    if n == 1:
        return 1
    if n == 2:
        return 2

    return get_floor_top_down(n - 1) + get_floor_top_down(n - 2)


def get_floor_bottom_up(n):
    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2
    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]


def get_floor_bottom_up_space_opt(n):
    if n == 1:
        return 1
    if n == 2:
        return 2

    prev_prev, prev = 1, 2
    for i in range(3, n + 1):
        current = prev + prev_prev
        prev_prev, prev = prev, current

    return current


if __name__ == "__main__":
    n = 5
    print(get_floor_top_down(n))
    print(get_floor_bottom_up(n))
    print(get_floor_bottom_up_space_opt(n))
