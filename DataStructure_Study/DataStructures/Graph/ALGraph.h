#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include "SimpleLinkedList.h"
#include "Vertex.h"

typedef struct
{
	int numV; // Number of vertices
	int numE; // Number of edges
	List* adjList; // List containing adjacent vertices
} ALGraph;

typedef ALGraph Graph;

void GraphInit(Graph* pg, int nv);
void AddEdge(Graph* pg, Vertex fromV, Vertex toV);
void ShowGraphInfo(Graph* pg);
void GDestroy(Graph* pg);

#endif