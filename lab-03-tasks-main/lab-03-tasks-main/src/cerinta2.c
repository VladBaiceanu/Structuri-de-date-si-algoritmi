#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce elimina elementele cu informatii duplicate
 * Hint:
 *      * parcurgeti lista si modificati nodurile a.i sa elimi-
 *        nati duplicatele
 *      * daca capul listei nu se modifica va trebuii 
 *        sa il returnati
 * 
 * @param list - capul listei ce trebuie sa fie procesata
 * @return node* - returneaza capul listei
 */
node *removeDuplicates(node *list)
{
    node *ptr, *aux, *copy;
    ptr = list;

    while(ptr != NULL){
        aux = ptr->next;
        copy = ptr;

        if(aux == NULL){
            return list;
        }
        
        while(aux != NULL){
            if(ptr->data == aux->data){
               copy->next = aux->next;
               free(aux);
               aux = NULL;
               aux = copy->next;

            }
            else{
                copy = aux;
                aux = aux->next;
            }
        }
        
        ptr = ptr->next;
    } 

    return list;
}



