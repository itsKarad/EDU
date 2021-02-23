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


void solve()
{
    int n[4];
    vector<vector<int>> a(4);
    rep(j,0,4){
        cin>>n[j];
        rep(i,0,n[j]){
            int x;
            cin>>x;
            a[j].pb(x);
        }
        sort(all(a[j]));
    }
    vector<int> idx(4,0);
    vector<int> answerIdx(4,0);
    int answer=INF;
    while(1){
        int mn=INF,mx=-1;
        rep(i,0,4){
            mn=min(mn,a[i][idx[i]]);
            mx=max(mx,a[i][idx[i]]);
        }
        if(answer>mx-mn){
            answer=mx-mn;
            answerIdx=idx;
        }
        bool f=false;
        rep(i,0,4){
            if(mn==a[i][idx[i]] && idx[i]+1<n[i]){
                idx[i]++;
                f=true;
                break;
            }
        }
        if(!f){
            break;
        }
        
    }
    rep(i,0,4){
        cout<<a[i][answerIdx[i]]<<" ";
    }





    
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