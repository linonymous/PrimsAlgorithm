//	Prims Algorithm
// By Linonymous


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

#define read(x) freopen(x,"r",stdin)
#define write(x) freopen(x,"w",stdout)
#define REP(i,n) for( i=0;i<(n);i++)
#define FOR(i,a,b) for( i=(a);i<=(b);i++)
#define FORD(i,a,b) for( i=(a);i>=(b);i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ins insert

typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
#define SZ 100005

ll n,i,j,cost;
bool visited[SZ];
ll a[500][500];

void init()
{
	for(i=0;i<SZ;i++)
		visited[i]=false;
}

void prims(ll x)
{
	priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	//visited[x]=true;
	q.push(mp(0,x));
	ll min;
	while(!q.empty())
	{
		pair<ll,ll> node=q.top();
		q.pop();
		ll p=node.second;
		if(visited[p])
			continue;
		cost+=node.first;
		visited[p]=true;
		for(i=0;i<n;i++)
		{
			if(!visited[i] && a[p][i])
				q.push(mp(a[p][i],i));	
		}	
	}
}

int main()
{
	ll x,y,wt;
	cin>>n;
	REP(i,n)
	{
		cin>>x>>y>>wt;
		a[x][y]=wt;
		a[y][x]=wt;			
	}
	prims(0);
	cout<<cost<<endl;			
    return 0;
}
