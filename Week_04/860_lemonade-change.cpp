class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int val : bills)
        {
            if (val == 5)
            {
                five++;
            }
            else if (val == 10)
            {
                ten++;
                five--;
            }
            else
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else
                {
                    five -= 3;
                }
            }

            if (five < 0)
            {
                return false;
            }
        }

        return true;
    }
};