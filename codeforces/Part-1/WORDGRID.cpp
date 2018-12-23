#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
template<typename T> using V = vector<T>;
#define fi first
#define se second
#define pb push_back
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fr(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ro(i, a, b)     for (int i = (a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x)   (int)x.size()
#define ii  pair< int, int >
#define i_ii pair< int, ii >
#define ret return 0;
const LL INF = 1e18 + 5;
const int MOD = (int)1e9 + 9;
const int maxn = (int)1e5 + 5;
const int maxm = (int)1e9;
LL TEN(int x){LL ans = 1;while(x--)ans*=10;return ans;}
void add(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
int modE(int n, int x){int res=1;while(x){if(x&1)res=(1ll*res*n)%MOD;n=(1ll*n*n)%MOD;x>>=1;}return res;}

int t, T, n, k;
multiset<int> a;

int main() {
scanf("%d", &T);
while(T--){
    a.clear();
    scanf("%d%d", &n, &k);
    fo(i, n)scanf("%d", &t), a.insert(t);
    if(n == 1){
        printf("%d\n", *a.begin());
        continue;
    }
    int mx = *a.rbegin();
    a.erase(a.find(mx));

    LL ans = 0;
    while(1){
        /*for(auto x : a)cout << x << ' ';
        cout << endl;*/
        while(SZ(a) && *a.begin() <= k)ans += *a.begin(), a.erase(a.begin());
        if(SZ(a) < 2)break;
        int a1 = *a.begin();
        auto it = a.upper_bound(a1);
        if(it == a.end()){
            if(SZ(a) == 2) {ans += 2 * k;a.clear(); break;}
            else {                
                int a2 = *next(a.begin());
                a.erase(a.begin()), a.erase(a.begin());
                a.insert(a1 - 1), a.insert(a2 - 1);
            }
        }else{
            int a2 = *it;
            int d = a1 - k;
            a.erase(a.find(a1));
            a.erase(a.find(a2));
            a.insert(a1 - d);
            a.insert(a2 - d);
        }
    }
        // for(auto x : a)cout << x << ' ';
        // cout << endl;
    if(SZ(a) && *a.begin() > k){
        int a1 = *a.begin(); a.erase(a.begin());
        int d = a1 - k;
        mx -= d;
        a1 -= d;
        ans += a1;
    }
    if(SZ(a))ans += *a.begin();
    ans += mx;
    printf("%lld\n", ans);

}
}
