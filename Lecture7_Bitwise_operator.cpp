#include <iostream>
using namespace std;

// int main(){
//     int a = 4, b = 8;
//     cout << (a & b) << endl; // bitwise AND
//     cout << (a | b) << endl; // bitwise OR
//     cout << (a ^ b) << endl; // bitwise XOR

//     cout << (10 << 2) << endl; // left shift operator, 10 in binary is 1010, shifting left by 2 gives 101000 which is 40 in decimal
//     cout << (10 >> 1) << endl; // right shift operator, 10 in binary is 1010, shifting right by 1 gives 101 which is 5 in decimal
// }

// Local scope
// int main(){
//     if(3>1){

//     }else{
//         int x = 10;
//     }
//     // cout << x << endl; // This will cause an error because x is not in scope here(local scope)
//     return 0;
// }

// int x = 10; // global variable

// void fun(){
//     cout << x << endl; // This will print 10 because x is a global variable
// }

// int main(){
//     fun();
//     cout << x << endl; // This will also print 10 because x is a global variable
//     return 0;
// }


// Data tyoe modifiers
// int main(){
//     cout << sizeof(int) << endl; // 4 bytes
//     cout<< sizeof(long int) << endl; // 4 bytes
//     cout<< sizeof(long long int) << endl; // 8 bytes
//     cout<< sizeof(short int) << endl; // 2 bytes

//     unsigned int a = 10; // unsigned int can only store positive values
//     cout << a << endl;

//     unsigned int b = -10; // unsigned int cannot store negative values, so it will wrap around and store a large positive value instead


//     cout << b << endl; 
// }


// wAF to reverse of an integer number
// int main(){
//     int num, reversed = 0;
//     cout << "Enter an integer: ";
//     cin >> num;

//     while(num != 0){
//         int digit = num % 10; // get the last digit
//         reversed = reversed * 10 + digit; // append the digit to the reversed number
//         num /= 10; // remove the last digit from num
//     }

//     cout << "Reversed number: " << reversed << endl;
//     return 0;
// }