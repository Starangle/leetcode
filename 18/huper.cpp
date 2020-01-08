class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        
        for(int i = 0; i < size - 3; ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < size - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = size - 1;
                while(l < r){
                    if(nums[i] + nums[j] + nums[l] + nums[r] == target){
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[++l]);
                        while(l < r && nums[r] == nums[--r]);
                    }
                    else if(nums[i] + nums[j] + nums[l] + nums[r] > target) r--;
                    else l++;
                }
            }
        }
        
        return res;
    }
};