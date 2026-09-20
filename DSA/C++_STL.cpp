#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// vector container

// int main(){
//     vector<int> vec;

//     vec.push_back(1);
//     vec.push_back(2);
//     vec.push_back(3);
//     vec.push_back(4);
//     vec.push_back(5);
//     vec.emplace_back(6);

//     vec.pop_back();
//     // cout << vec.size() << endl; //3
//     // cout << vec.capacity() << endl; //4

//     for(int val : vec){
//         cout << val << " ";
//     }
//     cout << endl;

//     cout << "val at idx 2 " << vec[2] << " or " << vec.at(2) << endl;

//     cout << "front " << vec.front() << endl;
//     cout << "back " << vec.back() << endl;

//     return 0;
// }

// int main()
// {
//     vector<int> vec1 = {1, 2, 3, 4, 5}; 
//     // vector<int> vec(10,-1); // dyanamic programming - tabulation DP[][]

//     vector<int> vec2(vec1);


//     for (int val : vec2){
//         cout << val << " ";
//     }
//     cout << endl;
// }

// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5}; 
    
//     // vec.erase(vec.begin());
//     // vec.erase(vec.begin() + 2);
//     // vec.erase(vec.begin()+1, vec.begin()+3);
//     // vec.insert(vec.begin() + 2 ,3);

//     vec.clear();

//     for (int val : vec){
//         cout << val << " ";
//     }
//     cout << endl;

//     cout << "size: " << vec.size() << endl;
//     cout << "cap: " << vec.capacity() << endl;
//     cout << "empty: " << vec.empty() << endl;

//     return 0;
// }


// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5}; 
  
//     cout << "vec.begin: " << *(vec.begin()) << endl;
//     cout << "end.begin: " << *(vec.end()) << endl;

//     return 0;
// }

// // vector iterator loop (forward iterator)
// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5}; 
  
//     vector<int>::iterator it;
//     for(it = vec.begin(); it != vec.end(); it++) {
//         cout << *(it) << " ";
//     }
//     cout << endl;

//     return 0;
// }

// vector iterator loop (backword iterator)
// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5}; 
  
//     // for(vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++) { // isko define krna ke bjay hm directly auto kr sakta ha
//     //     cout << *(it) << " ";
//     // }
//     for(auto it = vec.rbegin(); it != vec.rend(); it++) { // isko define krna ke bjay hm directly auto kr sakta ha auto use in both forword and backword
//         cout << *(it) << " ";
//     }
//     cout << endl;

//     return 0;
// }


// Pair

// int main(){
//     // pair<int, int> p = {1, 2}; 
//     // pair<string, int> p = {"prashant", 2}; 
//     pair<string, pair<char, int>> p = {"prashant", {'a',3}}; 
  
//     cout << p.first << endl;
//     cout << p.second.first << endl;
//     cout << p.second.second << endl;
//     return 0;
// }

//vector pair

// int main(){

//     vector<pair<int, int>> vec = {{1,2},{3, 4},{5, 6}};

//     vec.push_back({4, 5}); // insert
//     vec.emplace_back(6, 7); // not send object  in place object create
    
//     for(auto p : vec){
//         cout << p.first << " " << p.second << endl;
//     }
  
//     return 0;
// }

// queue

// int main(){
//     queue<int> q;

//     q.push(1);
//     q.push(2);
//     q.push(3);

//    while(!q.empty()){
//     cout << q.front() << " ";
//     q.pop();
//    }
//    cout << endl;
//    return 0;
// }

// priority queue
// queue priority wise greater is first the largest wise priority

// int main(){
//     // priority_queue<int> q;
//     priority_queue<int, vector<int>, greater<int>> q;  // for reverse order

//     q.push(5);
//     q.push(4);
//     q.push(10);
//     q.push(6);

//    while(!q.empty()){
//     cout << q.top() << " ";
//     q.pop();

//    }
//    cout << endl;
//    return 0;
// }


// Map

// int main(){
//     map<string, int> m;

//     m["tv"] = 100;
//     m["laptop"] = 100;
//     m["laptop"] = 300;
//     m["headphones"] = 50;
//     m["table"] = 120;
//     m["watch"] = 50;

//     m.insert({"camera", 25});
//     m.emplace("glass", 40);
//     m.erase("tv");

//     for(auto p: m) {
//         cout << p.first << " " << p.second << endl;
//     }

//     cout << "count = " << m.count("laptop") << endl;
//     cout << "laptop value = " << m["laptop"] << endl;

//     if(m.find("camera") != m.end()){
//         cout << "found\n";
//     }else{
//         cout << "Not found";
//     }

