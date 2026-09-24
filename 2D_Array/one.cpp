#include <iostream>
#include <vector>
using namespace std;

// int main(){
//     //1d array
//     // int arr[5] = {1, 2, 3, 4, 5}

//     //2d array
//     int matrix[4][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
//     int rows = 4;
//     int cols = 3;

//     matrix[2][1] = 18;  // we ca change the values

//     cout << matrix[2][1] << endl;
//     return 0;
// }

// print elements of matrix
// int main() {
//     int matrix[4][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
//     int rows = 4;
//     int cols = 3;

//     for(int i=0; i<rows; i++) {
//         for(int j=0; j<cols; j++){
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     return 0;
// }

// print by take input 
// int main() {
//     int matrix[4][3];
//     int rows = 4;
//     int cols = 3;

//     //input
//     for(int i=0; i<rows; i++) {
//         for(int j=0; j<cols; j++){
//             cin >> matrix[i][j];
//         }
//     }

//     //output
//     for(int i=0; i<rows; i++) {
//         for(int j=0; j<cols; j++){
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     return 0;
// }


// Linear search in 2d array

// bool linearSearch(int mat[][3], int rows, int cols, int key) { // we dont need to pass rows but it neccessary to pass coloumns
//     for(int i=0; i<rows; i++) {
//         for(int j=0; j<cols; j++){
//             if( mat[i][j] == key){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main() {
//     int matrix[4][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
//     int rows = 4;
//     int cols = 3;

//     cout << linearSearch(matrix, rows, cols, 8) << endl;

//     return 0;
// }

// return ans in for of pair


// pair<int, int> linearSearch(int mat[][3], int rows, int cols, int key) { // we dont need to pass rows but it neccessary to pass coloumns
//     for(int i=0; i<rows; i++) {
//         for(int j=0; j<cols; j++){
//             if( mat[i][j] == key){
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

// int main() {
//     int matrix[4][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
//     int rows = 4;
//     int cols = 3;

//     pair<int, int> ans = linearSearch(matrix, rows, cols, 8);

//     cout << ans.first << " " << ans.second << endl;

//     return 0;
// }


// Maximum row sum

// int getMaxSum(int mat[][3], int rows, int cols){
//     int maxRowSum = INT_MIN;

//     for(int i=0; i<rows; i++){
//         int rowSumI = 0;
//         for(int j=0; j<cols; j++){
//             rowSumI += mat[i][j];
//         }
//         maxRowSum = max(maxRowSum, rowSumI);
//     }

//     return maxRowSum;
// }

// int getMaxSum(int mat[][3], int rows, int cols) {  //  maximum coloumn sum;
//     int maxColumnSum = INT_MIN;

//     for(int j = 0; j < cols; j++) {
//         int columnSum = 0;

//         for(int i = 0; i < rows; i++) {
//             columnSum += mat[i][j];
//         }

//         maxColumnSum = max(maxColumnSum, columnSum);
//     }

//     return maxColumnSum;
// }

// int main() {
//     int matrix[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     int rows = 3;
//     int cols = 3;

//     cout << getMaxSum(matrix, rows, cols) << endl;

//     return 0;
// }


// Sum of diagonal elements

// int diagonalSum(int mat[][4], int n) { //TC = O(n^2)
//     int sum = 0;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             if(i == j){
//                 sum += mat[i][j];
//             } else if(j == n-i-1) {
//                 sum += mat[i][j];
//             }
//         }
//     }

//     return sum;
// }

// int diagonalSum(int mat[][4], int n) {
//     int sum = 0;

//     //pd : j = i
//     // sd : j = n-i-1

//     for(int i=0; i<n; i++) {
//         sum += mat[i][i];
//         if(i != n-i-1) {  // condition for common elements
//             sum += mat[i][n-i-1];
//         }
//     }

//     return sum;
// }

// int main() {
//     int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
//     int n = 4;

//     cout << diagonalSum(matrix, n) << endl;
// }



// 2D Vector

// int main() {
//     vector<vector<int>> mat = {{1, 2 ,3}, {4, 5, 6},{7, 8, 9}};

//     // cout << mat[0][0];
//     for(int i=0; i<3; i++) {
//         for(int j=0; j<3; j++) {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

int main() {
    vector<vector<int>> mat = {{1, 2 ,3}, {4, 5, 6, 10, 11},{7, 8, 9}};

    // rows => mat.size()
    // cols => mat[i].size()
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}