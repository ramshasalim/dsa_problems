
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int m=matrix.size();
if (matrix.empty()) return false; // no elements to search

int n=matrix[0].size();

// We treat the whole matrix like one sorted array
// Example: 1 3 5 7 | 10 11 16 20 | 23 30 34 60
int l=0;
int e=(m*n)-1; // last index of this imaginary 1D array

while(l<=e){
int mid = l+(e-l)/2;

// mid is a 1D index, so convert it to row and column
// mid/n = row
// mid%n = column
if(matrix[mid/n][mid%n]==target){
return true;
}
else if(matrix[mid/n][mid%n]>target){
// middle element is bigger than target
// so search on the left side
e=mid-1;
}
else{
// middle element is smaller than target
// so search on the right side
l=mid+1;
}

}


// target was not found
return false;

}

};