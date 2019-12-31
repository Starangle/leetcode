class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }

            for(int item : nums) {
                cout << item << "   ";
            }
            cout << endl;
        }

        for(int i = 0; i < len; ++i) {
            if(nums[i] != i + 1)
                return i + 1;

        }
        return len + 1;
    }
};
