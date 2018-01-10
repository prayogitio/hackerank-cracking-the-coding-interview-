#include <bits/stdc++.h>

using namespace std;

int n;

long merge(vector<int> &temp, int first, int mid, int last, vector<int> &arr) {
    int i = first;
    int j = mid+1;
    int k = first;
    long count = 0;
    while ((i <= mid) && (j <= last)) {
        if (temp[j] < temp[i]) {
            arr[k] = temp[j];
            count += mid + 1 - i;
            j++;
            k++;
        } else {
            arr[k] = temp[i];
            i++;
            k++;
        }
    }
    while (i <= mid) {
        arr[k] = temp[i];
        i++;
        k++;
    }
    while (j <= last) {
        arr[k] = temp[j];
        j++;
        k++;
    }  
    return count;
}

long merge_sort(vector<int> &arr, int first, int last, vector<int> &temp) {
    if (first == last) return 0;
    long count = 0;
    int mid = first + (last-first)/2;
    count += merge_sort(temp, first, mid, arr);
    count += merge_sort(temp, mid+1, last, arr);
    count += merge(arr, first, mid, last, temp);
    return count;
 
}

long countInversions(vector <int> &arr, vector<int> &temp) {
    return merge_sort(arr, 0, n-1, temp);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        cin >> n;
        vector<int> arr(n);
        arr.clear();
        vector<int> temp(n);
        temp.clear();
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
           temp[arr_i] = arr[arr_i];
        }
        long result = countInversions(arr,temp);
        cout << result << endl;
    }
    return 0;
}
