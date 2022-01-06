#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param data - informatia nodului respectiv
 * @param next - adresa urmatorului nod
 * @return node* nou nod creat
 */
node *makeNode(int data, node *next){
    node* stack = (node*)malloc(sizeof(node));

    stack->data = data;
    stack->next = next;
    
    if(stack == NULL){
        return NULL;
    }

    return stack; 

}



/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */

node *makeList(FILE *file){

    int aux;
    node *first;

    fscanf(file,"%d",&aux);
    first = makeNode(aux,NULL);
    

    while(fscanf(file, "%d", &aux) != EOF){

        if(first->data <= aux){
            first = makeNode(aux,first);
        }
        
        if(first == NULL){
            free(first);
            return NULL;
        }
    }
return first;
  
}


/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat
 */
void print(node *head)
{
    // Nice to have - pentru testare locala in main
}