#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);

        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i < n; ++i) {
            int val;
            scanf("%d", &val);
            v1.push_back(val);
        }
        
        for (int i = 0; i < n; ++i) {
            int val;
            scanf("%d", &val);
            v2.push_back(val);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += v1[i] * v2[n-i-1];
        }
        printf("Case #%d: %ld\n", t, sum);
    }
    return 0;
}
