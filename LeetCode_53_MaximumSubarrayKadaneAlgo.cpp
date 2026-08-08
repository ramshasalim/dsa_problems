class Solution {
public:
int maxSubArray(vector<int>& nums) {

// maxi = best subarray sum found so far
int maxi=INT_MIN;

// curr_sum = sum of the current subarray
int curr_sum=0;

for(int i:nums){

// Add the current number to our current subarray
curr_sum+=i;

// Check if the current subarray gives us a new maximum
maxi=max(curr_sum,maxi);

// If the current sum becomes negative,
// keeping this subarray would only hurt future sums.
// So start a new subarray from the next element.
if(curr_sum<0){
curr_sum=0;
}
}

// Return the largest sum found
return maxi;

/*
Concept: Kadane's Algorithm

Keep adding elements to curr_sum.
If curr_sum becomes negative, discard it and start fresh.

Why?
A negative sum can only decrease the sum of any future
subarray, so there is no reason to carry it forward.

Example:
[-2,1,-3,4,-1,2,1,-5,4]

Best subarray:
[4,-1,2,1] = 6

Time: O(n)  -> one pass
Space: O(1)  -> only a few variables
*/
}
};
