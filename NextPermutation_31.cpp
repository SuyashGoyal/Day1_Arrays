/*
Leetcode : #31 {https://leetcode.com/problems/next-permutation/description/}

I/P : [1, 2, 3]  |  I/P : [3, 2, 1]  |  I/P :  [1, 1, 5]
O/P : [1, 3, 2]  |  O/P : [1, 2, 3]  |  O/P :  [1, 5, 1]

i.e Return the next permutation of the set of elements
Next Lexicographically greater permutation of it's integer
Edge Case:
If such an arrangement is not possible, array must be rearranged in the lowest possible order
Logic : 2 pointers

Approach I: Brute Force T.C : O(n! * n  +  n! log n!  +  n!); S.C : O(n!)
    Generate all possible subsets using recursion and store them in a vector "all_permutations"
    Sort the vector "all_permutations"
    Do Linear Search to find the next greater element

Approach II: Optimal Approach T.C : O()
    Since we need to find the just greater number, moving from Right->Left
    we need to look for the smallest change in the number, so moving from 1s
    breaking point: curr < prev
    after encountering the break point, check for the next largest element than the ith element in the right part
    swap the elements
    sort the right part in ascending order to make it the smallest number

Approach III: Using STL 
    next_permutation(nums.begin(), nums.end)
    return nums;
*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;     
        //step 1
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        //step 2
        for(int i = n-1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }     
        //step 3
        reverse(nums.begin() + idx + 1, nums.end());
        
    }
};