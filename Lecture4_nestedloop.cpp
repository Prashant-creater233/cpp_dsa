// Nested Loop
// square pattern 
#include <iostream>
using namespace std;

// int main() {
//     int n =4;

//     for(int i=1; i<=n; i++){

//         for(int j=1; j<=n; j++){
//             cout << j << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// int main() {
//     int n =4;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout << "* ";
//         }
//         cout << endl ;
//     }

//     return 0;
// }


// print upper same as charcter A B C D 

// int main() {
//     int n = 4;

//     for(int i=0; i<n; i++){
//         char ch = 'A';
//         for(int j=0; j<n; j++){
//             cout << ch << " ";
//             ch = ch +1;
//         }
//         cout << endl ;
//     }

//     return 0;
// }


int main(){
    int n=4;

    char ch='A';
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }

}


// int main() {
//     int n = 3;
//     int num = 1;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout << num << " ";
//             num++;
//         }
//         cout << endl ;
//     }

//     return 0;
// }

// practice as above 

// int main(){
//     int n = 5;

//     int nm = 1;
//     for(int i=0;i<n; i++){
//         for(int j =0; j<n; j++){
//             cout << nm << "  ";
//             nm++;
//         }
//         cout << endl ;
//     }
//     cout << "after pattern" << nm ;
//     return 0;
// }


// practice ques

// int main(){
//     int n = 3;
//     char ch = 'A';

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }
//     cout << "After Pattern : "  << ch ;
//     return 0;
// }


// Triangle Pattern

// int main() {
//     int n =6;
//      for(int i=0; i<n; i++){
//         for(int j=0; j<i+1; j++){
//             cout << "*" << " ";
//         }
//         cout << endl ;
//      }
//      return 0;
// }


// int main() {
//     int n =6;
//      for(int i=0; i<n; i++){
//         for(int j=0; j<i+1; j++){
//             cout << i+1 << " ";
//         }
//         cout << endl ;
//      }
//      return 0;
// }

// int main() {
//     int n =5;
//     char ch ='A';
//      for(int i=0; i<n; i++){
//         for(int j=0; j<i+1; j++){
//             cout << ch << " ";
//         }
//         cout << endl ;
//         ch++;
//      }
//      return 0;
// }


// int main() {
//     int n =5;

//     for(int i=0; i<n; i++){
//         for(int j=1; j<=i+1; j++) {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }


// Reverse Triangle
// int main() {
//     int n =5;

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j>0; j--){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// Floyd's Triangle pattern;

// int main() {
//     int n =5;
//     int num =1;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<i+1; j++){ // Forward
//             cout << num << " ";
//             num++;
//         }
//         cout << endl;
//     }
//     return 0;
// }


// int main() {
//     int n =5;
//     int num =1;

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j>0; j--){ // backward => i+1
//             cout << num << " ";
//             num++;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// practice 

// int main(){
//     int n=4;
//     char ch ='A';
//     for(int i=0;i<n;i++){
//         for(int j=0 ;j<i+1; j++){ // forward loop se charcter print
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// same as above but in backward loop
// int main(){
//     int n=4;
//     char ch ='A';
//     for(int i=0;i<n;i++){
//         for(int j=i+1; j>0; j--){ // backward loop
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }
//     return 0;
// }


//Most important 

// int main(){
//     int n=4;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j>0; j--){
//             cout << char('A' + j -1) << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }