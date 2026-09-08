#include <iostream>
#include <vector>
using namespace std;

// int main(){
//     // vector<char> vec = {'a','b','c','d','e'};
//     vector<int> vec;

//     vec.push_back(25);
//     vec.push_back(35);
//     vec.push_back(55);

//     cout << "Size = " << vec.size() << endl;

//     vec.pop_back();

//     // for(int val : vec){  // for each loop
//     //     cout << val << endl;
//     // }

//     cout << vec.front() << endl;
//     cout << vec.back() << endl;
//     cout << vec.at(0) << endl;
//     return 0;
// }

// int main(){
//     vector<int> vec;

//     vec.push_back(0);
//     vec.push_back(1);
//     vec.push_back(2);
//     vec.push_back(3);
//     vec.push_back(4);

//     cout << vec.size() << endl;
//     cout << vec.capacity() << endl;
//     return 0;
// }

// Linaer search as vector 
// int linear_search(vector<int> arr, int size, int target){
//     for(int i=0; i< size; i++){
//         if(arr[i] == target){  // FOUND
//             return i;
//         }
//     }

//     return -1;  // indicate NOT FOUND
// }

// int main(){
//     vector<int> arr = {10,20,30,40,50};
//     int target = 50;
//     int size = 5;

//     int result = linear_search(arr, size, target);

//     cout << result;

//     return 0;
// }

// reverse of an vector
// void reverseArr(vector<int>& arr, int size){
//     int start = 0 , end = size-1;

//     while(start < end){
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// int main(){
//     vector<int> arr = {4, 2, 7, 8, 1, 2, 5};
//     int size = 7;

//     reverseArr(arr, size);

//     for(int i=0; i<size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }



// Subarray (print all posible subarrays)

// int main(){
//     int n =5;
//     int arr[5] = {1, 2, 3, 4, 5};

//     for(int st=0; st<n; st++){
//         for(int end=st; end<n; end++){
//             for(int i=st; i<=end; i++){
//                 cout << arr[i];
//             }
//             cout << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// Maximum Subarray Sum;  (By Brute Force Approach )
// int main(){
//     int n =5;
//     int arr[5]={1,2,3,4,5};
//     int maxSum = INT_MIN;

//     for(int st=0; st<n; st++){
//         int curSum =0;

//         for(int end=st; end<n; end++){
//             curSum += arr[end];
//             maxSum = max(curSum, maxSum);
//         }
//     }
//     cout << "max subarray sum = " << maxSum << endl;
// }



//Pair sum

// int main(){
//     vector<int> nums = {2,7,11,15};
//     int target= 9;
//     int ans=0;
//     int n = 4;
    
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(nums[i] + nums[j] == target){
//                 ans;
//             }
//         }
//     }
//     return 0;
// }




// pair sum by optimizal approach

vector<int> pairSum(vector<int> nums, int target) {
    vector<int> ans;
    int n = nums.size();

    int i=0 , j = n-1;

    while(i < j){
        int pairSum = nums[i] + nums[j];

        if(pairSum > target) {
            j--;
        } else if(pairSum < target){
            i++;
        } else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    vector<int> ans = pairSum(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}