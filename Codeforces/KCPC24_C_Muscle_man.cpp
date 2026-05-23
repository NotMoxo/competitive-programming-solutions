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
    vector<int>v(6),x(6);
    int mn1 = LLONG_MAX, mn2 = LLONG_MAX;
    for (int i=0;i<6;i++) {
        cin >> v[i] >> x[i];
        mn1 = min(mn1, v[i]);
        mn2 = min(mn2, x[i]);
    }
    int ans = 0;
    for (int i=0;i<6;i++) {
        ans += v[i] - mn1;
        ans += x[i] - mn2;
    }
    cout << ans << endl;
}

signed main() {
    file();
    MOXO
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
