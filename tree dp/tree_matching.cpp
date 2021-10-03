#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define meme(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1'000'000'007
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
 
int dp[200005][2];
 
void dfsutil(vector<int> adj[],int src,int par){
    dp[src][0] = dp[src][1] = 0;
    bool f = 0;
    for(auto x: adj[src]){
        if(x != par){
            f = 1;
            dfsutil(adj,x,src);
        }
    }
    if(!f) return;
    vector<int> prefix,suffix;
    for(auto x: adj[src]){
        if(x != par){
            prefix.push_back(max(dp[x][0],dp[x][1]));
            suffix.push_back(max(dp[x][0],dp[x][1]));
        }
    }
    for(int i = 1;i<prefix.size();i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i = suffix.size()-2;i>=0;i--){
        suffix[i]+=suffix[i+1];
    }
    dp[src][0] = suffix[0];
    int child = 0;
    for(auto x : adj[src]){
        if(x!=par){
            int left = (child==0) ? 0 : prefix[child-1];
            int right = (child==(int)suffix.size()-1) ? 0 : suffix[child+1];
            dp[src][1] = max(dp[src][1], 1+left+right+dp[x][0]);
            child++;
        }
    }
}
 
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp,0,sizeof(dp));
    dfsutil(adj,1,0);
    cout<<max(dp[1][0],dp[1][1])<<"\n";
}