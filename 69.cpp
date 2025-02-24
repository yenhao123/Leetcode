#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int high = x, low = 0;
        double res = x;
        while (res > 0) {
            if (res * res <= x) {
                if ((res + 1) * (res + 1) > x) return res;
                low = res;
            } else {
                high = res;
            }
            res = (high + low) / 2;
        }
        return res;
    }
};

// **測試函式**
void test() {
    Solution sol;
    
    // 測試案例
    int test_cases[] = {0, 1, 4, 8, 10, 16, 25, 26, 100, 101, 2147395599, INT_MAX};

    for (int x : test_cases) {
        cout << "Input: " << x << " | Output: " << sol.mySqrt(x) << endl;
    }
}

int main() {
    test();
    return 0;
}
