from typing import List
from collections import defaultdict


def getsubarrays(arr: List[int]) -> int:
    n = len(arr)
    if n == 0:
        return 0

    # 1. 收集每個值的出現位置
    pos_map = defaultdict(list)
    for i, v in enumerate(arr):
        pos_map[v].append(i)

    total = 0
    # 2. 針對每個可能的長度 k = 值
    for k, pos in pos_map.items():
        if k > n:
            continue  # 長度不可能超過整陣列

        pos = [-1] + pos  # 加左哨兵
        for i in range(1, len(pos)):
            # 起始上界
            left = max(pos[i] - k + 1, pos[i - 1] + 1)
            # 起始下界
            right = min(pos[i], n - k)
            if left <= right:
                total += right - left + 1

    return total


def brute(arr: List[int]) -> int:
    # O(n²) 暴力法，僅用來驗證正確性
    n = len(arr)
    ans = 0
    for i in range(n):
        for j in range(i, n):
            sub = arr[i : j + 1]
            if len(sub) in sub:
                ans += 1
    return ans


def test_getsubarrays():
    cases = [
        [3, 1, 2, 3],  # 5
        [2, 2, 2],  # 2
        [1, 2, 3, 4],  # 6
        [5, 5, 5, 5, 5, 5],  # 2
        [1, 1, 1, 1],  # 4
        [4, 4, 4, 4],  # 1
        [2, 3, 2, 3, 2],  # 7
        [],  # 0
        [10],  # 0
        [1],  # 1
        [3, 3, 3],  # 1
        [3, 1, 3],  # 2
    ]

    for i, arr in enumerate(cases, 1):
        assert getsubarrays(arr) == brute(arr), f"Case {i} failed"
    print("All test cases passed ✅")


test_getsubarrays()
