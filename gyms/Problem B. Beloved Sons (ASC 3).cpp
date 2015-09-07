#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = 1e9 + 1;
const double eps = 1e-6;
const ll mod = 1234567;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define clr(v, d) memset(v, d, sizeof(v))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).real(),(a).imag())
#define angle(a) atan2((a).imag() , (a).real())
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(v,m) (conj((v)/(m))*m)
#define dist(a,b) (sqrt(pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0)))
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

vi owner , visited;
int n;
vvi adj;

int AlternatingPath(int u){
	if(visited[u])
		return 0;
	visited[u]=1;
	for(int i=0;i<sz(adj[u]);i++){
		if(owner[adj[u][i]]==-1 || AlternatingPath(owner[adj[u][i]])){
			owner[adj[u][i]] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("beloved.in","r",stdin);
	freopen("beloved.out","w",stdout);
	scanf("%d",&n);
	pair<int,int> a[n];
	adj.resize(n+1);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].first) , a[i].second = i+1;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int u;
			scanf("%d",&u);
			adj[i].push_back(u);
		}
	}
	sort(a , a+n , greater<pair<int,int> >());
	owner.assign(n+1 , -1);
	for(int i=0;i<n;i++){
		visited.assign(n+1 , false);
		AlternatingPath(a[i].second);
	}
	int match[n+1];
	clr(match,0);
	for(int i=1;i<=n;i++){
		if(owner[i]!=-1)
			match[owner[i]]=i;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",match[i]);
	return 0;
}



















