#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
pair <pair<ll,ll>,pair<ll,ll> > p1,p2;

bool onSegment(pair<ll,ll> p, pair<ll,ll> q, pair<ll,ll> r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
       return true;
 
    return false;
}
ll orientation(pair <pair<ll,ll>,pair<ll,ll> > p,pair<ll,ll> q)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    ll val = (p.second.second - p.first.second) * (q.first - p.second.first) -
              (p.second.first - p.first.first) * (q.second - p1.second.second);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool dointersect()
{
    // Find the four orientations needed for general and
    // special cases
    ll o1 = orientation(p1, p2.first);
    ll o2 = orientation(p1,p2.second);
    ll o3 = orientation(p2 ,p1.first);
    ll o4 = orientation(p2,p1.second);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1.first, p2.first, p1.second)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1.first, p2.second, p1.second)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2.first, p1.first, p2.second)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2.first, p1.second, p2.second)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

void check()
{
  if(dointersect() == false)
  {
    cout << "no" << endl;
    return;
  }
  else
  {  
    if(p1.first.second == p1.second.second && p2.first.second == p2.second.second)
    {
        cout << "yes" << endl;
        return; 
    }
    else if(p1.first.first == p1.second.first && p2.first.first == p2.second.first )
    { 
        cout << "yes" << endl;
        return;
    }
    else if(p1.first.second == p1.second.second && p2.first.first == p2.second.first)
    {
     if((p1.first.second==p2.second.second&&p1.first.first==p2.second.first)||(p1.first.second ==    p2.second.second&&p2.second.first==p1.second.first))
    {
     cout << "yes" << endl;
     return;
    }
    if((p1.first.second==p2.first.second&&p1.first.first==p2.first.first)||(p1.first.second == p2.first.second&&p2.first.first==p1.second.first))
    {
       cout << "yes" << endl;
       return;
    }
      cout << "no" << endl;
      return;
   }
   else
   {
       if((p2.first.second==p1.second.second&&p2.first.first==p1.second.first)||(p2.first.second ==    p1.second.second&&p1.second.first==p2.second.first))
       {
         cout << "yes" << endl;
         return;
       }
       if((p2.first.second==p1.first.second&&p2.first.first==p1.first.first)||(p2.first.second == p1.first.second&&p1.first.first==p2.second.first))
    {
       cout << "yes" << endl;
       return;
    }
       cout << "no" << endl;
      return;
   
 }
   }
   return ;
}

void solve()
{
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if(b == d)
  {
    if(a < c)
    {
      p1 = (make_pair(make_pair(a,b),make_pair(c,d)));
    }
    else
    {
      p1 = (make_pair(make_pair(c,d),make_pair(a,b)));
    }
  }
  else
  {
    if(b < d)
    {
      p1 = (make_pair(make_pair(a,b),make_pair(c,d)));
    }
    else
    {
      p1 = (make_pair(make_pair(c,d),make_pair(a,b)));
    }
  }
  cin >> a >> b >> c >> d;
   if(b == d)
  {
    if(a < c)
    {
      p2 = (make_pair(make_pair(a,b),make_pair(c,d)));
    }
    else
    {
      p2 = (make_pair(make_pair(c,d),make_pair(a,b)));
    }
  }
  else
  {
    if(b < d)
    {
      p2 = (make_pair(make_pair(a,b),make_pair(c,d)));
    }
    else
    {
      p2 = (make_pair(make_pair(c,d),make_pair(a,b)));
    }
  }
  //cout << p2.first.first << " " << p2.first.second << " " << p2.second.first << " " << p2.second.second << endl;
  //cout << p1.first.first << " " << p1.first.second << " " << p1.second.first << " " << p1.second.second << endl;
  check();
}

int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
    solve();
}
