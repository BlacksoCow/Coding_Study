#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
// Below are source file functions
int VertexSort(Vertex v1, Vertex v2)
{ // Function for sorting vertices in alphabetical order in adjList
	return v1 > v2 ? 1 : 0;
}
int WeightSort(Edge e1, Edge e2)
{ // Function for sorting weight in decreasing order in weightHeap
	return e1.weight - e2.weight;
}
int Visitvertex(Graph* pg, Vertex visitV)
{ // Returns whether visiting was successful
	if(pg->visitInfo[visitV] == 0)
	{ // Case when visitV was never visited
		pg->visitInfo[visitV] = 1;
		return TRUE;
	}
	return FALSE; // Returns FALSE if visitV was already visited
}
void RemoveWay(Graph* pg, Vertex fromV, Vertex toV)
{ // Removes one way from fromV to toV
	Vertex nextV;
	if(LFirst(&(pg->adjList[fromV]), &nextV))
	{ // Searching target edge in graph
		if(nextV == toV)
			LRemove(&(pg->adjList)[fromV]);
		else
		{
			while(LNext(&(pg->adjList[fromV]), &nextV))
			{
				if(nextV == toV)
				{
					LRemove(&(pg->adjList)[fromV]);
					break;
				}
			}
		}
		return;
	}
	puts("Edge doesn't exist: Removing failed");
	return;
}
void RemoveEdge(Graph* pg, Edge edge)
{ // Removes target edge in graph
	RemoveWay(pg, edge.v1, edge.v2);
	RemoveWay(pg, edge.v2, edge.v1); // Double removal for undirected graph 
	(pg->numE)--;
	return;
}
int IsConnected(Graph* pg, Vertex v1, Vertex v2)
{ // Checks whether target vertices are connected with edges using DFS
	Stack stack;
	StackInit(&stack);
	Vertex visitV = v1; // Starting vertex
	Visitvertex(pg, visitV);
	SPush(&stack, visitV);
	Vertex nextV;
	while(LFirst(&(pg->adjList[visitV]), &nextV))
	{
		int visitFlag = FALSE;
		if(nextV == v2)
		{ // Destination vertex found
			for(int i = 0; i < pg->numV; i++)
				pg->visitInfo[i] = 0; // Reinitializing visitInfo array to 0
			return TRUE;
		}
		if(Visitvertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while(LNext(&(pg->adjList[visitV]), &nextV))
			{ // Attempting to visit other connected vertices
				if(nextV == v2)
				{ // Destination vertex found
					for(int i = 0; i < pg->numV; i++)
						pg->visitInfo[i] = 0; // Reinitializing visitInfo array to 0
					return TRUE;
				}
				else if(Visitvertex(pg, nextV) == TRUE)
				{ // If nextV's visiting is successful
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		} // All attempts to visit connected vertices completed
		if(visitFlag == FALSE)
		{ // Only works when every visit attempt failed
			if(SIsEmpty(&stack))
				break; // DFS completed
			else
				visitV = SPop(&stack); // Resetting visitV as prior vertex
		}
	}
	for(int i = 0; i < pg->numV; i++)
		pg->visitInfo[i] = 0; // Reinitializing visitInfo array to 0
	return FALSE;
}
void RecoverEdge(Graph* pg, Edge edge)
{ // Recovering(Adding) target edge into graph
	Vertex fromV = edge.v1;
	Vertex toV = edge.v2;
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
	return;
}
// Below are header file functions
void GraphInit(Graph* pg, int nv)
{ // Initialization of graph after graph strcutrue is created
	pg->numV = nv;
	pg->numE = 0;
	pg->visitInfo = (int*)calloc(sizeof(int), nv); // All set to 0
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	for(int i = 0; i < nv; i++)
	{
		ListInit(&pg->adjList[i]); // Initializing all adjacent vertices lists
		SetSortRule(&(pg->adjList[i]), VertexSort); // Initializing sorting rule
	}
	HeapInit(&(pg->weightHeap), WeightSort); // Initializing weight heap
	return;
}
void AddEdge(Graph* pg, Vertex fromV, Vertex toV, int weight)
{ // Adds edge that connects fromV to toV into graph 
	Edge edge = {fromV, toV, weight};
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV); // Undirected graph needs double addings
	HInsert(&(pg->weightHeap), edge); // Inserting weight into weightHeap
	(pg->numE)++;
	return;
}
void ShowGraphInfo(Graph* pg)
{ // Prints every connected vertex per vertex
	Vertex v;
	for(int i = 0; i < pg->numV; i++)
	{
		if(LFirst(&(pg->adjList[i]), &v))
		{
			printf("Vertices connected with %c:", i + 'A');
			printf(" %c", v + 'A');
			while(LNext(&(pg->adjList[i]), &v))
				printf(" %c", v + 'A');
			putchar('\n');
		}
		else
			printf("%c has no connection\n", i + 'A');
	}
	return;
}
void ShowEdgeInfo(Graph* pg)
{ // Prints information of every edge in graph
	Heap copyHeap;
	HCopy(&copyHeap, &(pg->weightHeap)); // Duplication to prevent changes of real Heap
	Edge edge;
	while(!HIsEmpty(&copyHeap))
	{
		edge = HDelete(&copyHeap);
		printf("Edge: %c - %c, Weight: %d\n", edge.v1 + 'A', edge.v2 + 'A', edge.weight);
	}
	return;
}
void DFSearch(Graph* pg, Vertex startV)
{ // Traverses every vertices starting from startV by DFS
	Stack stack;
	StackInit(&stack);
	SPush(&stack, startV); // First push for ending situation
	Vertex visitV = startV;
	Visitvertex(pg, visitV); // Starting vertex is vistited
	Vertex nextV;
	while(LFirst(&(pg->adjList[visitV]), &nextV))
	{ // Loops until stack gets empty
		int visitFlag = FALSE;
		if(Visitvertex(pg, nextV) == TRUE)
		{ // First connected vertex visit successful
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{ // Attempting to visit other connected vertices
			while(LNext(&(pg->adjList[visitV]), &nextV))
			{ // If nextV's visiting is successful
				if(Visitvertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		} // All attempts to visit connected vertices completed
		if(visitFlag == FALSE)
		{ // Only works when every visit attempt failed
			if(SIsEmpty(&stack))
				break; // DFS completed
			else
				visitV = SPop(&stack); // Resetting visitV as prior vertex
		}
	}
	for(int i = 0; i < pg->numV; i++)
		pg->visitInfo[i] = 0; // Reinitializing visitInfo array to 0
	return;
}
void CreateMST(Graph* pg)
{ // Removes edges until graph becomes MST using kruskal algorithm
	int index = 0;
	Edge edge;
	Edge recoverEdge[pg->numE]; // Saving recovered edges
	while(pg->numE > pg->numV - 1)
	{ // Removing edges starting from lastget weight
		edge = HDelete(&(pg->weightHeap));
		RemoveEdge(pg, edge);
		if(!(IsConnected(pg, edge.v1, edge.v2)))
		{ // If removing edge results in connection loss, recover edge
			RecoverEdge(pg, edge);
			recoverEdge[index++] = edge;
		}
	}
	for(int i = 0; i < index; i++)
		HInsert(&(pg->weightHeap), recoverEdge[i]); // Recovering edges back to heap
	return;
}
void GDestroy(Graph* pg)
{ // Destroys every dynamic allocation used in graph and itself
	for(int i = 0; i < pg->numV; i++)
		RemoveAll(&(pg->adjList[i]));
	free(pg->adjList);
	free(pg->visitInfo);
	return;
}