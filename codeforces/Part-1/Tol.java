public class Tol
{
	public static void main(String[] args)
	{
		int t;
	  cin >> t;
	  while(t--)
	  {
	  	int num;
	  	cin >> num;
	  	for(int i=0;i<num;i++)
	  	{
	  		int p,h;
	  		cin >> p >> h;
	  		p+=100005;
	  		v.pb({p-h,p+h});
	  	}
	  	sort(v.begin(),v.end());
	  	double area = pow((v[0].SE-v[0].FI)/2.0,2);
	  	int cur = 0;
	  	for(unsigned i=1;i<v.size();i++)
	  	{
	  		while(i<v.size() && v[i].SE<=v[cur].SE)
	  			i++;
	  		if(i == v.size())
	  			break;
	  		//cerr << i << endl;
	  		if(v[i].FI < v[cur].SE)
	  		{
	  			double h = (v[i].SE-v[i].FI)/2.0;
	  			double h1 = (v[cur].SE-v[cur].FI)/2.0;
	  			pdd intH = lineLineIntersection({v[i].FI,0},{v[i].FI+h,h},
	  				{v[cur].SE,0},{v[cur].FI+h1,h1});
	  			//cerr << intH.FI << " " << intH.SE  << " " << area << endl;
	  			area -= ((v[cur].SE-v[i].FI)*intH.SE)/2.0;

	  		}
	  		area += pow((v[i].SE-v[i].FI)/2.0,2);
	  		cur = i;
	  	}
	  	cout << fixed << setprecision(2);
	  	cout << area << endl;
	  	v.clear();
	  }
	}
}