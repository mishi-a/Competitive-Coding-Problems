#include<iostream>
#include<vector>        
#include <algorithm> 
#include <iterator>
#include <deque>
using namespace std;

#define sync ios::sync_with_stdio(false)
#define endl '\n'
int max1;
int index1;
int update (int coun,deque <int>& v,deque <int>& d,int k)
{
  int n = v.size();
  for(int i=0;i<coun;i++)
  {
    int l = v[v.size()-1];
    int p = d[d.size()-1];
    v.pop_back();
    d.pop_back();
    v.push_front(l);
    d.push_front(p);
    int sum = 0;
    index1++;
    v[0] = v[1]+d[0]-d[k];
    if(index1<n){
    if(v[0] > v[index1])
    {
       index1 = 0;
       max1 = v[0];
    }}
  }

  if(index1<n)
  {
    cout << max1 << endl;
    return max1;
  }
  else
  {
   int max = -1;
   for(int i=0;i<v.size();i++)
   {
     if(v[i] > max){
       max = v[i];
       index1 = i;}
   }
    cout << max << endl;
    max1 = max;
    return max;
  }
  return 0;
}
int main()
{
  sync;
  int n,k,p;
  cin >> n >> k >> p;
  deque <int> d;
  int a;
  int result = 0;
  for(int i=0;i<n;i++)
  {
    cin >> a;
    d.push_back(a);
    if(n <=k)
      result = result+a;
  }
  if(n > k)
  {
          deque <int> v;
          int sum = 0;
          for(int i=0;i<k;i++)
          {
            sum = sum+d[i];
          }
          v.push_back(sum);
          max1 = v[0];
          index1 = 0;
          for(int i=1;i<=n-k;i++)
          {
            sum = sum -d[i-1] + d[i+k-1];
            v.push_back(sum);
            if(sum > max1 )
            {
              max1 = sum;
              index1 = i;
            }
          }
          /*for(int i=0;i<=n-k;i++)
           cout << v[i] << " ";*/
           char x;
           int coun = 0;
           int result = 0;
           for(int i=0;i<p;i++)
           {
             cin >> x;
             if(x == '!')
                coun++;
             else
             {
               if(coun == 0 && result!=0)
                 cout << result <<endl;
               else{
               result = update(coun%n,v,d,k);
               coun = 0;
              }
           }
   }
   }
   else
   {
         char x;
         for(int i=0;i<p;i++)
           {
             cin >> x;
             if(x == '!')
                continue;
             else
             {
               //update(coun,v,d,k);
               cout << result << endl;
               
             }
           } 
   }
   
}
