#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_one, stack_two;   
        void push(int x) {
            stack_one.push(x);
        }

        void pop() {
            if (stack_one.empty() && stack_two.empty())
                return;
            if (stack_two.empty()) {
                while (!stack_one.empty()) {
                    stack_two.push(stack_one.top());
                    stack_one.pop();
                }
            }
            stack_two.pop();
        }

        int front() {
            if (stack_two.empty()) {
                while (!stack_one.empty()) {
                    stack_two.push(stack_one.top());
                    stack_one.pop();
                }
            }
            return stack_two.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
