//recursive
class Solution {
public:
    int climbStairs(int n) {
        //base case
        if(n <= 1) return 1;
        
        //recursive case
        return climbStairs(n-1) + climbStairs(n-2);
    }
};