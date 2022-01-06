#include "utils.h"
#include "queue.h"
#include "queue_node.h"


/**
 * @brief Functie ce aloca dinamic memorie pentru coada,
 *        initializand campurile front si rear
 * 
 * @param queue - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru coada
 */
void createQueue(Queue **queue)
{
    *queue = (Queue*)malloc(sizeof(Queue));

    (*queue)->front = NULL;
    (*queue)->rear = NULL;

}

/**
 * @brief Functie ce va fi folosita pentru a adauga un nod in coada queue
 * 
 * * Hint:
 *         * se va folosi functia createQueueNode pentru crearea unui nou nod
 *         * trebuie actualizati poniterii rear si front sau doar front
 *         * a se citi cursul :)
 * 
 * @param queue - coada in care trebuie adaugat un nou nod cu informatia data
 * @param data - datele noului nod
 */
void en(Queue *queue, char *data)
{
    queue_node* flag = (queue_node*)malloc(sizeof(queue_node*));

    flag->data = data;
    flag->next = NULL;

    if(queue->rear == NULL){
        
        queue->rear = flag;
    }

    else{
        (queue->rear)->next = flag;
        (queue->rear) = queue->rear->next;
    }

    if(queue->front == NULL){
        queue->front = queue->rear;

    }
}

/**
 * @brief Functie ce scoate din coada urmatorul nod si
 *        returneaza datele stocate in nod.
 * * Hint:
 *        * a se citi cursul :)
 * 
 * @param queue - coada din care va fi scos nodul 
 * @return char* - datele din interiorul nodului
 */
char *de(Queue *queue){

    queue_node* aux;

    aux = queue->front;
    char* info = (char*)malloc(sizeof(char)*strlen(aux->data));
    strcpy(info,aux->data);

    queue->front = queue->front->next;
    free(aux);
    return info;
}

/**
 * @brief Functie ce va elibera memoria asociata fiecarui nod al cozi
 *  
 *  * Hint:
 *          * se poate folosi functia deleteQueueNode
 * @param queue - coada a carui noduri vor fi sterse
 */
void deleteQueue(Queue *queue){
    // Nice to have
}

/**
 * @brief Functie ce testeaza pointerii rear si front pentru 
 *        a determina daca coada este goala
 * 
 * @param queue - coada ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyQueue(Queue *queue)
{
  return ((queue->front == NULL) && (queue->rear == NULL));

}
