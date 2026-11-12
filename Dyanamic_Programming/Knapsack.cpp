#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// static bool compare(vector<int>& a, vector<int>& b) {
//     double a1 = (1.0 * a[0]) / a[1];
//     double b1 = (1.0 * b[0]) / b[1];

//     return a1 > b1;
// }

// double fractionalKnapsack(vector<vector<int>>& items, int K) {

//     sort(items.begin(), items.end(), compare);

//     double maxVal = 0.0;

//     for(auto& item : items) {

//         int val = item[0];
//         int wt = item[1];

//         if(wt <= K) {
//             maxVal += val;
//             K -= wt;
//         }
//         else {
//             maxVal += ((double)val / wt) * K;
//             break;
//         }
//     }

//     return maxVal;
// }

// int main() {

//     vector<vector<int>> items = { //370
//         {60, 10},
//         {100, 20},
//         {120, 30},
//         {80, 40},
//         {150, 15}
//     };

//     int K = 60;

//     cout << fractionalKnapsack(items, K) << endl;

//     return 0;
// }




// 0/1 Knapsack (brute-force) from recursion

// double knapsack01_Rec(vector<vector<int>>& items, int W, int n) {
//     if(n == 0 || W == 0) {
//         return 0;
//     }

//     int val = items[n-1][0];
//     int wt = items[n-1][1];

//     if(wt <= W) {
//         int include = val + knapsack01_Rec(items, W-wt, n-1);
//         int exclude = knapsack01_Rec(items, W, n-1);
//         return max(include, exclude);
//     } else {
//         return knapsack01_Rec(items, W, n-1);
//     }
// }

// int main() {
//     vector<vector<int>> items = {
//         {20, 2},
//         {30 ,3},
//         {50, 4},
//         {60, 5},
//         {100, 9}
//     }; // val, wt

//     int W = 10;

//     cout << knapsack01_Rec(items, W, items.size()) << endl;

//     return 0;
// }


// 0/1 knapsack by memoization


// int knapsack01_MemoDP(vector<vector<int>>& items, int W, int n,
//                       vector<vector<int>>& dp) {

//     // Base case
//     if(n == 0 || W == 0) {
//         return 0;
//     }

//     // Already calculated
//     if(dp[n][W] != -1) {
//         return dp[n][W];
//     }

//     int val = items[n-1][0];
//     int wt = items[n-1][1];

//     // Include or exclude
//     if(wt <= W) {

//         int include = val + knapsack01_MemoDP(items, W-wt, n-1, dp);

//         int exclude = knapsack01_MemoDP(items, W, n-1, dp);

//         return dp[n][W] = max(include, exclude);
//     }

//     // Cannot include
//     return dp[n][W] = knapsack01_MemoDP(items, W, n-1, dp);
// }

// int main() {

//     vector<vector<int>> items = {
//         {20, 2},
//         {30, 3},
//         {50, 4},
//         {60, 5},
//         {100, 9}
//     };

//     int W = 10;
//     int n = items.size();

//     vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

//     cout << knapsack01_MemoDP(items, W, n, dp) << endl;

//     return 0;
// }



// Tabulation Solution


int knapsack01_TabDP(vector<vector<int>>& items, int W, int n) {

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= W; j++) {

            int val = items[i-1][0];
            int wt = items[i-1][1];

            if(wt <= j) {
                dp[i][j] = max(
                    val + dp[i-1][j-wt],
                    dp[i-1][j]
                );
            } 
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {

    vector<vector<int>> items = {
        {20, 2},
        {30, 3},
        {50, 4},
        {60, 5},
        {100, 9}
    };

    int W = 10;
    int n = items.size();

    cout << knapsack01_TabDP(items, W, n) << endl;

    return 0;
}
