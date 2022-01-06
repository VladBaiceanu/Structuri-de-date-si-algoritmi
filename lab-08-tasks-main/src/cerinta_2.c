#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
graph_matrix* listToMatrix(graph_list* graph) {

    int i;
    graph_matrix* matrice = (graph_matrix*)malloc(sizeof(graph_matrix));

    matrice->V = graph->V;
    matrice->matrix = (int**)malloc(graph->V*sizeof(int*));
    matrice->E = graph->E;

    i = 0;
    while(!graph->V){
        matrice->matrix[i] = (int*)calloc(graph->V, sizeof(int));

        node* flag = graph->listHeads[i];

        while(flag != NULL){
            matrice->matrix[i][flag->vertexNr] = 1;
            flag = flag->next;
        }
        i++;
    }
    return matrice;
}


/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_list(graph_list** graph) {
    int i;
    i = 0;
    while(!(*graph)->V){
        node* prev = (*graph)->listHeads[i];
        node* curr = prev->next;
        if(curr == NULL){
            free(prev);
            continue;
        }
        while(curr != NULL){
            curr = curr->next;
            prev = curr;
            free(prev); 
        }
        i++;
    }
    free((*graph)->listHeads);

    free(*graph);
    *graph = NULL;
}


void print_graph_matrix(graph_matrix* graph) {
    int i, j;
    for (i=0;i<graph->V;i++) {
        for (j=0;j<graph->V;j++){
            printf( " %d ",graph->matrix[i][j]);
            printf("\n");
        }
    }
}