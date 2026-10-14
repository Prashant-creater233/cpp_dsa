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

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 7};
    int x = 4;

    auto it = upper_bound(arr.begin(), arr.end(), x);

    cout << "Upper Bound Index: " << it - arr.begin();
    return 0;
}

int binarySearch(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

vector<int> searchRange(vector<int>& arr, int x) {
    int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if (first == arr.size() || arr[first] != x)
        return {-1, -1};

    int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;

    return {first, last};
}

void reverseArray(vector<int>& arr) {
    int i = 0, j = arr.size() - 1;

    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}