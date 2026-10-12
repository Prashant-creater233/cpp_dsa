// print number 1 to 5
//While Loop
#include <iostream>
using namespace std;

// int main(){
//     int n = 20;
//     int count = 1;

//     while(count<=n){
//         cout << count << " "; // \n in " " string use line by lene hoge ek line me print nhi hoga
//         count++;
//     }
//     cout << endl;
//     return 0;
// }

// int main(){
//     int n=10;
//     int count=1;
//     while(count<=n){
//         cout << count << " \n";
//         count+=2;
//     }
//     cout << endl;
//     return 0;
// }

//For Loop

// int main(){
//     int n = 3;

//     for(int i=1; i<=n; i++) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }

// calculate sum of numbers 1 to n

// int main(){
//     int n = 10;
//     int sum =0;

//     for(int i=1; i<=n; i++) {
//         sum += i;
//         if(i== 5){
//             break;
//         }
//     }
//     cout << "sum = " << sum << endl;
//     return 0;
// }


// calculate sum of numbers 1 to n odd number

// int main(){
//     int n;
//     cout << "enter number : ";
//     cin >> n ;
//     int oddSum = 0;
//     for(int i= 1; i<=n; i++){
//         if(i%2 != 0){
//             oddSum += i;
//         }
//     }
//     cout << "OddSum = " << oddSum << endl;

    // while loop  error aa rha ha
    // int n = 5;
    // int oddSum = 0;

    // while(n>0){
    //     if(n%2 != 0){
    //         oddSum += n;
            
    //     }
    //     n--;
    // }
    // cout << "oddSum" << oddSum << endl;
    // return 0;
// }


// do while loop

// int main() {
//     int n = 10;
//     int i = 1;

//     do {
//         cout << i << " " ;
//         i++;
//     } while(i <= n);
//     return 0;
// }

// check if number is prime or not



// int main() {
//     int n = 7;
//     bool isPrime = true;

//     for(int i=2; i< n-1; i++) {
//         if(n % 2 == 0){
//             isPrime = false;
//             break;
//         }
//     }

//     if(isPrime == true){
//         cout << "prime no\n";
//     } else {
//         cout << "Non prime\n";
//     }

//     return 0;
// }


// int main() {
//     int n = 14;
//     bool isPrime = true;

//     for(int i=2; i*i <= n; i++) {
//         if(n % 2 == 0){
//             isPrime = false;
//             break;
//         }
//     }

//     if(isPrime == true){
//         cout << "prime no\n";
//     } else {
//         cout << "Non prime\n";
//     }

//     return 0;
// }


// Nested loop

// int main(){
//     int n = 10;
//     for(int i=1 ; i<=n; i++) {
//         int m = 20;
//         for(int j=1; j<=m; j++){
//             cout << "*" ;
//         }
//         cout << endl;
//     }
//     return 0;
// }



// sum of all number from 1 to N are divisible by 3
// int main(){
//     int n = 20;
//     int sum = 0;
//     for(int i=1 ;i<=n; i++){
//         if(i % 3 ==0){
//             sum +=i;
//         }
//     }
//     cout << sum << endl;
//     return 0;
// }


// print factorial of a number

// int main(){
//     int n = 4;
//     int fact = 1;
//     for(int i=1 ;i<=n; i++){
//         fact = fact*i ;
//     }
//     cout << fact << endl;
//     return 0;
// }

