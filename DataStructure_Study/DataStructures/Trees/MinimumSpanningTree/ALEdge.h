#ifndef __ALEDGE_H__
#define __ALEDGE_H__

#include "Vertex.h"

typedef struct
{
	Vertex v1;
	Vertex v2;
	int weight;
} ALEdge;

typedef ALEdge Edge;

#endif