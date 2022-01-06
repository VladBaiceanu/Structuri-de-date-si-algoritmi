#include "heap.h"
#include <stdbool.h>
/**
 * TODO: Implementati functia de creare MinHeap avand o capacitate data
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
MinHeap* create(int capacitate) {
    Heap *h = (Heap *)malloc(sizeof(Heap));

    if (h == NULL){
        return NULL;
    }

    h->size = 0;
    h->arr = (HeapNode **)malloc(sizeof(HeapNode *) * h->capacity);
    h->capacity = capacitate;
    h->poz = (int *)calloc(capacitate,sizeof(int));

    if (h->arr == NULL){
        return NULL;
    }

    return h;
	
}

/**
 * TODO: Implementati functia de creare HeapNode 
 * @param  v:  varful care trebuie adaugat
 * @param dist: distanta rezultata in urma implementarii algoritmului Dijkstra
 * @retval - HeapNode-ul creat
 */
HeapNode *createHeapNode(int v, int dist) {
    HeapNode *h;
    h = (HeapNode *)malloc(sizeof(HeapNode));
    h->distanta = dist;
    h->v = v;

    return h;
   
}

/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din MinHeap
 * @param  heap: MinHeap-ul
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */

int parent(MinHeap *heap, int i) {
	if (i > heap->size - 1 || i <= 0){
		return -1;
	}

	return (i - 1) / 2;
}
/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */

int leftChild(MinHeap *heap, int i) {
 int pos = 2*i + 1;

    if (pos > heap->size - 1 || i < 0){
        return -1;
    }

    return pos;
  
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(MinHeap *heap, int i) {
	int pos = 2 * i + 2;

	if (pos > heap->size - 1 || i < 0){
		return -1;
	}

	return pos;
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap   
 * @param  heap: MinHeap-ul
 * @retval - HeapNode-ul in care este stocata radacina
 */
HeapNode* returnRoot(MinHeap *heap) {

	return heap->vec[0];
   
}

/**
 * TODO: Implementati functia heapify
 * @param  heap: MinHeap-ul
 * @param  i: pozitia de pe care se doreste
 * @retval None
 */
void heapify(MinHeap *heap, int i) {
    int right, left,min;
	while(true){
        min = i;
        left = leftChild(heap, i);
        right = rightChild(heap, i);
        HeapNode *aux;

        if (left == -1 && right == -1){
            return;
        }

        if(right != -1 && heap->arr[min]->distanta > heap->arr[right]->distanta){
            min = right;
        }

        if(left != -1 && heap->arr[min]->distanta > heap->arr[left]->distanta){
            min = left;
        }

        }

        if(min != i){
            aux = heap->arr[i];
            heap->arr[i] = heap->arr[min];
            heap->arr[min] = aux;
            i = min; 
        }

    }
}
/**
 * TODO: Implementati functia de redimensionare a MinHeap-ului  
 * @param  heap: MinHeap-ul
 * @retval None
 */
void resize(MinHeap *heap) {
	int* aux = (int *)realloc(heap->arr, heap->capacity * 2);

	if (aux == NULL){
        return;
    }

    if (heap->arr != NULL){
        free(heap->arr);
    }

    heap->arr = aux;
	
}
/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  heap: MinHeap-ul
 * @param  x: HeapNode-ul care urmeaza a fi inserat
 * @retval None
 */
 
void insert(MinHeap *heap, HeapNode *x){
 	int i;

    if (heap->size == heap->capacity){
        resize(h);
    }

    i = heap->size;
    heap->size++;
 
    while (i > 0  &&  x > heap->vec[(i - 1)/2]){
        heap->vec[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->arr[i] = x;
}




/**
 * TODO: Implementati functia stergere a unui heap
 * @param  h: MinHeap-ul
 * @retval None
 */
void deleteMinHeap(MinHeap **heap){
 	if (*heap == NULL){ 
        return;
    }

    if ((*heap)->arr != NULL){ 
        free((*heap)->arr);
    }

    free(*heap);
    *heap=NULL;
	
}
/**
 * TODO: Implementati functia de afisare a unui heap
 * @param  heap: MinHeap-ul
 * @note : se va afisa si pozitia HeapNode-urilor, pe langa componentele HeapNode-ului
 * @retval None
 */
void printHeap(MinHeap *heap){
	//nice to have
}
/**
 * TODO: Implementati functia de stergere a radacinii
 * @param  heap: MinHeap-ul
 * @retval HeapNode-ul care s-a sters, fosta radacina
 */
HeapNode* deleteNode(MinHeap *heap){
    HeapNode *h;

    heap->poz[0] = -1;
    h = heap->arr[0];
    
    HeapNode *l = heap->arr[heap->size - 1];

    heap->arr[0] = l;
    heap->poz[0] = -1;
    heap->size--;

    heapify(heap, 0);

    return h;
}
