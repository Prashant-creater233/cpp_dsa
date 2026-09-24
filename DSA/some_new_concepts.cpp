#include <iostream>
#include <algorithm>
using namespace std;


//Prime or not
// string isPrime(int n) {
//     for(int i=2; i*i <= n; i++){
//         if((n % i) == 0) {
//             return "Non Prime";
//         }
//     }
//     return "Prime";
// }

// int main(){
//     int n = 47;

//     cout << isPrime(n) << endl;
//     return 0;
// }

// print digits
// void printDigits(int n){
//     while(n != 0){
//         int digit = n % 10;
//         cout <<digit << endl;

//         n = n/10;
//     }
// }

// count of digits
// void printDigits(int n){
//     int count = 0;

//     while(n != 0){
//         int digit = n % 10;
//         count++;

//         n = n/10;
//     }
//     cout << count << endl;
// }

// sum of digits  time complexity O(logn) with base 10
// void printDigits(int n){
//     int sum = 0;

//     while(n != 0){
//         int digit = n % 10;
//         sum += digit;

//         n = n/10;
//     }
//     cout << sum << endl;
// }

// int main(){
//     int n = 3568;

//     // printDigits(n);

//     //shortcut to print digits
//     cout << (int)(log10(n) + 1) << endl;
//     return 0;
// }


// Armstrong Number

// bool isArmstrong(int n) {
//     int copyN = n;
//     int sumOfCubes = 0;

//     while(n != 0){
//         int dig = n % 10;
//         sumOfCubes += (dig*dig*dig);

//         n = n/10;
//     }

//     return sumOfCubes == copyN;
// }

// int main() {
//     int n = 153;

//     if(isArmstrong(n)){
//         cout << "is an armstrong number\n";
//     } else{
//         cout << "not an armstrong number\n";
//     }
//     return 0;
// }


// Find GCD OR HCF using most optize approch using ( EUCLID'S ALGORITHM)

// int gcd(int a, int b){
//     while( a > 0 && b > 0){
//         if(a > b){
//             a = a % b;
//         } else{
//             b = b % a;
//         }
//     }

//     if(a == 0) return b;
//     return a;
// }

// // by recursion

// int gcdRec(int a, int b){ // we assume a is always greater number
//     if(b == 0) return a;

//     return gcdRec(b, a % b); // this is condition a > b so a is always greater than b
// }


// int lcm(int a, int b){
//     int gcd = gcdRec(a, b);
//     return (a*b) / gcd;
// }


// int main(){
//     cout << gcd(20, 28) << endl;
//     cout << gcdRec(6, 12) << endl; // by recursion
//     cout << lcm(20, 28) << endl;
//     return 0;
// }



// raverse of number
class Solution {
public:
    int reverse(int n) {
        int revNum = 0;
        while(n != 0) {
            int dig = n%10;

            revNum = revNum * 10 + dig;
            n = n/10;
        }

        return revNum;
    }
};