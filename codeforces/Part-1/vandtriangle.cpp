#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pp pop_back
#define f first
#define mp make_pair
#define se second
#define ll long long
#define pii pair<ll,ll>
const int N=1000010;
const int mod=1e9+7;



int main()
{

	ll n,m;
	cin >> n >> m;
	if(m == 0)
	{
		cout << n << " " << n;
		return 0;
	}
	if(n == 1)
	{
		cout << "1 1";
		return 0;
	}
	ll v = n/2 ;
	if(n%2)
		v++;
	if(m>=v)
		cout << "0 ";
	else
		cout << n-2*m << " ";
	ll i;
	//cerr << m << endl;
	for(i=2;i<=n;i++)
	{
		if((i*(i-1))>=2*m)
			break;
		//cerr << i << endl;	
	}
	cout << n-i;

	return 0;		
}