#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
int WhoPrecedes(Vertex v1, Vertex v2)
{
	return v1 > v2 ? 1 : 0;
}
int Visitvertex(Graph* pg, Vertex visitV)
{ // Returns whether visiting was successful
	if(pg->visitInfo[visitV] == 0)
	{ // Case when visitV was never visited
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 'A');
		return TRUE;
	}
	return FALSE; // Returns FALSE if visitV was visited
}
// Below are header file functions
void GraphInit(Graph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->visitInfo = (int*)calloc(sizeof(int), nv); // All set to 0
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	for(int i = 0; i < nv; i++)
	{
		ListInit(&pg->adjList[i]); // Initializing all adjacent vertices lists
		SetSortRule(&(pg->adjList[i]), WhoPrecedes); // Initializing sorting rule
	}
	return;
}
void AddEdge(Graph* pg, Vertex fromV, Vertex toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV); // Undirected graph needs double addings
	(pg->numE)++;
	return;
}
void ShowGraphInfo(Graph* pg)
{
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
void DFSearch(Graph* pg, Vertex startV)
{
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
void GDestroy(Graph* pg)
{
	for(int i = 0; i < pg->numV; i++)
		RemoveAll(&(pg->adjList[i]));
	free(pg->adjList);
	free(pg->visitInfo);
	return;
}