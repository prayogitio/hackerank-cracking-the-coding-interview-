#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
 
priority_queue<int> max_heap_left; 
priority_queue<int,vector<int>,greater<int>> min_heap_right;
void calculate_median(double x,double &median) {
    if (max_heap_left.size() > min_heap_right.size()) {
        if (x < median) {
            min_heap_right.push(max_heap_left.top());
            max_heap_left.pop();
            max_heap_left.push(x);
        }
        else
            min_heap_right.push(x);
        median = ((double)max_heap_left.top()
                +(double)min_heap_right.top())/2.0;
    }
    else if (max_heap_left.size()==min_heap_right.size()) {
        if (x < median) {
            max_heap_left.push(x);
            median = (double)max_heap_left.top();
        } else {
            min_heap_right.push(x);
            median = (double)min_heap_right.top();
        }
    }
    else {
        if (x > median) {
            max_heap_left.push(min_heap_right.top());
            min_heap_right.pop();
            min_heap_right.push(x);
        } else
            max_heap_left.push(x);
        median = ((double)max_heap_left.top()
                 + (double)min_heap_right.top())/2.0;
    }
}

int main() {   
    int n;
    cin >> n;
    vector<double> arr(n);
    double median = 0;     
    for (int i = 0; i < n; i++) {   
    	cin >> arr[i];
        calculate_median(arr[i], median);
        cout << setprecision(1) << fixed << median << endl;
    }
    return 0;
}