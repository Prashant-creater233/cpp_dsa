#include <iostream>
#include <climits>
using namespace std;

// int main(){
//     int marks[5] = {99, 100, 54, 36, 88};
//     marks[0] = 101;
//     cout << marks[0] << endl ;
//     cout << marks[1] << endl ;
//     cout << marks[2] << endl ;
//     cout << marks[3] << endl ;
//     cout << marks[4] << endl ;

//     return 0;
// }

// int main(){
//     int size = 5;
//     int marks[size];

//     for(int i=0; i<size; i++){
//         cin >> marks[i];
//     }

//     //loops : 0 to size-1
//     for(int i=0; i<size; i++){
//         cout << marks[i] << endl;
//     }
//     return 0;
// }


// find smallest and largest in Array

// int main(){  // find smallest no in array
//     int nums[] = {5,15,22,1,-15,-24};
//     int size = 6;

//     int smallest = INT_MAX;

//     for(int i=0; i<size; i++){
             
//         // if(nums[i] < smallest){ // 1st method 
//         //     smallest = nums[i];
//         // }
//         smallest = min(nums[i], smallest);
//     }

//     cout << "Smallest = " << smallest << endl;
//     return 0;
// }

// for largest 
// int main(){
//     int larg[] = {3,87,767,45,67,90};
//     int size = 6;

//     int largest = INT_MIN;

//     int largeIndex = 0;

//     for(int i=0; i<size; i++){
//         // if(larg[i] > largest){  // 1st method
//         //     largest = larg[i];
//         // }

//         largest = max(larg[i], largest);  // 2nd method in one line

//         if(larg[i] > larg[largeIndex]){ // find largest value at which index
//             largeIndex = i;
//         }
//     }

//     cout << "Largest = " << largest << endl;
//     cout << "LargeIndex = " << largeIndex << endl;

//     return 0;
// }

// pass by reference
 
// void changeArr(int arr[], int size){
//     cout << "in function\n";
//     for(int i=0; i<size; i++){
//         arr[i] = 2*arr[i];
//     }
// }

// int main(){
//     int arr[] = {1, 2, 3};

//     changeArr(arr, 3);

//     cout << "in main\n";
//     for(int i=0; i<3; i++){
//         cout << arr[i] << " "; 
//     }
//     cout << endl;
    
//     return 0;
// }


// Linear Search

int linearSearch(int arr[], int size, int target) {
    for(int i=0; i<size; i++){
        if(arr[i] == target){  // FOUND
            return i;
        }
    }

    return -1;  // indicate NOT FOUND
}

int main(){
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int size = 7;

    int target = 8;

    cout << linearSearch(arr, size , target) << endl;

    return 0;
}


// Reverse of a Array

// void reverseArr(int arr[], int size){
//     int start = 0 , end = size-1;

//     while(start < end){
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// int main(){
//     int arr[] = {4, 2, 7, 8, 1, 2, 5};
//     int size = 7;

//     reverseArr(arr, size);

//     for(int i=0; i<size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Practice questions
// 1 WAP to calculate sum & product of all numbers in array

// int  main(){
//     int arr[]={2, 6, 8, 10, 4};
//     int size = 5;

//     int sum=0;
//     for(int i=0; i<size; i++){ //sum
//         sum += arr[i];
//     }

//     int prod = 1;
//     for(int i=0; i<size; i++){ //product
//         prod *= arr[i];
//     }

//     cout << sum << endl;
//     cout << prod << endl;
// }

// 2 WAP to swap the max & min number of array

// int main() {
//     int arr[] = {2, 6, 8, 10, 4};
//     int size = 5;

//     int maxx = 0;

//     for(int i = 0; i < size; i++) {
//         if(arr[i] > arr[maxx]) {
//             maxx = i;
//         }
//     }

//     int minn = 0;

//     for(int i = 0; i < size; i++) {
//         if(arr[i] < arr[minn]) {
//             minn = i;
//         }
//     }

//     swap(arr[maxx], arr[minn]);

//     for(int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// 3 WAP to print all the unique values in an array..

// int main(){
//     int arr[]= {1,2,5,3,1,2,3,4,6};
//     int size = 9;

//     for(int i=0; i<size; i++){
//         int count=0;

//         for(int j=0; j<size; j++){
//             if(arr[i] == arr[j]){
//                 count++;
//             }
//         }

//         if(count == 1){
//             cout << arr[i] << " ";
//         }
//     }

//     return 0;
// }


//WAF to print intersection of 2 arrays

