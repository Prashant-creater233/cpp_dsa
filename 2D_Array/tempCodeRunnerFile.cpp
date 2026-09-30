
//     return 0;
// }


// Sum of diagonal elements

int diagonalSum(int mat[][4], int n) { //TC = O(n^2)
    int sum = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i = j) {
                sum += mat[i][j];