class Solution {
public:
/*
solution 1:
积分法：
将每个位置可积累的雨水累加起来。
*/
    // int trap(vector<int>& height) {
    //     int len = height.size();
    //     vector<int> left(len + 1, 0);
    //     vector<int> right(len + 1, 0);
    //     int res = 0;
    //     int leftMax = 0, rightMax = 0;
    //     for(int i = 1; i < len; ++i) {
    //         leftMax = left[i] = max(leftMax, height[i - 1]);
    //     }
    //     for(int i = len - 2; i >= 0; --i) {
    //         rightMax = right[i] = max(rightMax, height[i + 1]);
    //     }
    //     for(int i = 0; i < len; ++i) res += max(min(left[i], right[i]) - height[i], 0);
    //     return res;
    // }

    /*
    将上述方法空间从O(2n) ----> O(1)
    */
    // int trap(vector<int>& height) {
    //     int size = height.size();
    //     int left = 0, right = size - 1;
    //     int leftMax = 0, rightMax = 0;
    //     int res = 0;
    //     /*
    //     一个直观的感受是：
    //     无论是从左向右还是从右向左遍历，只有发生降序的时候才能累计雨水。
    //     发生降序累计雨水的前提是另一边有一个比这边所有数都大的bound(所以我们只更新当前height小的一边)
    //     */

    //     while(left < right) {
    //         if(height[left] < height[right]){
    //             // 更新左最大值
    //             if(leftMax < height[left]) leftMax = height[left];
    //             // 产生降序，累计雨水
    //             else res += leftMax - height[left];
    //             left++;
    //         }
    //         else {
    //             if(rightMax < height[right]) rightMax = height[right];
    //             else res += rightMax - height[right];
    //             right--;
    //         }
    //     }
        
    //     return res;
    // }

    /*
    类似单调栈的逻辑，栈保存index
    以升序或者降序保存数，不满足升序和降序的时候循环进行结算，直到栈内继续完全满足升序或者降序。
    */
    int trap (vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        // 遍历数组
        while (current < height.size()) {
            /*
            降序 + bound 可以引发蓄水，所以遇到降序直接如栈，遇到升序循环进行结算。
            */
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                    
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};