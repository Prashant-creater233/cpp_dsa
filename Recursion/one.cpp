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

int sum(int n) {
    if(n == 1) {
        return 1;
    } 

    return n + sum(n-1);
}

int main() {

    cout << sum(4) << endl;

    return 0;
}