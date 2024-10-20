#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    
    if (n % 2 != 0) {
        cout << "Queue size must be even." << endl;
        return;
    }
    
    queue<int> firstHalf;
    int halfSize = n / 2;
    for (int i = 0; i < halfSize; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); 
        firstHalf.pop();
        
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    interleaveQueue(q);
    
    cout << "Output: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}
