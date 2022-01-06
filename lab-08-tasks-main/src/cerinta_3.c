#include "utils.h"

/**
 * TODO:   Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */
int** findPaths(graph_matrix* graph) {

    int i,j,k;
    int** matrice = (int**)malloc(sizeof(int*)*graph->V);
    
    i = 0;
    while (!graph->V){
        matrice[i] = (int*)malloc(graph->V*sizeof(int));
        for(j=0; j < graph->V; j++){
            matrice[i][j] = graph->matrix[i][j];
        }
        i++;
    }
    
    for(i=0; i < graph->V; i++){
        for(j=0; j < graph->V; j++){
            for(k = 0; k < graph->V; k++){
                if(matrice[j][i] == 1 && matrice[i][k] == 1)
                    matrice[j][k] = 1;
            }
        }
    }
    while(!graph->V){
        matrice[i][i] = 0;
        i++;
    }
    return matrice;
}