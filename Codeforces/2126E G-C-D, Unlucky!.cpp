#include <bits/stdc++.h>
using namespace std;
#define LOOP(i, x, n) for (int i = x; i < n; i++)
#define RLOOP(i, x, n) for (int i = x; i >= n; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define pf push_front
#define MOXO ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl '\n'
#define int long long
#define ull unsigned long long

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
                                 ███    ███  ██████   █   █   ██████
                                 ████  ████ ██    ██   █ █   ██    ██
                                 ██ ████ ██ ██ ██ ██    █    ██ ██ ██
                                 ██  ██  ██ ██    ██   █ █   ██    ██
                                 ██      ██  ██████   █   █   ██████
*/

void solve() {
    int n; cin >> n;
    vector<int>p(n), s(n);
    for (int i=0;i<n;i++) cin >> p[i];
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=1;i<n;i++) {
        if (p[i - 1] % p[i] != 0) {
            NO;
            return;
        }
    }
    for (int i=0;i<n-1;i++) {
        if (s[i + 1] % s[i] != 0) {
            NO;
            return;
        }
    }
    if (p[n - 1] != s[0]) {
        NO;
        return;
    }
    int gc = p[n-1];
    for (int i=1;i<n;i++) {
        if (gcd(p[i - 1], s[i]) != gc) {
            NO;
            return;
        }
    }
    YES;
}
signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}
