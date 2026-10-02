#include <iostream>
#include <vector>
using namespace std;


// Raze in a Maze

// void helper()



// vector<string> findPath(vector<vector<int>> &mat){}

// int main() {
//     vector<vector<int>> mat = {{1, 0 , 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

//     vector<string> ans = findPath(mat);
//     for(string path : ans) {
//         cout << path << endl;
//     }
// }




// Merge Sort (recursive)

// void merge(vector<int> &arr, int st, int mid, int end){ //O(n)
//     vector<int> temp;
//     int i = st, j = mid+1;
//     while(i <= mid && j<=end){
//         if(arr[i] <= arr[j]){   //  agar hma decending order me sort krna hota to yha pe >= use krte
//             temp.push_back(arr[i]);
//             i++;
//         } else {
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }

//     while(i <= mid){
//         temp.push_back(arr[i]);
//         i++;
//     }

//     while(j <= end){
//         temp.push_back(arr[j]);
//         j++;
//     }

//     for(int idx=0; idx<temp.size(); idx++){
//         arr[st + idx] = temp[idx];
//     }
    
// }

// void mergeSort(vector<int> &arr, int st, int end){
//     if(st < end){
//         int mid = st + (end - st) / 2;

//         mergeSort(arr, st, mid); //left half
//         mergeSort(arr, mid + 1, end); // right half

//         merge(arr, st, mid, end);
//     }
// }


// int main(){
//     vector<int> arr {12, 31, 35, 8, 32, 17};

//     mergeSort(arr,0, arr.size()-1);

//     for(int val : arr){
//         cout << val << " ";
//     }

//     return 0;
// }


// Quick Sort ( recursive)

int partition(vector<int> &arr, int st, int end){
    int idx = st-1, pivot = arr[end];
    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){ // decending order me sort krna hota to yha pe >= use krte
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st < end) {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx-1); // left half

        quickSort(arr, pivIdx+1, end); // right half
    }
}

int main(){
    vector<int> arr {12, 31, 35, 8, 32, 17};

    quickSort(arr,0, arr.size()-1);

    for(int val : arr){
        cout << val << " ";
    }

    return 0;
}