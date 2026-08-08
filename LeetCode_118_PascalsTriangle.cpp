class Solution {
public:
vector<vector<int>> generate(int numRows) {
vector<vector<int>> ans;

// We build Pascal's Triangle row by row
// Each new row depends on the row directly above it
for(int i=0;i<numRows;i++){

vector<int> arr;

// Row i has exactly i+1 elements
for(int j=0;j<=i;j++){

// The first and last element of every row are always 1
if(j==0||j==i){
arr.push_back(1);

}
else{
// Every middle element is the sum of the 2 elements above it
// ans[i-1][j-1] -> upper-left
// ans[i-1][j]   -> upper-right
arr.push_back(ans[i-1][j-1]+ans[i-1][j]);

}

}

// Once the row is complete, add it to the triangle
ans.push_back(arr);

}

// Return the complete Pascal's Triangle
return ans;

}
};
