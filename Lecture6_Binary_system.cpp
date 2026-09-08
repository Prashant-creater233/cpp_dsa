#include <iostream>
using namespace std;

// // decimal to binary conversion function
// int decToBinary(int decNum){
//     int ans = 0, pow = 1; //pow -> 10^0

//     while(decNum > 0){
//         int rem = decNum % 2;
//         decNum /= 2;
//         ans += rem * pow;
//         pow *= 10;
//     }
//     return ans;
// }

// int main(){
//     int decNum = 50;
//     cout << decToBinary(decNum) << endl;
//     for(int i =1; i<=10; i++){
//         cout << decToBinary(i) << endl;
//     }
//     return 0;
// }


// binary to decimal conversion function
// int BinaryToDecimal(int binaryNum){
//     int ans = 0, pow = 1; //pow -> 2^0
    
//     while(binaryNum > 0){
//         int rem = binaryNum % 10;
//         ans += rem * pow;

//         binaryNum /= 10;
//         pow *= 2;
//     }
//     return ans;  //decimal form
// }

// int main(){

//     cout << BinaryToDecimal(101) << endl;
//     return 0;
// }