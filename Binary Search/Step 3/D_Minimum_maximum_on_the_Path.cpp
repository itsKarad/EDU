#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long 
#define MOD 1000000007
#define MOD2 1000000014000000049L
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define bs binary_search
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;
#define debug(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************
int n,m,d;
vector<pair<pair<int,int>,int>> a(1e5+5);
bool valid(int x){
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        if(a[i].second<=x){
            adj[a[i].first.first].pb(a[i].first.second);
        }
    }
    // bfs
    vector<bool> vis(n,false);
    vector<int> dist(n,INF);
    dist[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y : adj[x]){
            if(!vis[y]){
                vis[y]=true;
                dist[y]=dist[x]+1;
                q.push(y);
            }
        }
    }
    if(dist[n-1]<=d){
        return true;
    }
    return false;
}
void out(int x){
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        if(a[i].second<=x){
            adj[a[i].first.first].pb(a[i].first.second);
        }
    }
    // bfs
    vector<bool> vis(n,false);
    vector<int> dist(n,INF);
    vector<int> p(n,-1);
    dist[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y : adj[x]){
            if(!vis[y]){
                vis[y]=true;
                dist[y]=dist[x]+1;
                p[y]=x;
                q.push(y);
            }
        }
    }
    if(dist[n-1]==INF){
        cout<<-1<<endl;
        return;
    }
    vector<int> path;
    int curr=n-1;
    while(curr!=0){
        path.pb(curr);
        curr=p[curr];
    }
    path.pb(0);
    reverse(all(path));
    if(path.size()-1>d){
        cout<<-1<<endl;
        return;
    }
    cout<<path.size()-1<<endl;
    for(auto x : path){
        cout<<x+1<<" ";
    }
    cout<<endl;

}
void solve()
{
    cin>>n>>m>>d;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        a[i]={{x,y},z};
    }
    int lo=0,hi=1e9;
    int answer=INF;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(valid(mid)){
            hi=mid-1;
            answer=min(answer,mid);
        }
        else{
            lo=mid+1;
        }
    } 
    out(answer);
}
signed main() 
{ 
    FAST;
    solve();
    return 0; 
} 



// Paste for reading from input file
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif




int power(int base, int exp) {
   int res=1;
   while(exp>0) {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
   }
   return res%MOD;
}






// sometimes I believe compiler ignores all my comments