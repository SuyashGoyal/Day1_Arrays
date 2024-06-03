/*
Leetcode : #75 {https://leetcode.com/problems/sort-colors/description/}

Given an integer array nums, in which exactly two elements appear 
only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and 
uses only constant extra space.

Important Logic: 
Dutch National Flag Algorithm : 3 way partitioning | 1-pass
The algorithm was desinged to sort an array containing only 0s, 1s & 2s.

Algorithm Working:
Maintain 3 pointers: low mid & high
low  : array beginning
mid  : array begining and moves through it
high : array ending

Intuition: keep all the 0s before 'low'
           keep all the 2s after 'high'
           move 'mid' through the array, comparing the value at each position with 1
                if value = 0
                    swap curr with element at 'low'
                    increment 'low', 'mid'
                if value = 2
                    swap curr with element at 'high'
                    decrement 'high'
                if value = 1
                    increment 'mid'

Algorithm Termination: 
            when 'mid' crosses 'high'
            => all elements have been processed and the array sorted

sorts the array in a single pass through the elements. T.C: O(n)
                
*/


#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while (mid <= high)
        {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++; mid++;
            } else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if(nums[mid] == 1) {
                mid++;
            }
        }
    }
};