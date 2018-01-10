#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    //bubble sort
    int num_swap = 0;
    bool isThereSwap = true;
    for (int i = 0; i < n && isThereSwap == true; i++) {
        isThereSwap = false;
        for (int j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                num_swap++;
                isThereSwap = true;
            }
        }
    }
    printf("Array is sorted in %d swaps.\n",num_swap);
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d\n", a[n-1]);
    return 0;
}
