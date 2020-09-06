class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i += 2 * k)
        {
            int index = i;
            int end = min(i + k - 1, len - 1);
            while (index < end)
            {
                char tmp = s[index];
                s[index] = s[end];
                s[end] = tmp;
                index++;
                end--;
            }
        }

        return s;
    }
};