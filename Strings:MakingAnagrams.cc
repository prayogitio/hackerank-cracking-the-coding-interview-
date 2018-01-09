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

int number_needed(string a, string b) {
	map<char, int> count;
	for (int i = 0; i < a.length(); i++) {
		count[a[i]]++;
	}
	for (int i = 0; i < b.length(); i++) {
		count[b[i]]--;
	}
	map<char,int>::iterator it;
	int res = 0;
	for (it=count.begin(); it!=count.end(); it++) {
		res += abs(it->second);
	}
	return res;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
