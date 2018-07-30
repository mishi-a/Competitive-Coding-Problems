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
int freqs[30];
int freqt[30];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    string s,t;
    cin >> s >> t;
    for(int i=0;i<s.length();i++)
    {
       freqs[s[i]-'a']++;
       freqt[t[i]-'a']++;
    }
    int flag = 0;
    for(int i=0;i<=25;i++)
    {
      if(freqs[i]>1 && freqt[i]==0)
      {
        flag = 1;
        break;
      }
    }
    for(int i=0;i<=25;i++)
    {
            if(flag == 1)
              break;
            if(freqt[i]==0 && freqs[i]==1)
              {
                 freqs[i]--;
                 for(int j=0;j<=25;j++)
                 {
                   if(freqt[j]>0 && freqs[j]==0)
                   {
                      flag = 2;
                      break;
                   }
                 }
                 if(flag==2)
                   break;
                 else
                 {
                   flag = 1;
                   break;
                 }  
              }
    }
    if(flag == 0)
      flag = 2;
    if(flag == 2)
      cout << "B" << endl;
    else
      cout << "A" << endl;
    memset(freqs,0,sizeof(freqs));
    memset(freqt,0,sizeof(freqt));
  }
}

