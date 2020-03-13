#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define edge vector<pair<int,pii>>

const int N=100009;
const int mod=1e9;

int parent[N],members[N],csum[N];

int find(int u)
{
    while(u!=parent[u]) u=parent[parent[u]];
    return u;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m,a,b,c,ans=0;
    edge edges;

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edges.pb(mp(c,mp(a,b)));
    }

    sort(edges.begin(),edges.end());

    if(edges.size()>=1) csum[0]=edges[0].f;
    for(int i=1;i<m;i++)
    {
        csum[i]=edges[i].f+csum[i-1];
    }

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        members[i]=1;
    }

    for(int i=m-1;i>=0;i--)
    {
        int u=find(edges[i].s.f);
        int v=find(edges[i].s.s);

        if(u!=v)
        {
            int set1=members[u];
            int set2=members[v];

            int prod=(set1*set2)%mod;
            ans+=(prod*csum[i]);
            ans%=mod;

            if(set1<set2)
            {
                parent[u]=parent[v];
                members[v]+=members[u];
                members[u]=0;
            }
            else
            {
                parent[v]=parent[u];
                members[u]+=members[v];
                members[v]=0;
            }
        }
    }

    cout<<(ans%mod);
    return 0;
}