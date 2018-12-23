#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef unordered_map<int, int> mii;
typedef unordered_map<ll, ll> mll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define rep(i,n) for(unsigned int i = 0;i < n;i++)
#define loop(i, a, b) for(int i = a;i < b;i++)
#define rloop(i, a, b) for(int i = a;i >= b;i--)
#define vout(a) rep(i,a.size()) cout << a[i] << " ";cout << endl;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007

void lio(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
ll power(ll a, ll b) {ll x=power(a,b/2);return (b%2)?x*x*a:x*x;}
ll power_mod(ll a, ll b) {ll x=power_mod(a,b/2);return (b%2)?(((x*x)%mod)*a)%mod:(x*x)%mod;}
ll add_mod(ll a, ll b) {return ((a%mod)+(b%mod))%mod;}
ll sub_mod(ll a, ll b) {return ((a%mod)-(b%mod)+mod)%mod;}
ll prod_mod(ll a, ll b) {return ((a%mod)*(b%mod))%mod;}


int main(void) {
	fio;
	//lio();
	ll n,s,m;
    cin >> n >> s >> m;
    
    if(n == 1) {
        cout << s << endl;
        return 0;
    }
    if(s == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll minus = 0;
    vll p(n+1, 1);vll pal(n+1, 1);
    loop(i,1,n+1) p[i] = (p[i-1] * s) % m;

    pal[1] = s;pal[2] = s;
    loop(i,3,n+1) pal[i] = ((pal[i-2] * s)%m - s + m)%m;
   
    loop(len, 2, n+1)
        minus = (minus + (pal[len]*p[n-len])%m)%m;
    cout << (p[n] - minus + m)%m << endl;
	return 0;
}