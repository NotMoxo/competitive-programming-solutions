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
    string s, s2; cin >> s >> s2;
    string t = "", t2 = "";
    for (auto c : s) {
        t += c;
        int n = t.size();
        if (n >= 4 && t.substr(n - 4, 4) == "(xx)") {
            for (int i=0;i<4;i++) {
                t.pop_back();
            }
            t += "xx";
        }
    }
    for (auto c : s2) {
        t2 += c;
        int n = t2.size();
        if (n >= 4 && t2.substr(n - 4, 4) == "(xx)") {
            for (int i=0;i<4;i++) {
                t2.pop_back();
            }
            t2 += "xx";
        }
    }
    if (t == t2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}
