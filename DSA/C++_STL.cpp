#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
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

int main(){
    map<string, int> m;

    m["tv"] = 100;
    m["laptop"] = 100;
    m["laptop"] = 300;
    m["headphones"] = 50;
    m["table"] = 120;
    m["watch"] = 50;

    m.insert({"camera", 25});
    m.emplace("glass", 40);
    m.erase("tv");

    for(auto p: m) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "count = " << m.count("laptop") << endl;
    cout << "laptop value = " << m["laptop"] << endl;

    if(m.find("camera") != m.end()){
        cout << "found\n";
    }else{
        cout << "Not found";
    }

   return 0;
}
