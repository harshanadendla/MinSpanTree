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
const int N=1e6+1;
const int mod=1e9+7;

struct ds
{
    int id,members;
};

int n,m,ans,a,b,c;
ds parent[N];
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> edges;

int find(int u)
{
    while(u!=parent[u].id) u=parent[u].id;
    return u;
}

void unioN(int x,int y)
{
    if(parent[x].members < parent[y].members)
    {
        parent[x].id=parent[y].id;
        parent[y].members+=parent[x].members;
        parent[x].members=0;
    }
    else
    {
        parent[y].id=parent[x].id;
        parent[x].members+=parent[y].members;
        parent[y].members=0;
    }
}

int mst()
{
    int e=0;

    for(int i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
    }

    while(e<n-1)
    {
        auto edge=edges.top();
        edges.pop();

        int set1=edge.s.f;
        int set2=edge.s.s;

        if(find(set1)!=find(set2))
        {
            e++;
            ans+=edge.f;
            unioN(set1,set2);
        }
    }

    return ans;
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

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edges.push(mp(c,mp(a,b)));
    }

    cout<<mst();

    return 0;
}