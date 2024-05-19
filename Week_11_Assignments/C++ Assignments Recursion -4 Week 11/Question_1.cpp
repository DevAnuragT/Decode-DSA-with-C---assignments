class Solution {
public:
    void helper(vector<int>& nums,vector<int> ans,vector<vector<int>>& res, int idx){
        if(idx==nums.size()){
            res.push_back(ans);
            return;
        }
        helper(nums,ans,res,idx+1);
        ans.push_back(nums[idx]);
        helper(nums,ans,res,idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        helper(nums,ans,res,0);
        return res;
    }
};
