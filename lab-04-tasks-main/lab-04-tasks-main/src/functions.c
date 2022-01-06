#include "functions.h"
#include "utils.h"

/**
 * @brief Functie ce testeaza daca cuvantul primit ca parametru este "stop"
 * 
 *  * Hint:
 *          * puteti folosi functia strcmp(...) pentru comparare de siruri de caractere
 * 
 * @param word cuvantul ce trebuie testat
 * @return true/false in functie de rezultatul comparatiei cu "stop" 
 */
bool isNotStop(const char *word)
{

}

/**
 * @brief Functie ce citeste cuvant cu cuvant din fisierul primit ca parametru, adauga fiecare cuvant citit in coada
 *        pana la intalnirea cuvantului "stop"
 * 
 * * Hint:
 *      * se vor implementa mai intai functiile asociate stivei si cozi
 * 
 * @param queue - coada ce trebuie populata cu cuvinte
 * @param file - fisierul din care se face citirea
 */
void readInputIn(Queue *queue, FILE *file)
{
    char word[50];

    while(fscanf(file,"%s",word) != EOF){
        if(strcmp(word,"stop") == 1){
            en(queue,word);
        }
    }
}

/**
 * @brief Functie ce parcurge coada de cuvinte, populeaza o stiva pentru inversarea cuvantului,
 *        dupa inversarea cuvantului continutul stivei este transferat in stiva results cu ajutorul
 *        operatiilor pop/push
 * * Hint:
 *      * se vor implementa mai intai functiile asociate stivei si cozi
 *      * detaliile de functioare se gasesc si in sectiunea HINTURI din README
 * 
 * @param queue - coada de cuvinte ce trebuie procesata
 * @param results - stiva ce contine rezultatul final al inversarii oridini cuvintelor
 */
void processInput(Queue *queue, Stack *results)
{
    Stack *temp;
    Queue *flag;

    createStack(&temp);
    createQueue(&flag);

    while(! isEmptyQueue(queue)){
        en(flag,queue->rear->data);
        de(queue);
    }
    int i;
    while(! isEmptyQueue(flag)){
        for(i=0; i < strlen(flag->rear->data); i++){
            push(temp,flag->rear->data[i]);
        }
        while(isEmptyStack(temp)){
            push(results,pop(temp));
        }
        de(flag);
    
}
}
