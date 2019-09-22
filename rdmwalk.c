#include <stdlib.h>
#include "rdmwalk.h"
#include "time.h"

int walk(walker *w, Graph G, float random){
    float acum = 0.0;

    //Paga o custo no nodo atual
    w->balance = w->balance - G->v_list[w->vertex_id]->cost;

    if(!G->adj[w->vertex_id])
    //if(w->vertex_id == 4)
        return -1;

    // decide para onde vai
    for (link a = G->adj[w->vertex_id]; a != NULL; a = a->next){
        if( random <= a->probability * 100 + acum ){
            w->vertex_id = a->w->id;
            printf("\nFui para: %d\n", a->w->id);
            break;
        }else
            acum = acum + a->probability * 100;
    }

    return 0;
}

void sim(walker *w, Graph G, int m){
    int a = 0;
    srand(time(NULL)*time(NULL));
    int rand1 = rand()%10000;
    float random = rand1 / 100.00;
    float result = 0;
    int starting_point = w->vertex_id;
    int k=0;

    for(int j = 0; j < m; j++){
        w->vertex_id = starting_point;
        k++;
        printf("\nUma Rodada %d\n",k);
        a = 0;
        w->balance = 0;
        while(a == 0){
            rand1 = rand()%10000;
            random = rand1 / 100.00;
            a = walk(w,G,random);
        }
        result = result + w->balance;
    }

    result = result / m;
    w->balance = result;
}
