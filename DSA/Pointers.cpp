#include <iostream>
#include <vector>
using namespace std;

// int main(){
//     // int a = 10;
//     // int* ptr = &a;

//     // cout << ptr << endl;
//     // cout << &a << endl;

//     // float price = 100.25;
//     // float* ptr = &price;

//     // cout << ptr << endl;
//     // cout << &price << endl;
//     // cout << &ptr << endl;

//     return 0;
// }


// Pinter to Pointer
// int main(){
//     int a = 10;
//     int* ptr = &a;

//     int** parPtr = &ptr;

//     cout << &ptr << endl;
//     cout << parPtr << endl;

//     return 0;
// }


//Dereference operator (*)
//  int main(){
//     // int a = 10;
//     // int* ptr = &a;

//     // cout << *(&a) << endl;
//     // cout << *(ptr) << endl;

//     int a = 10;
//     int* ptr = &a;

//     int** parPtr = &ptr;

//     cout << *(parPtr) << endl;
//     cout << ptr << endl;

//     cout << **(parPtr) << endl;


//     return 0;
// }


// Null pointer

//  int main(){
//     int** ptr = NULL;

//     cout << *ptr << endl;

//     return 0;
// }

// void changeA(int* ptr){
//     *ptr = 20;
// }

// int main(){
//     int a = 10;

//     changeA(&a);

//     cout << "inside main function : " << a << endl; // 20

//     return 0;
// }


// pass by references by alias

// void changeA(int &b){ // pass by refernces using alias
//     b = 20;
// }

// int main(){
//     int a = 10;

//     changeA(a);

//     cout << "inside main function : " << a << endl; // 20

//     return 0;
// }

// Array pointer

// int main(){
//     int arr[] = {1,2,3,4,5};

//     cout << arr << endl;
//     cout << *arr << endl;

//     return 0;
// }

// int main(){
//     int arr[] = {1,2,3,4,5};

//     int a=15;
//     // arr = &a; // constant jisse ham throghout the program kabhi change nhi kr sakte

//     return 0;
// }

// increment and decrement 

// int main(){
//     int a = 10;
//     int* ptr = &a;

//     // cout << ptr << endl;
//     // ptr++;
//     // cout << ptr << endl; // +4

//     cout << ptr << endl;
//     ptr = ptr + 2; // 2int => 8 Bytes
//     cout << ptr << endl; // +8

//     return 0;
// }

// int main(){
//     int arr[] = {1,2,3,4,5};

//     cout << *arr << endl; //1
//     cout << *(arr+1) << endl;//2
//     cout << *(arr+2) << endl;//3
//     cout << *(arr+3) << endl;//4

//     return 0;
// }


int main(){
    int arr[] = {1,2,3,4,5};

    // subtract two pointer 
    // int* ptr2; //100
    // int* ptr1 = ptr2 + 2; // 108
    // cout << ptr1 - ptr2 << endl; // 2


    // comapre pointer
    int* ptr1;
    int* ptr2;

    cout << ptr1 << endl;
    cout << ptr2 << endl;

    cout << (ptr1 > ptr2) << endl;

    return 0;
}