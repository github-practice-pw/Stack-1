/*
 *                  Next Greater Element II
 *
 * Leetcode : https://leetcode.com/problems/next-greater-element-ii/description/
 * 
 * Time complexity : O(3N)
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
    vector<int> brute_force(vector<int>& nums) {     
        int n = nums.size();
        vector<int> result(n , -1);

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                int idx = (i+j)%n; // Next index
                if (nums[idx] > nums[i]) {
                    result[i] = nums[idx];
                    break;
                }
            }
        }
        return result;

    }

    // Optimized approach : Using monotonic stack
    // TC : O(3N) and SC : O(N)
    vector<int> dailyTemperaturesStack(vector<int>& nums) { 
        int n = nums.size();

        stack<int> s;
        vector<int> result(n, -1);

        for(int i = 0; i < 2*n; i++) {
            while(!s.empty() && nums[s.top()] < nums[i % n]) {
                result[s.top()] = nums[i%n];
                s.pop();
            }

            if (i < n) {
                s.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> nums = {1,2,3,4,3};

    // Test brute-force approach
    vector<int> result_brute_force = sol.brute_force(nums);
    cout << "Brute Force Result: ";
    for (int num : result_brute_force) {
        cout << num << " ";
    }
    cout << endl;

    // Test optimized approach using monotonic stack
    vector<int> result_stack = sol.dailyTemperaturesStack(nums);
    cout << "Optimized Stack Result: ";
    for (int num : result_stack) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
