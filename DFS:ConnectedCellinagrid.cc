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

int count_region(vector<vector<int>> &grid, int i, int j);
int n, m;

int get_biggest_region(vector< vector<int> > &grid) {
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maximum = max(maximum, count_region(grid, i ,j));
        }
    }
    return maximum;
}

int count_region(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return 0;
    if (grid[i][j] == 0)
        return 0;
    int count = grid[i][j]--;
    count += count_region(grid, i-1, j-1);
    count += count_region(grid, i-1, j);
    count += count_region(grid, i-1, j+1);
    count += count_region(grid, i, j-1);
    count += count_region(grid, i, j+1);
    count += count_region(grid, i+1, j-1);
    count += count_region(grid, i+1, j);
    count += count_region(grid, i+1, j+1);
    return count;
}

int main(){
    cin >> n;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
