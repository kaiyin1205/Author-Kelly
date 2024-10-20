#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) {
    stack<int> s;
    int nge[n];
    
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    int n;
    cout << "Please enter how many numbers you will input: ";
    cin >> n; 
    int arr[n];

    cout << "Please input " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printNGE(arr, n);

    return 0;
}