//    return 0;
// }


// multimap
// int main(){
//     multimap<string, int> m;

//     m.insert({"camera", 25});
//     m.emplace("glass", 40);
//     m.emplace("glass", 40);
//     m.emplace("glass", 40);
//     m.emplace("glass", 50);

//     //m.erase("glass"); // sari delete ho jayenge
//     m.erase(m.find("glass")); // ek tv delete hoga

//     for(auto p: m) {
//         cout << p.first << " " << p.second << endl;   
//     }
//    return 0;
// }


// // unordered map store in unordered way
// int main(){
//     unordered_map<string, int> m;

//     m.insert({"camera", 25});
//     m.emplace("glass", 40);
//     m.emplace("laptop", 140);
//     m.emplace("fridge", 100);
//     m.emplace("watch", 150);

//     for(auto p: m) {
//         cout << p.first << " " << p.second << endl;   
//     }
//    return 0;
// }



// set
// int main(){
//     set<int> s;

//     s.insert(1);
//     s.insert(2);
//     s.insert(3);
//     s.insert(4);
//     s.insert(5);

//     // s.insert(1);
//     // s.insert(2);
//     // s.insert(3);


//     cout << "lower bound = " << *(s.lower_bound(4)) << endl; //4 if 4 not in set 4 se just badi value 5 aata agar koi bhi badi value exit nhi krti to return s.end() return anyvalue we don't know
//     cout << "upper bound = " << *(s.upper_bound(4)) << endl; // 5 
//     for(auto val: s) {
//         cout << val << " ";
//     }
//     cout << endl;
//    return 0;
// }


// unordered set
// int main(){
//     unordered_set<int> s;

//     s.insert(1);
//     s.insert(2);
//     s.insert(3);
//     s.insert(4);
//     s.insert(5); 

//     s.insert(1);
//     s.insert(2);
//     s.insert(3);

//     for(auto val: s) {
//         cout << val << " ";
//     }
//     cout << endl;
//    return 0;
// }



// Algorithms
// 1 sort 

// int main(){
//     // int arr[5] =  {3, 5, 1, 8, 2};

//     // sort(arr, arr + 5);

//     // for(int val : arr) {
//     //     cout << val << " ";
//     // }
//     // cout << endl;

//     vector<int> vec =  {3, 5, 1, 8, 2};

//     // sort(vec.begin(), vec.end()); // ascending order
//     sort(vec.begin(), vec.end(), greater<int>()); // decendind order

//     for(int val : vec){
//         cout << val << " ";
//     }
//     cout << endl;
// }

// bool comparator(pair<int, int> p1, pair<int, int> p2) {
//     if(p1.second < p2.second) return true;
//     if(p1.second > p2.second) return false;

//     if(p1.first < p2.first) return true; // if second values equal so compare on the basis of first 
//     else return false;
// }

// int main(){

//     vector<pair<int, int>>  vec =  {{3, 1}, {2, 1}, {7, 1}, {5, 2}};

//     // sort(vec.begin(), vec.end());
//     sort(vec.begin(), vec.end(), comparator); //in ascending acc to second value

//     for(auto p : vec){
//         cout << p.first << " " << p.second << endl;  // sort in ascending on the basis of first value but if i want to arrange acc to second value so we want to make custom comparator
//     }
//     cout << endl;
// }


// Reverse Algorithm

// int main(){

//     vector<int>  vec =  {1, 2, 3, 4, 5};

//     // reverse(vec.begin(), vec.end()); 
//     reverse(vec.begin()+1, vec.begin()+3); 

//     for(auto val : vec){
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Next Permutation we also covered in last file sorting

// int main(){
//     // string s = "abc";
//     string s1 = "acb";
//     // next_permutation(s.begin(), s.end()); 
//     prev_permutation(s1.begin(), s1.end()); 

//     cout << s1 << endl;

//     // min max function
//     cout << max(4, 5) << " " << min(6, 10) << endl;

//     // swap function
//     int a =5, b=10;
//     swap(a, b);
//     cout << "a = " << a << endl;

//     return 0;
// }



int main(){
    // vector<int> vec = {1, 2, 3, 4, 5};

    // cout << *(max_element(vec.begin(), vec.end())) << endl;
    // cout << *(min_element(vec.begin(), vec.end())) << endl;
    // cout << binary_search(vec.begin(), vec.end(), 4) << endl;

    int n = 15;
    long int n2 = 15;
    long long int n3 = 15;

    cout << __builtin_popcount(n) << endl;
    cout << __builtin_popcountl(n2) << endl;
    cout << __builtin_popcount(n3) << endl;

    return 0;
}