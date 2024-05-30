/*
Leetcode : #53 {https://leetcode.com/problems/maximum-subarray/description/}

Kadane's Algorithm : to find the max. subarray sum

I/P : [5, 4, -1, 7, 8]
O/P : 23 //here the entire array will be the largest subarray

Find the subarray with the largest sum and return its sum.
Logic: Divide & Conquer

Approach : Apply Kadane's ALgorithm 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int localSum = 0; 
        int sum = INT_MIN;

        for(int i = 0; i < n; i++) {
            localSum += nums[i];
            sum = max(sum, localSum);
            if(localSum < 0)
                localSum = 0;
        }
        return sum;
    }
};