#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 7};
    int x = 4;

    auto it = lower_bound(arr.begin(), arr.end(), x);

    cout << "Lower Bound Index: " << it - arr.begin();
    return 0;
}