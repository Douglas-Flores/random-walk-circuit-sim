#ifndef _rdmwalk_h
#define _rdmwalk_h

#include "graph.h"
#include "time.h"

struct rdm_walker {
    float balance;
    int vertex_id;
};
typedef struct rdm_walker walker;

int walk(walker *w, Graph G, float random);
void sim(walker *w, Graph G, int m);

#endif
