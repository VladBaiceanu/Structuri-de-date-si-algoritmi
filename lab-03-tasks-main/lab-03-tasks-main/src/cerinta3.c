#include "list.h"
#include "utils.h"



/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param number - numarul pe care il are copilul
 * @param name - numele copilului
 * @param next  - adresa urmatorului nod
 * @return childNode* - nou nod creat
 */
childNode *makeChildNode(int number, const char *name, childNode *next){

    childNode* list = (childNode*)malloc(sizeof(childNode));
    list->number = number;
    if(list == NULL){
        return NULL;
    } 

    list->name = (char*)malloc(sizeof(char)*strlen(name));
    strcpy(list->name,name);
    if(list->name == NULL){
        free(list);
        return NULL;
    }
    list->next = next;

    return list;

}




/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeChildNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return childNode* 
 */
childNode *makeCircularList(FILE *file){

    childNode *head, *aux;
    int numar;
    char nume[100];

    fscanf(file,"%d %s",&numar,nume);
    head = makeChildNode(numar,nume,NULL);
    aux = head;

    while(fscanf(file,"%d %s",&numar,nume) != EOF){
        head = makeChildNode(numar,nume,head);

        if(head == NULL){
            free(head);
            free(head->name);
            return NULL;
        }
    }
    aux->next = head;

    return head;

    
}


/**
 * @brief Functie ce 
 * 
 * @param head - capul listei ce reprezinta cercul de copii
 * @param p - pasul ce va fi luat pentru eliminarea copiilor
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p){

    childNode *curr, *prev, *second_list;

    curr = head;
    int i;
    if(head == NULL){
        return NULL;
    }
       
    second_list = NULL;

    while (curr->next != curr){
        i = 1;
        while (i != p){
            prev = curr;
            i++;
            curr = curr->next;
        }

        prev->next = curr->next;
        second_list = makeChildNode(curr->number,curr->name,second_list);
        free(curr->name);
        free(curr);
        curr = prev->next;
    }
    second_list = makeChildNode(curr->number,curr->name,second_list);
    return second_list;
    // cu complexitatea O(1) a copiilor in ordinea in care 
    // sunt eliminati
}