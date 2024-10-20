#include <iostream>
#include <stack>

using namespace std;

// 插入元素到栈底的函数
void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(topElement);
}

// 使用递归反转栈的函数
void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topElement);
}

// 打印栈中元素的函数
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(31);
    s.push(30);
    s.push(29);
    s.push(28);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
