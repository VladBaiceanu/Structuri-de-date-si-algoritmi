#include "utils.h"
#include "counting.h"

//----- Counting Sort -----

/**
 * //TODO: Implementarea algoritmului counting sort
 * Restrictii: 0 <= arr[i] < 50
 * Dimensiunea vectorului de frecventa va fi 50
 * @param arr - vectorul care trebuie sortat
 * @param dim - dimensiunea vectorului
 * @return vectorul de frecventa utilizat in algoritm
 */
int* countingSort(int *arr, int dim){

    int aux[50];
    int max = 0;
    int i;

    for(i =1; i < dim; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int fv[50];

    for(i = 0; i <= max; i++){
        fv[i] = 0;
    }

    for (i = 0; i < dim; i++){
        fv[arr[i]]++;
    }

    for(i = 1; i <= max; i++){
        fv[i] =+ fv[i-1];
    }

    for(i = dim - 1; i >= 0; i--){
        aux[fv[arr[i]] - 1] = arr[i];
        fv[arr[i]]--;
    }

    for(i  = 0; i < dim; i++){
        arr[i] = aux[i];
    }
    return fv;
 
}

/**
 * Complexitate spatiala: O(n+k), complexitate temporala: O(n)
 * De ce nu este mai folosit?-Ocupa prea mult spatiu
 */