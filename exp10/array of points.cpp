#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if(n <= 2) return n;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        map<pair<int,int>, int> m;
        int same = 1;

        for(int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if(dx == 0 && dy == 0) {
                same++;
                continue;
            }

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            m[{dx, dy}]++;
        }

        int mx = 0;
        for(auto &it : m) mx = max(mx, it.second);

        ans = max(ans, mx + same);
    }

    return ans;
}
