/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (79.80%)
 * Likes:    9036
 * Dislikes: 341
 * Total Accepted:    446.3K
 * Total Submissions: 559.3K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part.
 * 
 * Note that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be s.
 * 
 * Return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "eccbbbbdec"
 * Output: [10]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i = 0; i < s.size(); ++i)
        {
            m[s[i]] = i;
        }
        vector<int> res;

        int maxi = m[s[0]];
        int prev = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            maxi = max(maxi,m[s[i]]);
            if(maxi == i)
            {
                res.push_back(maxi-prev);
                prev = maxi;
            }
        }
        return res;
    }
};
// @lc code=end

