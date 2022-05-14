/* iamujj15 */

#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;

#define fstio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb emplace_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define FIXED_FLOAT(x) std::fixed << std::setprecision(15) << (x)
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef long long ll;
typedef unsigned long long ull;


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll pow2(ll k) {ll i = 1; if (k == 0) return 1; while (k--) i *= 2; return i;}
ll lcm(int a, int b) { return (a / gcd(a, b)) * b;}
ll mx(ll a, ll b) {return a > b ? a : b;}
ll mn(ll a, ll b) {return a < b ? a : b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
ll _ceil(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
/*--------------------------------------------------------------------------------------------------------------------------*/

ll n;
vector<vll> grd;

bool issafe(ll i, ll j, ll x)
{
    for (ll p = 0; p < n; p++)
        if (grd[p][j] == x || grd[i][p] == x)
            return false;

    ll sbg = (ll)sqrt(n);
    ll ii, ji;
    ii = i - i % sbg;
    ji = j - j % sbg;

    for (ll p = 0; p < sbg; p++)
        for (ll q = 0; q < sbg; q++)
            if (grd[p + ii][q + ji] == x)
                return false;

    return true;
}

bool slvsdkrec(ll i, ll j)
{
    if (i == n - 1 && j == n) return true;
    if (j == n)
    {
        i++;
        j = 0;
    }
    if (grd[i][j] == 0)
    {
        for (ll x = 1; x <= n; x++)
        {
            if (issafe(i, j, x))
            {
                grd[i][j] = x;
                if (slvsdkrec(i, j + 1) == true) return true;
                grd[i][j] = 0;
            }
        }
    }
    else
        if(slvsdkrec(i, j + 1)) return true;
    return false;
}

void solution()
{
    // Enter the value of the size of grid of dimension n*n.
    // Enter the value of grid in integers.
    // You'll get in output a grid with answer of the provided sudoku
    cin >> n;
    grd.resize(n, vll(n));

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> grd[i][j];

    if (slvsdkrec(0, 0) == false)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
                cout << grd[i][j] << " ";
            cout << nline;
        }
    }
}

int main()
{
#ifdef iamujj15
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    fstio();
    auto start1 = high_resolution_clock::now();
    solution();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef iamujj15
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}