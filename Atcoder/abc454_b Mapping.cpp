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
    int n,m; cin >> n >> m;
    vector<int> v(n), freq(101, 0), freq2(101, 0);
    for (int i=0;i<n;i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    bool alldiff = true;
    bool allin = true;
    for (int i=0;i<n;i++) {
        if (freq[v[i]] > 1) {
            alldiff = false;
        }
    }
    for (int i=1;i<=m;i++) {
        if (freq[i] < 1) {
            allin = false;
        }
    }
    cout << (alldiff ? "Yes" : "No") << endl;
    cout << (allin ? "Yes" : "No") << endl;
}
signed main() {
    file();
    MOXO
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
