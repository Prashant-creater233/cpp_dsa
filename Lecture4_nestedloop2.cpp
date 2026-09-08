#include <iostream>
using namespace std;
// Inverted Triangle Pattern (Reverse number)

// int main(){
//     int n=4;

//     int num= 1;
//     for(int i=0; i<n; i++){
//         //Spaces
//         for(int j=0; j<i; j++){
//             cout << " ";
//         }

//         //nums
//         for(int j=0; j<n-i; j++){
//             cout << (i+1);
//         }
//         cout << endl;
//     }
//     return 0;
// }

// now same for characters

// int main(){
//     int n=4;

//     char cht= 'A';
//     for(int i=0; i<n; i++){
//         //Spaces
//         for(int j=0; j<i; j++){
//             cout << " ";
//         }

//         //nums
//         for(int j=0; j<n-i; j++){
//             cout << cht;
//         }
//         cht++;
//         cout << endl;
//     }
//     return 0;
// }

// Pyramid Pattern (Numbers)  important
// int main(){
//     int n =8 ;

//     for(int i=0; i<n; i++){
//         //Spaces
//         for(int j=0; j<n-i-1; j++){
//             cout << " ";
//         }

//         //nums1
//         for(int j=1; j<=i+1; j++){
//             cout << j;
//         }

//         // nums2
//         for(int j=i; j>0; j--){
//             cout <<  j;
//         }

//         cout << endl;
//     }
//     return 0;
// }

// Hollow Diamond Pattern (Numbers)  important

// int main()
// {

//     int n = 4;

//     // top
//     for (int i = 0; i < n; i++)
//     {
//         // Spaces
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         cout << "*";

//         if (i != 0)
//         {
//             // Spaces
//             for (int j = 0; j < 2 * i - 1; j++)
//             {
//                 cout << " ";
//             }
//             cout << "*";
//         }

//         cout << endl;
//     }
//     // bottom
//     for (int i = 0; i < n - 1; i++)
//     {
//         // spaces
//         for (int j = 0; j < i + 1; j++)
//         {
//             cout << " ";
//         }
//         cout << "*";

//         // spaces
//         if (i != n - 2)
//         {
//             for (int j = 0; j < 2 * (n - i) - 5; j++)
//             {
//                 cout << " ";
//             }
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// Butterfly Pattern (Numbers)  important

int main(){
    //top
    int n=4;
    for(int i=0; i<n; i++){
        //Left stars
        for(int j=0; j<i+1; j++){
            cout << "*";
        }

        // Spaces
        if(i!=n-1){
            for(int j=0; j<2*(n-i-1); j++){
                cout << " ";
            }
        }

        //Right stars
        for(int j=0; j<i+1; j++){
            cout << "*";
        }

        cout << endl;
    }
    // bottom
    for(int i=0; i<n; i++){
        //Left stars
        for(int j=0; j<n-i; j++){
            cout << "*";
        }
        //spaces
        if(i!=0){
            for(int j=0; j<n+2*(i-2); j++){
                cout << " ";
            }
        }
        //Right stars
        for(int j=0; j<n-i; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}