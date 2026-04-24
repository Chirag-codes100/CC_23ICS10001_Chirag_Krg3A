#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) {
    return (a * b) / __gcd(a, b);
}

int nthMagicalNumber(int n, int a, int b) {
    long long mod = 1e9 + 7;
    long long l = min(a, b), r = 1LL * n * min(a, b);
    long long LCM = lcm(a, b);

    while(l < r) {
        long long mid = (l + r) / 2;
        long long count = mid / a + mid / b - mid / LCM;

        if(count < n) l = mid + 1;
        else r = mid;
    }

    return l % mod;
}
