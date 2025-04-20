#include <stdio.h>
#include "ALGraph.h"
int main(int argc, char** argv)
{
	Graph graph;
	GraphInit(&graph, 7);
	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);
	ShowGraphInfo(&graph);
	DFSearch(&graph, A);
	putchar('\n');
	DFSearch(&graph, C);
	putchar('\n');
	DFSearch(&graph, E);
	putchar('\n');
	DFSearch(&graph, G);
	putchar('\n');
	GDestroy(&graph);
	return 0;
}