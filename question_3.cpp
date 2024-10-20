#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k) {
    queue<int> negatives; 
    vector<int> result; 

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negatives.push(i); 
        }
    }

    for (int i = k; i <= n; i++) {
        if (!negatives.empty()) {
            result.push_back(arr[negatives.front()]);
        } else {
            result.push_back(0);
        }

        if (!negatives.empty() && negatives.front() <= i - k) {
            negatives.pop();
        }

        if (i < n && arr[i] < 0) {
            negatives.push(i);
        }
    }

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printFirstNegativeInteger(arr, n, k);

    return 0;
}
