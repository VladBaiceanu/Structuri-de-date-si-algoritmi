#include "utils.h"


/**
 * TODO:   O functie ce transforma un graf reprezentat de o matrice de adiacenta 
 * intr-unul reprezentat cu ajutorul listelor de adiacenta
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - Graful in reprezentarea liste de adiacenta
 */
graph_list* matrixToList(graph_matrix* graph){

    int i,j;
    graph_list* list = (graph_list*)malloc(sizeof(graph_list));

    list->V = graph->V;
    list->listHeads = (node**)calloc(graph->V, sizeof(node*));
    list->E = graph->E;


    for(i=0; i < graph->V; i++){
        for(j=0; i < graph->V; j++){
            if(graph->matrix[i][j] == 1){
                list->listHeads[i] = push_values(list->listHeads[i],j);
            }
        }
    }
    return list;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_matrix(graph_matrix** graph){
    int i;
    for(i=0; i < (*graph)->V; i++){
        free((*graph)->matrix[i]);
    }
    free((*graph));
    *graph = NULL;
}


node* push_values(node* root, int val) {

    if(root == NULL){
        node* aux = (node*)malloc(sizeof(node));
        aux->next = NULL;
        aux->vertexNr = val;
        return aux;
    }
    root->next = push_values(root->next, val);
    return root;
}


void print_graph_list(graph_list* graph) {
}



