class Solution {
public:
    void helper(vector<int>& nums, vector<int>& ans, vector<vector<int>>& res, int idx, bool flag) {
        if (idx == nums.size()) {
            res.push_back(ans);
            return;
        }
        
        helper(nums, ans, res, idx + 1, false); //excluding current element
        if (idx > 0 && nums[idx] == nums[idx - 1] && !flag) //duplicate
            return;
        
        ans.push_back(nums[idx]); 
        helper(nums, ans, res, idx + 1, true);
        ans.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> res;
        helper(nums, ans, res, 0, true);
        return res;
    }
};
