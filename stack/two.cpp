#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// int main() {
//     //stock prices
//     vector<int> price = {100, 80, 60, 70, 60, 75, 85};

//     //solution
//     vector<int> ans(price.size(), 0);
//     stack<int> s;

//     for(int i=0; i<price.size(); i++) {
//         while(s.size() > 0 && price[s.top()] <= price[i]) {
//             s.pop();
//         }

//         if(s.size() == 0) {
//             ans[i] = i+1;
//         } else {
//             ans[i] = i - s.top(); // i - prevHigh
//         }

//         s.push(i);
//     }

//     for(int val : ans) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }


// Next Greater Element

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};

    //Next Greater Element
    stack<int> s;
    vector<int> ans(arr.size(), 0);
    int n = arr.size();

    for(int i=n-1; i>=0; i--) {
        while(s.size() > 0 && s.top() <= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}