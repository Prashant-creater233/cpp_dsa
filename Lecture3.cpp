// Conditional Statement

#include <iostream>
using namespace std;

// int main(){
//     int age;
//     cout << "enter age : ";
//     cin >> age ;

//     if(age >= 18){
//         cout << "you can vote\n";
//     } else{
//         cout << "you cannt vote\n";
//     }
// }

// int main(){
//     int n;
//     cout << "enter number : ";
//     cin >> n ;

//     if(n%2 == 0){
//         cout << "even number\n";
//     } else{
//         cout << "odd number\n";
//     }
// }


// int main(){
//     int mar ;
//     cout << "enter marks : ";
//     cin >> mar ;

//     if(mar >= 90){
//         cout << "A\n";
//     } else if(mar >= 80 && mar<90){
//         cout << "B\n";
//     } else{
//         cout << "C\n";
//     }
//     return 0;
// }

// lowercase or uppercase

int main(){
    char ch;
    cout << "enter char: ";
    cin >> ch;

    if(ch>= 'a' && ch<= 'z'){
        cout << "lowercase\n";
    } else {
        cout << "uppercase\n";
    }
    return 0;
}

//Ternary operator

// int main(){
//     int n = 45;

//     cout << (n >= 0 ? "Positive" : "Negative") << endl;
//     cout << (n <30? "Yes" : "NO") << endl;
//     return 0;
// }