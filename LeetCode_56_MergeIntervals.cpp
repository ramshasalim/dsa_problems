class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // If there are no intervals, there is nothing to merge
        if (intervals.empty()) {
            return {};
        }

        // Sort intervals by starting point
        // Example: [1,3], [2,6], [8,10]
        sort(intervals.begin(),intervals.end());

        int n=intervals.size();

        // Store the merged intervals
        vector<vector<int>> arr;
        arr.push_back(intervals[0]);

        for(int i=1;i<n;i++){

            // If current interval overlaps with the last merged interval,
            // merge them by extending the ending point
            if(arr.back()[1]>=intervals[i][0]){ 

                // Take the larger ending point
                // Example: [3,10] + [9,6]
                // Overlap exists because 10 >= 9
                // New ending point = max(10,6) = 10
                //
                // This is important because the current interval's
                // ending point might be smaller than the previous one.
                arr.back()[1]=max(arr.back()[1],intervals[i][1]);
            }

            else{
                // No overlap, so keep the current interval separately
                arr.push_back(intervals[i]);
            }
        }

        return arr;

        /*
        Concept:
        1. Sort intervals by starting point.
        2. Compare each interval with the last merged interval.
        3. If they overlap -> merge them.
        4. If they don't overlap -> add a new interval.

        Key condition:
        arr.back()[1] >= intervals[i][0]

        Example:
        [3,10] and [9,6]
        Since 10 >= 9, they overlap.
        Ending point = max(10,6) = 10.

        Time Complexity:

        Sorting       → O(n log n)
        Merging loop  → O(n)

        Total         → O(n log n + n)
                      → O(n log n)

        Space Complexity:
        O(n) → result array stores the merged intervals.
        */
    }
};
