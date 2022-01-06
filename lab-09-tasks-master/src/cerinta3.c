#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati algoritmul Floyd-Warshall pentru un graf cu matricea de adiacenta data
 * @param  g: graful dat
 * @retval - Matricea costurilor pentru toate nodurile
 */
int **Floyd_Warshall(Graph *g){
    int i, j,k,z,m;
    int c[g->V][g->V];

    for ( i = 0; i < g->V; i++){
        for ( j = 0; j < g->V; j++){
            if(g->a[i][j] != 0)
                c[i][j] = g->a[i][j];

            else
                 c[i][j] = INF;
        }
    }


    for (z = 0; z< g->V ; z++){
        for (i = 0; i < g->V ; i++){
            for (j = 0; j < g->V ; j++){
                if (c[i][j] > c[i][z]+c[z][j]) 
                    c[i][j] = c[i][z]+c[z][j];
            }
        }
    }

}