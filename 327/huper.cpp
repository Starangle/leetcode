class Solution {
public:

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> sum(len + 1, 0);
        for(int i = 0; i < len; ++i) sum[i + 1] = sum[i] + nums[i];
        return mergeSort(sum, lower, upper, 0, len + 1);
    }
    /*
     *
     * */
    int mergeSort(vector<long> &sum, int lower, int upper, int left, int right) {
        if(right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int m = mid, n = mid, count = 0;
        count = mergeSort(sum, lower, upper, left, mid) + mergeSort(sum, lower, upper, mid, right);
        for(int i = left; i < mid; i++)
        {
            // find the first m that satisfies sum[i, m] >= lower
            while(m < right && sum[m] - sum[i] < lower) m++;
            // find the first n that satisfies sum[i, n] > upper
            while(n < right && sum[n] - sum[i] <= upper) n++;
            count += n - m;
        }
        // inplace_merge(start, mid, end)，就地 归并[start, mid), [mid, end)两段区间，两段区间必须有序。
        inplace_merge(begin(sum) + left, begin(sum) + mid, begin(sum) + right);
        return count;
    }
    
    /*
    solution 2：
    multiset
    */
    // int countRangeSum(vector<int>& nums, int lower, int upper) {
    //     if(nums.size()==0)
    //         return 0;

    //     int count=0;
    //     multiset<long> sumSet;
    //     long sum=0;
    //     sumSet.insert(0);
    //     for(int i = 0;i < nums.size(); ++i)
    //     {
    //         sum += nums[i];
    //         multiset<long>::iterator itStart,itEnd;
    //         itStart = sumSet.lower_bound(sum - upper);
    //         itEnd = sumSet.upper_bound(sum - lower);
    //         count += distance(itStart,itEnd);
    //         sumSet.insert(sum);
    //     }
    //     return count;
    // }
};


