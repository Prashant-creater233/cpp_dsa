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

double knapsack01_Rec(vector<vector<int>>& items, int W, int n) {
    if(n == 0 || W == 0) {
        return 0;
    }

    int val = items[n-1][0];
    int wt = items[n-1][1];

    if(wt <= W) {
        int include = val + knapsack01_Rec(items, W-wt, n-1);
        int exclude = knapsack01_Rec(items, W, n-1);
        return max(include, exclude);
    } else {
        return knapsack01_Rec(items, W, n-1);
    }
}

int main() {
    vector<vector<int>> items = {
        {20, 2},
        {30 ,3},
        {50, 4},
        {60, 5},
        {100, 9}
    }; // val, wt

    int W = 10;

    cout << knapsack01_Rec(items, W, items.size()) << endl;

    return 0;
}