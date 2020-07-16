class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> helper;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (helper.find(target - nums[i]) != helper.end())
            {
                return {helper[target - nums[i]], i};
            }
            helper[nums[i]] = i;
        }

        return {-1, -1};     
    }
};