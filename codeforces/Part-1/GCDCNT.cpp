/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second
//#define block 224
#define MAXN 100002
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/


using namespace std;
int v[230][100005];
int n;
int arr[50005];
int tDiv[100005];
int block = 224;
 
// stores smallest prime factor for every number
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
int getFactorization(int x)
{
    vector<int> ret;
    set<int> r;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        r.insert(spf[x]);
        x = x / spf[x];
    }
    if(ret.size()==r.size())
    	return ret.size();
    else
    	return 0;
}
 
void add(int cBlock,int idx)
{
  for(int i=1;i*i<=arr[idx];i++)
  {
  	if(arr[idx]%i == 0)
  	{
  		v[cBlock][i]++;
  		v[cBlock][arr[idx]/i]++;
  		if(i*i == arr[idx])
  			v[cBlock][i]--;
  	}
  } 
}

void build()
{
  int cBlock = 0; 
  for(int i=0;i<n;i++)
  {
    if(i/block>cBlock)
    	cBlock++;
    add(cBlock,i);
  }
}

void update(int x,int y)
{
	int cBlock = x/block;
	for(int i=1;i*i<=arr[x];i++)
  	{
  		if(arr[x]%i == 0)
  		{
  			v[cBlock][i]--;
  			v[cBlock][arr[x]/i]--;
  			if(i*i == arr[x])
  				v[cBlock][i]++;
  		}
  	}	 
  	arr[x] = y;
	for(int i=1;i*i<=y;i++)
    {
  	  if(arr[x]%i == 0)
  	  {
  	  	v[cBlock][i]++;
  		v[cBlock][arr[x]/i]++;
  		if(i*i == arr[x])
  			v[cBlock][i]--;
  	  }
    } 
}

int getCount(int x,int y,int f)
{
	int ans = 0;
	int startBlock = x/block + 1;
	int endBlock = y/block -1;
	while(startBlock<=endBlock)
	{
		ans+=v[startBlock][f];
		startBlock++;
	}
	return ans;
}

int query(int x,int y,int g)
{
   int s=x,t=y;	
   int ans=0;
   int cnt = 0;	
   //cout << x << " " << y << " " << g << endl;
   for(int i=1;i*i<=g;i++)
   {
   	 if(g%i==0)
   	 {
   	 	//cout << i <<" " << g/i <<  endl;
        int val = getFactorization(i);
        int val1 = getFactorization(g/i);
        //cout << val << " " << val1 << endl;
        if(val!=0)
        {
        	if(val%2==0)
        		ans-=getCount(x,y,i);
        	else
        		ans+=getCount(x,y,i);
        }
        if(val1!=0)
        {
            if(i*i==g)
            	int z=0;
        	else if(val1%2==0)
        		ans-=getCount(x,y,g/i);
        	else
        		ans+=getCount(x,y,g/i);
        }  
        //cout << ans << endl; 	 
   	 }

   }
   
   int sBlock = x/block;
   int end = sBlock*block+block-1;
   int flag =0;
   while(x<=end&&x<=y)
   {
   	 if(__gcd(arr[x],g)!=1)
   	 	ans++;
   	 x++;
   	 if(x>y)
   	 	flag=1;
   }
   sBlock = y/block;
   int start = (sBlock-1)*block+block;
   if(flag == 0)
   {
   	 while(start<=y)
   	 {
   	 	 if(__gcd(arr[start],g)!=1)
   	 	    ans++;
   	 	 start++;
   	 }
   }
   //cout << ans << endl;
   return (t-s+1-ans); 
}

int main()
{
  sync;
  sieve();
  cin >> n;
  //	block  = ceil(sqrt(n));
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  build();
  int q;
  cin >> q;
  //cout << getFactorization(5) << endl;
  while(q--)
  {
    int t;
    cin >> t;
    if(t==1)
    {
    	int x,y;
    	cin >> x >> y;
    	x--;
    	update(x,y);
    }
    else
    {
        int x,y,g;
        cin >> x >> y >> g;
        x--;
        y--;
        cout << query(x,y,g) << endl;
    }
  }
}
