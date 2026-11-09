#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//fibonacci Recursion code
// int fib(int n) {
//     if(n <= 1) {
//         return n;
//     }

//     return fib(n-1) + fib(n-2);
// }

//fibonacci DP code -- Memoization (recursion)
int fibDP(int n, vector<int> &f) {
    if(n <= 1) {
        return n;
    }

    if(f[n] != -1) {
        return f[n];
    }

    return f[n] = fibDP(n-1, f) + fibDP(n-2, f);
}


//fibonacci DP code -- Tabulation (iterative)
int fibTabDP(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// int main() {
//     int n = 6;
//     vector<int> f(n+1, -1);
//     // cout << fib(n) << endl;
//     // cout << fibDP(n, f) << endl;
//     cout << fibTabDP(n) << endl;

//     return 0;
// }



// Frog Jump Problem DP


// int minCost(vector<int> &height) {  // O(n)  but SC = O(n)
//     int n = height.size();

//     if(n == 1) return 0;

//     vector<int> dp(n); // dp[i] => min cost to reach last stair i

//     dp[0] = 0;
//     dp[1] = abs(height[1] - height[0]);

//     for(int i=2; i<n; i++) {
//         int jump1 = dp[i-1] + abs(height[i] - height[i-1]);
//         int jump2 = dp[i-2] + abs(height[i] - height[i-2]);
//         dp[i] = min(jump1, jump2);
//     }

//     return dp[n-1];
// }

int minCost(vector<int> &height) {  // TC = O(n)  but SC = O(1)
    int n = height.size();

    if(n == 1) return 0;

    int prev1 = 0;
    int prev2 = abs(height[1] - height[0]);
    int result = prev2;

    for(int i=2; i<n; i++) {
        int jump1 = prev2 + abs(height[i] - height[i-1]);
        int jump2 = prev1 + abs(height[i] - height[i-2]);

        result = min(jump1, jump2);

        prev1 = prev2;
        prev2 = result;
    }

    return result;
}

int main() {
    vector<int> height = {30, 20, 50, 10, 40}; // 30

    cout << minCost(height) << endl;

    return 0;
}