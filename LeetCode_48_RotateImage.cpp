class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
int n = matrix.size();

/*
Concept:
To rotate the matrix 90° clockwise:

1. Transpose the matrix
   → rows become columns

2. Reverse every row
   → gives the final 90° clockwise rotation

Example:

1 2 3        1 4 7        7 4 1
4 5 6   →    2 5 8   →    8 5 2
7 8 9        3 6 9        9 6 3
 original      transpose     rotate
*/

// Transpose the matrix
// Swap elements across the main diagonal
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){

// Only swap the upper triangle.
// If we swap everything, each pair would be swapped twice.
if(j>i){
swap(matrix[i][j],matrix[j][i]);
}
}
}

// Reverse each row
// After transposing + reversing rows, the matrix is rotated 90° clockwise.
for(int i=0;i<n;i++){
reverse(matrix[i].begin(), matrix[i].end());
}

}
};
