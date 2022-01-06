#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati o functie care citeste dintr-un fisier de intrare
 * nr-ul de varfuri, muchii, iar pe urmatoarele linii
 * nod u, nod v si distanta[u][v], pentru a putea reprezenta ulterior matricea de adiacenta
 * @param  input: fisierul de intrare
 * @note   -Atentie! Nu redeschideti fisierul de intrare
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
Graph* createGraph(FILE *input){
    int u,v,dist,i;
    graph = (Graph *)malloc(sizeof(Graph));
    fscanf(input,"%d", &graph->E);
    fscanf(input,"%d", &graph->V);

    graph->mat = (int **)calloc(sizeof(int *), graph->V);

    for (i = 0; i < graph->V; i++){
        graph->mat[i] = (int *)calloc(sizeof(int), graph->V);
    }
 
    for(i = 0;i<graph->E;i++){
        fscanf(input,"%d %d %d",&u,&v,&dist);
        graph->mat[v][u]= dist;
        graph->mat[u][v]= dist;
    }

    return graph;
}
/**
 * TODO: Implementati functia de afisare a matricei de adiacenta
 * @param  g: graful creat anterior
 * @note : Nice to have
 * @retval - None
 */
void printMat(Graph *g){
   
}