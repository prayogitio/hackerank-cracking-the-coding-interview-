#include <bits/stdc++.h>

using namespace std;

map<int,int> set;

void solve(vector<int> arr, vector <int> sorted_arr, int money) {
    bool found = false;
    int first, second;
    for (int i = 0; i < sorted_arr.size()-1 && found == false; i++) {
        first = sorted_arr[i];
        second = money-first;
        int lo = i + 1;
        int hi = sorted_arr.size()-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (second == sorted_arr[mid]) {
                found = true;
                break;
            }
            if (second < sorted_arr[mid])
                hi = mid - 1;
            else lo = mid + 1;
        }
    }
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == first || arr[i] == second)
            res.push_back(i+1);
    }
    printf("%d %d\n", res[0], res[1]);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> sorted_arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
           sorted_arr[arr_i] = arr[arr_i]; 
        }
        sort(sorted_arr.begin(), sorted_arr.begin() + n);
        solve(arr, sorted_arr, money);
    }
    return 0;
}
