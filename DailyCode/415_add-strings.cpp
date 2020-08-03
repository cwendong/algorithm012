class Solution {

public:

    string addStrings(string num1, string num2) {
        int num1Len = num1.size() - 1;
        int num2Len = num2.size() - 1;
        string result;
        int overTen = 0;
        while (num1Len >= 0 || num2Len >= 0)
        {
            int num1Tmp = num1Len >= 0 ? num1[num1Len] - '0' : 0;
            int num2Tmp = num2Len >= 0 ? num2[num2Len] - '0' : 0;

            int sum = num1Tmp + num2Tmp + overTen;
            overTen = sum / 10;
            sum %= 10;
            result.push_back('0' + sum);
            
            num1Len--;
            num2Len--;
        }

        if (overTen > 0)
        {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        
        return result;
    }
};