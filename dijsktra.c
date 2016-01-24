/*
Dijkstra's algorithm for finding the shortest distance from the source to all nodes
*/

#include <stdio.h>
#include <stdlib.h>
#define V 9
#define INF 32767

int find_closest_node(int dist[V], int q[V])
{
	int min_dist = INF;
	int min_index, i;
	for(i=0;i<V;i++)
	{
		// find closest node from q
		if(dist[i]<min_dist && q[i]==1)
		{
			min_index = i;
			min_dist = dist[i];
		}
	}
	return min_index;
}

void dijkstra(int graph[][V] , int src)
{
	// maintain the shortest distance from source
	int* dist = (int*)malloc(V*sizeof(int));
	int i,j;
	for(i=0;i<V;i++)
	{
		dist[i] = INF;
	}
	dist[src] = 0;

	// maintain a set q for all elements whose shortest distance has not been found
	int q[V] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	int close_node;
	for(j=0;j<V;j++)
	{
		close_node = find_closest_node(dist, q);
		q[close_node] = 0;
		for(i=0;i<V;i++)
		{
			if(q[i]==1 && graph[close_node][i]!=0)
			{
				if(graph[close_node][i]+dist[close_node] < dist[i])
				{
					dist[i] = graph[close_node][i]+dist[close_node];
				}
			}
		}
	}	

	for(i=0;i<V;i++)
	{
		printf("%d ", dist[i]);
	} 
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
 
    return 0;
}