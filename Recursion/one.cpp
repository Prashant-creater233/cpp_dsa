#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void printNums(int n) { // recursive function
//     if(n == 1) {
//         cout << "1\n";
//         return;
//     }
    
//     cout << n << " "; // n, n-1, n-2,....to 1
//     printNums(n-1);
// }

// int main() {
//     printNums(4);

//     return 0;
// }


// find factorial

// int factorial(int n) {
//     if(n == 0) {
//         return 1;
//     }

//     return n * factorial(n-1);
// }

// int main() {
//     cout << factorial(4) << endl;
//     return 0;
// }


// sum of n numbers (recursion)

// int sum(int n) {
//     if(n == 1) {
//         return 1;
//     } 

//     return n + sum(n-1);
// }

// int main() {

//     cout << sum(4) << endl;

//     return 0;
// }


// Check if array is sorted

// bool isSorted(vector<int> arr, int n){
//     if(n == 0 || n == 1) {
//         re                                                                                               

//     return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
// }

// int main(){
//     vector<int> arr = {1, 2, 8, 4, 5};

//     cout << isSorted(arr, arr.size());

//     return 0;
// }


// Print subsets using recursion

// void printSubsets(vector<int> &arr, vector<int> &ans, int i) {   // & ans matlab original ans me hi changes honge copy nhi bnagi
//     if(i == arr.size()) {
//         for(int val: ans){
//             cout << val << " ";
//         }
//         cout << endl;
//         return;
//     }

//     // include
//     ans.push_back(arr[i]);
//     printSubsets(arr, ans , i+1);

//     ans.pop_back(); //backtracking
//     //exclude
//     printSubsets(arr, ans, i+1);
// }

// int main() {
//     vector<int> arr = {1, 2, 3};

//     vector<int> ans;  //store subsets
//     printSubsets(arr, ans, 0);
//     return 0;
// }


// Print all the permutations of string

#include <iostream>
using namespace std;

void permutation(string &s, int idx) {

    // Base case
    if(idx == s.size()) {
        cout << s << endl;
        return;
    }

    // Try every character at current position
    for(int i = idx; i < s.size(); i++) {

        swap(s[idx], s[i]);

        permutation(s, idx + 1);

        // Backtracking
        swap(s[idx], s[i]);
    }
}

int main() {
    string s = "abc";

    permutation(s, 0);

    return 0;
}