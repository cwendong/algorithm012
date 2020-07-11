class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int len = nums.size();
        int i = 0;
        for (int j = 1; j < len; j++)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }

        return 0 == len ? 0 : i + 1;
    }
};