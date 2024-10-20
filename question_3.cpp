#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k) {
    queue<int> negatives; // Queue to store negative numbers' indices
    vector<int> result;   // Vector to store the result

    // Process the first window of size k
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negatives.push(i); // Store index of negative number
        }
    }

    // Traverse through the rest of the array
    for (int i = k; i <= n; i++) {
        // Check if we have a negative number in the queue for the current window
        if (!negatives.empty()) {
            result.push_back(arr[negatives.front()]);
        } else {
            result.push_back(0);
        }

        // Remove the elements that are out of this window
        if (!negatives.empty() && negatives.front() <= i - k) {
            negatives.pop();
        }

        // Add the next element if it is negative
        if (i < n && arr[i] < 0) {
            negatives.push(i);
        }
    }

    // Print the result
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
