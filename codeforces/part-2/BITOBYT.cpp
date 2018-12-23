#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

const int MAX = 2e5+7;


using namespace std;
ll bit[1660][3];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n;
  	cin >> n;
  	bit[2][0] = 1;
  	ll b=1,nib=0,byt=0;
  	for(int i=1;i<n;i++)
  	{
  		if(bit[i][0] > 0)
  		{
  			b-=bit[i][0];
  			nib+=bit[i][0];
  			bit[i+8][1]+=bit[i][0];
  		}
  		if(bit[i][1] > 0)
  		{					
  			nib-=bit[i][1];
  			byt+=bit[i][1];
  			bit[i+16][2]+=bit[i][1];
  		}
  		if(bit[i][2] > 0)
  		{
  			b+=2*bit[i][2];
  			bit[i+2][0]+=2*bit[i][2];
  			byt-=bit[i][2];
  		}
  	}
  	cout << b << " " << nib << " " << byt << endl;
  	memset(bit,0,sizeof(bit));
  } 
}
