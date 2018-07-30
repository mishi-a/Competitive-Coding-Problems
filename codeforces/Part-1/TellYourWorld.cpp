/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second
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

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;

int arr[1005];
vector <int > v;
int change(int& num1,int& num2)
{
     //cout << num1 << " " << num2 << " " ;
     int gcd = __gcd(abs(num1),abs(num2));
     num1/=gcd;
     num2/=gcd;
     if(num1<0 && num2<0)
     {
       num1*=-1,num2*=-1;
     }
     else if(num2<0)
     {
       num1*=-1,num2*=-1;
     }
     //cout << num1 << " " << num2 << endl;
}

int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    cin >> arr[i];
  }
  int p1 = arr[1];
  int p2 = arr[2];
  int p3 = arr[3];
  int s1 = p3-p2;
  int s2 = 1;
  change(s1,s2);
  int flag = 0;
  for(int i=4;i<=n;i++)
  {
    int t1 = arr[i]-p2;
    int t2 = i-2;
    change(t1,t2);
    if(t1!=s1 ||t2!=s2 )
    {
      flag = 1;
      break;
    }
  }
  if(flag == 0)
  {
    int t1 = p2-p1;
    int t2 = 1;
    change(t1,t2);
    if(s1 ==t1 && s2==t2)
    {
      cout << "no" << endl;
      return 0;
    }
    cout << "yes" << endl;
    return 0;
  }
  for(int i=2;i<=n;i++)
  {
     int num1 = arr[i]-p1;
     int num2 = i-1;
     change(num1,num2);
     for(int j=2;j<=n;j++)
     {
        int x = arr[j]-p1;
        int y = j-1;
        change(x,y);
        if(x!=num1 || y!=num2)
         v.pb(j);       
        
     }
     //cout << v.size() << endl;
     if(v.size()==0)
     {
       cout << "no" << endl;
       return 0;
     } 
     if(v.size()==1)
     {
       cout << "yes" << endl;
       return 0;
     }
     int node = v[0];
     int flag1 = 0;
     for(int i=1;i<v.size();i++)
     {
        int k = arr[v[i]]-arr[node];
        int l = v[i]-v[0];
        change(k,l);
        if(k!=num1||l!=num2)
        {
           flag1 = 1;
           break;
        }
     }
     if(flag1 == 0)
     {
       cout << "yes" << endl;
       return 0;
     }
     //cout << i << " " << v.size() << endl;
     v.clear();
  }
  cout << "no" << endl;
}
