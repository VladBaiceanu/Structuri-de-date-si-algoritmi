#include "heap.h"

/**
 * TODO: Alocati memorie si cititi datele din fisier
 * @param  **v: vectorul cu datele citite
 * @param  dimensiune: dimensiunea vectorului
 * @param  input: fisierul de intrare
 * @retval None
 */
void readVector(int **v, int dimensiune, FILE *input)
{
    *v = (int*)malloc(sizeof(int)*dimensiune);

    int i;

    for(i=0; i < dimensiune; i++){
        fscanf(input,"%d",(*v)+i);
    }

}

/** 
 * TODO:   Stergeti elementul de pe pozitia i din heap
 * @param  *h: heap binar 
 * @param  i: index-ul elementului ce trebuie sters din heap
 * @retval None
 */
void deleteNode(Heap *h, int i)
{
    int k;

    k = h->vec[h->size - 1];
    h->vec[i] = k;
    h->size--;

    heapify(h, h->vec[0]);
	
}
/**
 * TODO: Implementati algoritmul heapsort
 * @param  *h: heap-ul binar ce contine datele vectorului sortat
 * @param  *buf: vectorul ce trebuie sortat
 * @param  dimensiune: dimensiunea vectorului ce trebuie sortat
 * @retval None
 */
void heapsort(Heap *h, int *buf, int dimensiune)
{
    int i,aux;

    if (h == NULL || buf == NULL || dimensiune == 0){
        return;
    }

    while (dimensiune > h->capacity){
        resize(h);
    }

    for (int i = 0; i < dimensiune; i++){
        h->vec[i] = buf[i];
    }

     h->size = dimensiune;

    for (i = (dimensiune-1)/2 - 1; i >= 0; i--){
        heapify(h, i);
    }

     for (i = dimensiune-1; i >= 0; i--){
        aux = h->vec[0];
        h->vec[0] = h->vec[i];
        h->vec[i] = aux;
        h->size = i;

        heapify(h, 0);
    }
    h->size = dimensiune;
    printHeap(h);
}
