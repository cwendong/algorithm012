class Solution {
public:
    int climbStairs(int n) {

       /*
        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        }

        return climbStairs(n - 1) + climbStairs(n -2);
        */

        int first = 1;
        int second = 1;
        int current = 1;

        for (int i = 1; i < n; ++i)
        {
            current = first + second;
            first = second;
            second = current;
        }

        return current;
    }
};