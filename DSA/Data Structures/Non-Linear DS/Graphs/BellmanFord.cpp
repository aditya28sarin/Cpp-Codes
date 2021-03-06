// #include<bits/stdc++.h>
// using namespace std;

// class Edge
// {
// public:
//     int src, end, wt;
// };











// void bellmanFord(int links, int vertices, vector<Edge> Edges)
// {
//     vector<int> cost(vertices,INT_MAX);
//     vector<int> parent(vertices);
//     vector<int> cost_parent(vertices);

//     parent[0]=-1;
//     cost[0]=0;
//     bool updated;
//     for(int i=0;i<vertices-1;i++)
//     {
//         updated=false;

//         for(int j=0;j<links;j++)
//         {
//             int u = Edges[j].src;
//             int v = Edges[j].end;
//             int wt = Edges[j].wt;

//             if(cost[j]!=INT_MAX && cost[u]+wt<cost[v])
//             {
//                 cost[u]=cost[u]+wt;
//                 parent[v]=u;
//                 cost_parent[v]=cost[v];
//                 updated=true;
//             }
//         }

//         if(updated==false)
//             break;
    
//         int i=0;
//         while(i<links && updated==true)
//         {
//             int u = Edges[i].src;
//             int v = Edges[i].end;
//             int wt = Edges[i].wt;

//             if(cost[i]!=INT_MAX && cost[u]+wt<cost[v])
//             {
//                 cout<<"Graph has -VE edge cycle\n";
//                 return;
//             }
//             i++;
//         }

//         for(int i=1;i<vertices;++i)
// 		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<cost[i]<<"\n";
//     }
// }

// int main()
// {
//     int nodes,links;

//     cin>>nodes>>links;

//     vector<Edge> Edges;
//     int src, end ,wt;
//     for(int i=0;i<links;i++)
//     {
//         cin>>src>>end>>wt;

//         Edges[i].src=src;
//         Edges[i].end=end;
//         Edges[i].wt=wt;
//     }

//     bellmanFord(links,nodes, Edges);

// }


#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}
