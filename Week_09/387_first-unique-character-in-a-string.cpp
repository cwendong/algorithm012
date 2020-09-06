class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> helper;
        int len = s.length();

        for (int i = 0; i < len; ++i)
        {
            if ( helper.find(s[i]) != helper.end())
            {
                helper[s[i]]++;
            }
            else 
            {
                helper[s[i]] = 1;
            }
        }

        for (int i = 0; i < len; ++i)
        {
            if (helper[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};