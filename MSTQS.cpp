// thop sum.....dsu kooda revise aipoindi....u=parent[u].id kadu ra howle.......u=parent[parent[u].id].id;....thu howle
// and union lo club cheyyalsindi parents ni....edi padithe adi kadu

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
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=2e5+5;
const int mod=1e9+7;

struct Ds
{
    int id,members;
};

int n,m,q,a,b,c,type;
Ds parent[N];
set<pair<int,pii>> edges,mst;

int root(int u)
{
    while(u!=parent[u].id) u=parent[parent[u].id].id;
    return u;
}

void unioN(int x,int y)
{
    if(parent[x].members<parent[y].members)
    {
        parent[x].id=parent[y].id;
        parent[y].members+=parent[x].members;
    }
    else
    {
        parent[y].id=parent[x].id;
        parent[x].members+=parent[y].members;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    //o0badboy0o

    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edges.insert(mp(c,mp(a,b)));
    }

    for(int i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
    }

    int e=0;
    for(auto edge : edges)
    {
        int set1=edge.s.f;
        int set2=edge.s.s;
        
        int x=root(set1);
        int y=root(set2);

        if(x!=y)
        {
            mst.insert(edge);
            unioN(x,y);
            e++;
        }
        if(e==n-1) break;
    }

    for(int i=0;i<q;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>a>>b;
            mst.insert(mp(0,mp(a,b)));
        }
        else if(type==2)
        {
            cin>>a>>b;
            mst.erase(mp(0,mp(a,b)));
        }
        else
        {
            int ans=0;
            int e=0;
            for(int i=1;i<=n;i++)
            {
                parent[i].id=i;
                parent[i].members=1;
            }

            for(auto edge : mst)
            {
                int set1=edge.s.f;
                int set2=edge.s.s;
                
                int x=root(set1);
                int y=root(set2);
                
                if(x!=y)
                {
                    e++;
                    ans+=edge.f;
                    unioN(x,y);
                }
                if(e==n-1) break;
            }

            cout<<ans<<"\n";
        }
    }

    return 0;
}
