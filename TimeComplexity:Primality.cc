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
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        if (n == 1)
            printf("Not prime\n");
        else {
            bool prime = true;
            int hi = (int) sqrt(n);
            for (int i = 2; i <= hi && prime == true; i++) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            if (prime)
                printf("Prime\n");
            else printf("Not prime\n");    
        }
        
    }
    return 0;
}