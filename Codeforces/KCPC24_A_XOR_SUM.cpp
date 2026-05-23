#include <limits.h>
#include <math.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define LOOP(i, x, n) for (int i = x; i < n; i++)
#define RLOOP(i, x, n) for (int i = x; i >= n; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define pf push_front
#define PI 3.141592653589793
#define MOXO ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl '\n'
#define mod 998244353
#define mp make_pair
#define int long long
#define ull unsigned long long
typedef std::vector<int> vi;

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#include <vector>

bool isPalindrome(const std::vector<int> &vec, int l, int r) {
    while (l < r) {
        if (vec[l] != vec[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int mexlr(vector<int> &v, int l, int r) {
    set<int> seen;
    for (int i = l; i <= r; i++) {
        if (v[i] >= 0) {
            seen.insert(v[i]);
        }
    }
    int mexo = 0;
    while (seen.count(mexo)) {
        mexo++;
    }
    return mexo;
}

// elhookshtripledooksh STAMP
bool comparePairsBySecond(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.second < b.second;
}

int mex(vector<int> &v) {
    int n = v.size();
    vector<bool> present(n + 1, false);
    for (int i = 0; i < n; i++) {
        if (v[i] <= n) {
            present[v[i]] = true;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!present[i]) return i;
    }
    return n;
}

bool checkBit(int n, int i) {
    return (n >> i) & 1;
}

//  1. Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) // 100
        if (n % i == 0) return false; //
    return true;
}

// Sieve for small primes
bool prime[100];

void buildSieve() {
    for (int i = 0; i <= 100; i++) prime[i] = true;
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 100; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 100; j += i) {
                prime[j] = false;
            }
        }
    }
}

// prime numbers from 2 to n using sieve
void sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) cout << i << endl;
    }
    cout << endl;
}

// next prime
int nextPrime(int n) {
    int p = n + 1;
    while (!isPrime(p)) p++;
    return p;
}

// GCD
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// Max GCD
int MaxGcd(int n) {
    return (n / 2);
}

// LCM
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Prime factorization sieve
const int zx = 1000005;
int arr[zx];

void sieve_prime_fact() {
    for (int i = 0; i < zx; i++) {
        arr[i] = -1;
    }
    for (int i = 2; i < zx; i++) {
        if (arr[i] == -1) {
            for (int j = i; j < zx; j += i) {
                if (arr[j] == -1) {
                    arr[j] = i;
                }
            }
        }
    }
}

int prime_fact(int n) {
    map<int, int> fac;
    while (n != 1) {
        fac[arr[n]]++;
        n /= arr[n];
    }
    int divs = 1;
    for (auto it: fac) {
        divs *= (it.second + 1);
    }
    return divs;
}

// divisors
vector<int> getDivisors(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    return d;
}

// sum of primes
int sumOfPrimes(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) sum += i;
    }
    return sum;
}

vector<int> primeFactorization(int n) {
    vector<int> factors;
    if (n < 2) return factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// multiply big numbers
// 255
string multiply(string num1, string num2) {
    int n = num1.length();
    int m = num2.length();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mult = (num1[i] - '0') * (num2[j] - '0');
            int sum = mult + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string product = "";
    for (int num: res) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    return product.empty() ? "0" : product;
}

vector<int> parent(2005);
int DFS(int n) {
    if (n == -1) return 0;
    return 1 + DFS(parent[n]);
}

/*
                                 ███    ███  ██████   █   █   ██████
                                 ████  ████ ██    ██   █ █   ██    ██
                                 ██ ████ ██ ██ ██ ██    █    ██ ██ ██
                                 ██  ██  ██ ██    ██   █ █   ██    ██
                                 ██      ██  ██████   █   █   ██████
*/

bool ask(int x) {
    cout << x << endl;
    cout.flush();
    string s;
    cin >> s;
    return s == "yes";
}

// vector<int>primes;
int elhosk = 501;
int MOD = 1000000007LL;
int modpow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
// UPSOLVE
void elhookshtripledooksh() {
    int n; cin >> n;
    vector<int>v(n);
    int mnsum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int bit = 0;bit < 31;bit++) {
        int ones = 0;
        for (int i=0;i<n;i++) {
            if (v[i] & (1LL << bit)) ones++;
        }
        int zero = n - ones;
        int cost1 = zero * (1LL << bit);
        int cost0 = ones * (1LL << bit);
        mnsum += min(cost1, cost0);
        if (zero == ones) cnt *= 2;
    }
    cout << mnsum << ' ' << cnt << endl;
}

signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) elhookshtripledooksh();
}
