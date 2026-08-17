class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();

        // Store {value, original index}
        // We need the original indices in the final answer
        vector<pair<int,int>>narr;
        for(int i=0;i<n;i++){
            narr.push_back({nums[i],i});
        }

        // Sort by value so that we can use two pointers
        sort(narr.begin(),narr.end());
        
        
        // l starts from the smallest value
        // e starts from the largest value
        int l=0;
        int e=n-1;

        while(l<=e){

            // Check the sum of the two current values
            if(narr[l].first+narr[e].first==target){
                
                // .second contains the original index
                return {narr[l].second,narr[e].second};
            }

            // Sum is too large → move the right pointer left
            // This gives us a smaller value
            else if(narr[l].first+narr[e].first>target){
                e--;
            }

            // Sum is too small → move the left pointer right
            // This gives us a larger value
            else{
                l++;
            }
        }

        // No pair found
        return{};

        /*
        Concept:
        Sort the elements and use two pointers.

        Smallest + Largest:
        - Sum too large → decrease the largest
        - Sum too small → increase the smallest
        - Sum equal to target → answer found

        IMPORTANT:
        We store {value, original index} because sorting changes
        the order of the elements, but the answer requires
        the original indices.

        Example:
        nums = [2,7,11,15], target = 9

        After sorting:
        [2,7,11,15]

        2 + 15 = 17 → too large → move right
        2 + 11 = 13 → too large → move right
        2 + 7  = 9  → found

        Return the ORIGINAL indices: [0,1]

        Time Complexity:
        Creating pairs → O(n)
        Sorting        → O(n log n)
        Two pointers   → O(n)

        Total          → O(n + n log n + n)
                       → O(n log n)

        Space Complexity:
        O(n) → extra vector of pairs is used.
        */
    }
};
