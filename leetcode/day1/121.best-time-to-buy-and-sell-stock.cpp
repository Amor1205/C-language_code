/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (54.30%)
 * Likes:    22584
 * Dislikes: 709
 * Total Accepted:    3M
 * Total Submissions: 5.5M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int>> &v)
    {
        //if we have no stock or we have no chance of transaction(k=0)
        if(i>=prices.size()||k<=0) return 0;
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy)  //if we are buying then next time we will sell else next time we will buy
        {        //-prices[i], because bought stock of prices[i], expend money
            
           return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v)); 
        }
        else    //it's time to sell , now decrease k, we have done 1 transaction
        {       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
           return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(); 
        vector<vector<int>> v(n,vector<int> (2,-1));
        //passing here buy=1 because we will first buy then sell
        //we can do atmost k=1 transaction
        return find(prices,0,1,1,v);
    }
};
// @lc code=end

