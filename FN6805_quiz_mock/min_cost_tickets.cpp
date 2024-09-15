// You have planned some train traveling one year in advance. The days of the year in 

//which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 
//2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

int mincostTickets(vector<int>& DAYS, vector<int>& cost) {
        
        unordered_set<int> days(DAYS.begin(),DAYS.end());
        vector<int> dp(367);
        
        for(int i=1 ; i<366 ; i++)
        {
            dp[i] = dp[i-1];
            if(days.find(i) != days.end())
            {
			// cost of ith day , decision of ith day will be
                dp[i] = min({ dp[i - 1] + cost[0],   // 1st case
                             dp[max(0, i - 7)] + cost[1],  // 2nd case
                             dp[max(0, i - 30)] + cost[2]});  // 3rd case
            }
        }
        return dp[365];
    }




/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



*/


void elementSum(vector<int>&candidates,vector<vector<int>>&res,vector<int>&elements,int target ,int begin){
        if(!target){
            res.push_back(elements); return;
        }
        for(int i=begin;i<candidates.size() && candidates[i] <= target ;i++){
            elements.push_back(candidates[i]);
            elementSum(candidates,res,elements,target-candidates[i],i);
            elements.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>elements;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        elementSum(candidates,res,elements,target,0);
        return res;
    }
