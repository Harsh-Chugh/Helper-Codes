/*    These are some good tips which i got from someone's code while stalking at Codeforces

On getting WA:
* Check if implementation is correct and NOTHING overflows.
* Start thinking about counter cases for your logic as well as implementation.
* Try removing redundancy (any additon you might have done for ease of 
implementation or thought process) and putting asserts.
* Make a generator, an unoptimized but correct soln and run it against wrong soln.
* When there a few values and we have to perform certain operations (mostly in game 
theory), start looking for patterns in the answer in small values

If nothing comes to mind:
* Binary search over the ans
* Think about more strong greedy
* Think about bipartition, levels, adding/removing edges/nodes, degree 
in trees and graphs
* Try reducing the constraints or chaning the frame of reference and 
then solving (mostly useful in DP/combinatorics) 
*/






#include<bits/stdc++.h>
#define INF  1e9 + 10
using namespace std;
// bool visited[100005]={false};
// vector<int> graph[100005];
int level[100005]={0};


// bfs and level of node
void bfs(int source)
{
	queue<int> q;
	q.push(source);
	visited[source]=true;

	while(!q.empty())
	{
		int cur_v=q.front();
		q.pop();

		cout<<cur_v<<' ';

		for(int child : graph[cur_v])
		{
			if(visited[child])
				continue;

			q.push(child);
			visited[child]=true;
			level[child]=level[cur_v]+1;
		}
	}
}



// dfs
void dfs(int vertex)
{
	visited[vertex]=true;

	for(int child : graph[vertex])
	{
		if(visited[child])
			continue;

		dfs(child);
	}
}





// dfs for detecting cycle
bool dfs(int vertex,int par)
{

	visited[vertex]=true;
	bool isLoop_exists=false;
	for(auto child : graph[vertex])
	{
		if(visited[child] && child==par)
			continue;
		
		if(visited[child])
			return true;

		isLoop_exists |= dfs(child,vertex);
	}

	return isLoop_exists;
}




// dijkstra 
vector<pair<int,int>> g[100005];
void dijkstra(int source)
{
	 vector<bool> vis(100005,false);
    vector<int> dist(100005,INF);

    set<pair<int,int>> st;
    st.insert({0,source});
    dist[source]=0;

    while((int)st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(node);
            
        int cur_v=node.second;
        int v_dist=node.first;

        if(vis[cur_v])
            continue;

        vis[cur_v]=true;




        for(auto child : g[cur_v])
        {
            int child_v=child.first;
            int wt=child.second;

            if(dist[cur_v] + wt <dist[child_v])
            {
                dist[child_v] = dist[cur_v] + wt;

                st.insert({dist[child_v],child_v});
            }
        }
    }

}


int main()
{


	int n,e;
	cin>>n>>e;

	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	// count connected components in a graph
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt<<endl;


	// Detect isthere any cycle in Graph
	bool isLoop_exists=false;
	for(int i=0;i<n;i++)
	{
		if(visited[i])
			continue;

		if(dfs(i,-1))
		{
			isLoop_exists=true;
			break;
		}
	}

	if(isLoop_exists)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;



	bfs and level of node
	bfs(1);
	cout<<endl;
	for(int i=1;i<=13;i++)
		cout<<i<<' '<<level[i]<<endl;





	// dijkstra
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int x,y,wt;
		cin>>x>>y>>wt;

		// directed graph
		g[x].push_back({y,wt});


	}


	return 0;

}