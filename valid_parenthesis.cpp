/*
 *                  Valid Parenthesis
 *
 * Leetcode : https://leetcode.com/problems/valid-parentheses/description/
 * 
 * Time complexity : O(N)
 * Space complexity : O(N)
 * Did this code successfully run on Leetcode : Yes
 * Any problem you faced while coding this : -
 * Your code here along with comments explaining your approach in three sentences only
 *          - Using stack, comparing the elements of the string with top most
 *            char of the stack and pop the elements. At the end if the stack is empty we 
 *            can return true
 */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    // Optimized approach : Using monotonic stack
    // TC : O(N) and SC : O(N)
    bool isValid(string s) { 
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '{') {
                st.push('}');
            } else if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << "Test 1: " << sol.isValid(test1) << endl; // Expected: true (1)
    cout << "Test 2: " << sol.isValid(test2) << endl; // Expected: true (1)
    cout << "Test 3: " << sol.isValid(test3) << endl; // Expected: false (0)
    cout << "Test 4: " << sol.isValid(test4) << endl; // Expected: false (0)
    cout << "Test 5: " << sol.isValid(test5) << endl; // Expected: true (1)

    return 0;
}