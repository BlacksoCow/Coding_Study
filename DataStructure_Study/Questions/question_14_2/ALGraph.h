#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#define TRUE 1
#define FALSE 0
#include "SimpleLinkedList.h" // For adjList
#include "ArrayStack.h" // For DFS
#include "Vertex.h" // Information of vertices

typedef struct
{
	int numV; // Number of vertices
	int numE; // Number of edges
	int* visitInfo; // Array for checking whether vertex was visited
	List* adjList; // List containing adjacent vertices
} ALGraph;

typedef ALGraph Graph;

void GraphInit(Graph* pg, int nv);
void AddEdge(Graph* pg, Vertex fromV, Vertex toV);
void ShowGraphInfo(Graph* pg);
void DFSearch(Graph* pg, Vertex startV);
void GDestroy(Graph* pg);

#endif