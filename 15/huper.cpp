class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size =  nums.size();
        sort(begin(nums), end(nums));
        
        vector<vector<int>> res;
        for(int i = 0; i < size - 2; i++){
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if(nums[i] + nums[size - 1] + nums[size - 2] < 0) continue;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = size - 1;
            while(l < r){
                if(nums[l] + nums[r] == -nums[i]){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[++l]);
                    while(r > l && nums[r] == nums[--r]);
                }
                else if(nums[l] + nums[r] > -nums[i]) r--;
                else l++;
            }
        }
        return res;
    }
};
