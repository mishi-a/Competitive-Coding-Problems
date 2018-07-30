#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
 
using namespace std;
 
const int size = 1e7+9;
 
int arr[size]={0};
int arr1[size] = {0};
int mux;
long long  getsum(int index)
{
 long long  sum = 0;
 while(index > 0)
 {
   sum+=arr[index];
   index -=(index&(-index));
 }
 return sum;
}
 
void update(int index,int val)
{
  while(index <= mux)
  {
    arr[index]+=val;
    index +=(index & (-index));
  }
}
 
void solve()
{
 int n;mux = -1;
 cin >> n;
 vector <int> v;
 for(int i=0;i<n;i++)
 {
   int x;
   cin >> x;
   v.push_back(x);
   if(x>mux)
     mux = x;
   arr1[x-1] = 1;
 }
 long long  inversion = 0;
 for(int i=0;i<mux;i++)
 {
   update(i+1,arr1[i]);
 }
 for(int i=0;i<v.size();i++)
 {
   inversion += getsum(v[i]-1);
   //cout << inversion << endl;
   update(v[i],-1);
 }
 cout << inversion << endl;
 memset(arr,0,sizeof(arr));
 memset(arr1,0,sizeof(arr1));
}
 
 
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}
