#include "merge.h"
#include "quick.h"
#include "utils.h"
#include "stdlib.h"

//----- MergeSort -----

/**
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param middle - pozitia din mijloc
 * @param right - pozitia finala
 */
void merge(int *arr, int left, int middle, int right){
    int i,j,k = 0;
    int *aux = (int*)malloc(sizeof(int)*(right-left+1));
    i = left;
    j = middle;

    while(i < middle && j <= right){
        if(arr[i] < arr[j]){
            aux[k] = arr[i];
            i++;
        }
        else{
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while(j <= right){
        aux[k] = arr[j];
        j++;
        k++;
    }

    while(i < middle){
        aux[k] = arr[i];
        i++;
        k++;
    }
    
    for(i = 0; i < k; i++){
        arr[left] = aux[i];
        left++;
    }
}

/**
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param right - pozitia finala
 */
void mergesort(int *arr, int left, int right){
    if(left == right){
        return;
    }
    int middle = (left+right)/2+1;
    mergesort(arr,left,middle-1);
    mergesort(arr,middle,right);
    merge(arr,left,middle,right);
}

//----- Quick Sort -----

/**
 * @param x - primul element
 * @param y - al doilea element
 */
void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

/**
 * Consideram pivotul a fi ultimul element din vector
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
int partition(int *arr, int low, int high){
    int pivot,j,i;
    pivot = arr[high];
    i = (low - 1);

    for(j = low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

/**
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
void quicksort(int *arr, int low, int high){
    int flag;
    if(low < high){
        flag = partition(arr,low,high);
        quicksort(arr,low,(flag-1));
        quicksort(arr,(flag+1),high);
    }
}

//----- Analiza functiilor -----

/**
 * si care reprezinta metode de sortare instabile? Argumentati.
 * 
 * MergeSort este o metoda de sortare stabila pe cand QuickSort este instabila. Amandoua algoritmele se bazeaza pe principiul "Divide et impera"
 * MergeSort nu schimba oridinea relativa a doua elemente cu aceeasi valoare pe cand QuickSort poate sa le schimbe
 * 
 */