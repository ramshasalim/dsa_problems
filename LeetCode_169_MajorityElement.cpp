class Solution {
public:
int majorityElement(vector<int>& nums) {

// ans = current candidate for majority element
// count = how strong the candidate currently is
int ans=0;
int count=0;

for(int n:nums)
{
    
// If count becomes 0, the previous candidate
// has been cancelled out, so choose the current number
// as the new candidate
if(count==0){
ans=n;
}

// Same number as candidate → increase its count
// Different number → decrease its count
if(n==ans){
count++;
}else{
count--;
}

}

/*
Concept: Boyer-Moore Voting Algorithm

Think of every different number as cancelling each other out.

Example:
[2,2,1,1,1,2,2]

2 → count 1
2 → count 2
1 → count 1
1 → count 0
1 → new candidate, count 1
2 → count 0
2 → new candidate, count 1

The majority element appears more than n/2 times,
so it cannot be completely cancelled out.
Therefore, the final candidate is the majority element.

Time: O(n) → one pass through the array
Space: O(1) → only candidate and count are stored
*/

return ans;

}
};
