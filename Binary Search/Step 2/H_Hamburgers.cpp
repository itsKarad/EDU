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
int nb,ns,nc,pb,ps,pc,r;
int reqb=0,reqs=0,reqc=0;
int already=0;
string s;
bool valid(int x){// can we make x 
    int cost=0;

    cost+=max(0ll,(x*reqb-nb)*pb);
    cost+=max(0ll,(x*reqs-ns)*ps);
    cost+=max(0ll,(x*reqc-nc)*pc);
    return (cost<=r);
}
void solve()
{
    cin>>s;  
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    reqb=0,reqc=0,reqs=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B'){
            reqb++;
        }
        else if(s[i]=='S'){
            reqs++;
        }
        else{
            reqc++;
        }
    }  
    for(int burger=0;burger<=100;burger++){
        if(reqb*burger<=nb && reqs*burger<=ns && reqc*burger<=nc){
            already=burger;
        }
    }    
    nb-=already*reqb;
    ns-=already*reqs;
    nc-=already*reqc;
    int lo=0,hi=1e12;
    int answer=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(valid(mid)){
            answer=max(answer,mid);
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<answer+already<<endl;    
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