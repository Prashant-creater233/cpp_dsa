#include <iostream>
using namespace std;
// // agar ko kaam hma baar baar krana ha to ham function use krta ha

// //sum of two numbers
// int sum(int a, int b){
//     int c = a + b;
//     return c;
// }

// //min of two numbers
// int minOfTwo(int a, int b){
//     if(a<b){
//         return a;
//     } else{
//         return b;
//     }
// }

// //max of two numbers
// int maxOfTwo(int a, int b){ //parameters
//     if(a>b){
//         return a;
//     } else{
//         return b;
//     }
// }
// // calculate sum of 1to n numbers
// int sumOfN(int n){
//     int sum = 0;
//     for(int i = 1; i <= n; i++){
//         sum += i;
//     }
//     return sum;
// }

// // calculate N factorial
// int factorial(int n){
//     int fact = 1;
//     for(int i = 1; i <= n; i++){
//         fact *= i;
//     }
//     return fact;
// }

// int main(){
//     cout << sum(10, 5) << endl;
//     cout << "Minimum: " << minOfTwo(10, 5) << endl;
//     cout << "Maximum: " << maxOfTwo(10, 5) << endl; // arguments
//     cout << "Sum of N: " << sumOfN(10) << endl;
//     cout << "Sum of N: " << sumOfN(5) << endl;;
//     cout << "Factorial of 5: " << factorial(5) << endl;

//     return 0;
// }

// int sum(int a, int b){
//     a = a+10; // 15
//     b = b+10; // 14
//     return a+b; // 29
// }

// int main(){
//     int a = 5, b = 4;
//     cout << sum(a,b) << endl; //29
//     cout << a <<endl;
//     cout << b <<endl;
// }


// void changeX(int x){
//     x = 2*x;
//     cout << "x= " << x << endl;
// }

// int main(){
//     int x = 5;
//     changeX(x);
//     cout << "x= " << x << endl;
//     return 0;
// }


// sum of digits of a number
// int sumOfDigits(int num){
//     int digSum = 0;

//     while(num>0){
//         int lastDig = num % 10;
//         num /= 10;
//         digSum += lastDig;
//     }
//     return digSum;
// }

// int main(){
//     cout << "sum = " << sumOfDigits(2356) << endl;
// }


// cal nCr binomial coefficient
// int factorial(int n){
//     int fact = 1;
//     for(int i =1; i <=n; i++){
//         fact *= i;
//     } 
//     return fact;
// }

// int nCr(int n, int r){
//     int fact_n = factorial(n);
//     int fact_r = factorial(r);
//     int fact_n_r = factorial(n-r);
    
//     return fact_n / (fact_r * fact_n_r);
// }

// int main(){
//     int n = 5, r = 2;
//     cout << "nCr = " << nCr(n,r) << endl;
//     return 0;
// }

// print first n prime numbers
bool isPrime(int n){
    bool isPr = true;

    for(int i=2; i*i <= n; i++) {
        if(n % i == 0){
            isPr = false;
            break;
        }
    }

    

    return isPr;

}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << isPrime(n) << endl;

    if(isPrime(n) == true){
        cout << "prime no\n";
    } else {
        cout << "Non prime\n";
    }
    return 0;
}


// int main() {
//         string s = "LVIII";
//         unordered_map<char, int> mp;

//         mp['I'] = 1;
//         mp['V'] = 5;
//         mp['X'] = 10;
//         mp['L'] = 50;
//         mp['C'] = 100;
//         mp['D'] = 500;
//         mp['M'] = 1000;

//         int ans = 0;
//         for(int i=0; i<s.length(); i++) {
//             if(i+1 < s.length() && mp[s[i]] < mp[s[i+1]]) {
//                 ans -= mp[s[i]];
//             } else {
//                 ans += mp[s[i]];
//             }
//         }

//         cout << ans;
// }

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         int srow = 0, scol = 0, erow = m-1, ecol = n-1;
//         vector<int> ans;

//         while(srow <= erow && scol <= ecol) {
//             //top
//             for(int j=scol; j<=ecol; j++) {
//                 ans.push_back(mat[srow][j]);
//             }

//             //right
//             for(int i=srow+1; i<=erow; i++) {
//                 ans.push_back(mat[i][ecol]);
//             }

//             //bottom
//             for(int j = ecol-1; j >= scol; j--) {
//                 if(srow == erow) {
//                 break;
//                 }
//                 ans.push_back(mat[erow][j]);
//             }

//             //left
//             for(int i = erow-1; i >= srow+1; i--) {
//                 if(scol == ecol) {
//                     break;
//                 }
//                 ans.push_back(mat[i][scol]);
//             }

//             srow++; erow--; scol++; ecol--;

//         }

//         return ans;
//     }
// };
