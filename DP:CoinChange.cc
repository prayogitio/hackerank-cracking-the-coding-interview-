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

int n,m;
vector<int> coins(50);
long long memo[55][300];

long long make_change(int type, int money) {
    if (type > m-1)
        return 0;
    if (money < 0)
        return 0;
    if (money == 0)
        return 1;
    if (memo[type][money] != -1)
        return memo[type][money];
    return memo[type][money] = make_change(type+1, money) + make_change(type, money-coins[type]);
}

int main(){
    cin >> n >> m;
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    memset(memo, -1, sizeof memo);
    cout << make_change(0, n) << endl;
    return 0;
}
