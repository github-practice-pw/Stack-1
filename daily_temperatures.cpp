/*
 *                  Daily temperatures
 *
 * Leetcode : https://leetcode.com/problems/daily-temperatures/description/
 * 
 * Time complexity : O(2N)
 * Space complexity : O(N)
 * Did this code successfully run on Leetcode : Yes
 * Any problem you faced while coding this : -
 * Your code here along with comments explaining your approach in three sentences only
 *          - Using monotonic stack, comparing the elements of the array with top most
 *            element of the stack and updating the result array.
 */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    // Brute force approach : 
    // TC : O(N^2) and SC : O(1)
    vector<int> dailyTemperatures(vector<int>& nums) {     
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }

    // Optimized approach : Using monotonic stack
    // TC : O(2N) and SC : O(N)
    vector<int> dailyTemperaturesStack(vector<int>& nums) { 
        vector<int> ans(nums.size(), 0);
        stack<int> s;

        for(int i = 0; i < nums.size(); i++) {
            while(!s.empty() && nums[i] > nums[s.top()]) {
                int idx = s.top();
                s.pop();
                ans[idx] = i - idx;
            }
            s.push(i);
        }
        return ans;
    }
};
