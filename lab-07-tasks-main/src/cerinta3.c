#include "heap.h"

/**
 * TODO: Sortati eficient un vector k-sortat folosind un heap.
 * HINT: Se poate utiliza un heap de dimensiune mai mica decat
 * numarul de elemente din buffer
 * @param  *buffer: - vectorul k sortat
 * @param  dimensiune: numarul de elemente
 * @param  k: indicele de sortare a vectorului k-sortat
 * @retval - vectorul sortat
 */
int *kSortedArray(int *buffer, int dimensiune, int k){
    int i,l = 0;

    Heap* h = create(k + 1);
    int* v = (int*)malloc(sizeof(int)*dimensiune);
    for(i = 0; i < k + 1; i++){
        insert(h, buffer[i]);
    }

    for(i = k+1; i < dimensiune; i++){
        v[l++] = returnRoot(h);
        deleteNode(h, 0);
        insert(h, buffer[i]);
    }
	
    heapsort(h, h->vec, h->size);

    for(i = h->size - 1; i >= 0; i--){
        v[l++] = h->vec[i];
    }

	return v;
}
