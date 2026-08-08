class Solution {
public:
void sortColors(vector<int>& nums) {

// l = position where the next 0 should go
// h = position where the next 2 should go
// mid = element currently being checked
int n=nums.size();
int l=0;
int h=n-1;
int mid=0;

while(mid<=h){

// 2 belongs at the right side
// Swap it with h and move h left
// Don't increase mid because the swapped element still needs to be checked
if(nums[mid]==2){
swap(nums[mid], nums[h]);
h--;
}

// 0 belongs at the left side
// Swap it with l and move both pointers forward
else if(nums[mid]==0){
swap(nums[mid],nums[l]);
l++;
mid++;
}

// If it is 1, it is already in the correct middle section
else{
mid++;
}

}

/*
Concept:
We divide the array into 3 sections:

0s | 1s | unknown | 2s
    l       mid      h

l    -> boundary for 0s
mid  -> current element
h    -> boundary for 2s

0 → move to left
1 → leave it, move mid
2 → move to right

Time: O(n)  -> each element is processed at most a few times
Space: O(1) -> sorting is done in-place
*/
}
};
