<h1 align="center">
    lab-09: Grafuri - Drumuri de cost minim
  </h1>

## Cerinte:
1. Implementati o functie care creeaza matricea de adiacenta (a drumurilor) a unui graf neorientat pe baza datelor de intrare.
2. Implementati algoritmul Dijkstra folosindu-va de minHeap si de structura DijkstraPath (pentru instantierea & popularea vectorului de distante/predecesori).
3. Implementati algoritmul Floyd-Warshall. (Complexitate O(n³))

#### Puteti afla mai multe legat de modul de lucru [aici](https://github.com/sda-ab/student-setup#indicatii-rezolvare-laborator)
#### Pentru mai multe explicatii consultati [acest pdf](https://github.com/sda-ab/lab-09-tasks/blob/master/Laboratorul%209%20-%20Dijkstra.pdf)
## Observatii:
  - **teste:**
    - Comanda **make test** va rula toate testele.
    - Comanda **make test-cX** (unde **X** e nr. cerintei: **1, 2, 3**) va rula testele doar pentru cerinta **X**.
    - Comanda **make single-run** va rula main-ul.
    - Comanda **make test-heap** va rula testul pentru **heap.c**.
    - Testul pentru **cerinta 2** va rula automat si testul pentru **heap.c**.
    - Pentru debug pe testul de heap, exista in folderul tests fisierul "heap_debug.txt" verificarile pentru fiecare insert si delete pana la primul mismatch.
  - **implementare:**
    - Vectorul poz va fi initializat cu -1 pe intreaga capacitate, iar la structura DijkstraPath , vectorul pred trebuie initializat tot cu -1.
    - La deleteNode, dupa ce se elimina radacina, trebuie actualizata pozitia din vectorul poz cu -1.
    - In header-ul "graph.h" au fost definite valorile INF_MAX si INF_MIN pe care le puteti utiliza daca aveti nevoie in implementare.
    - In printPath se va afisa drumul fara nodul sursa, dar cu destinatia inclusiv.
  - **implementare MinHeap:**
    - Pentru partea de **insert**, se vor avea in vedere cele doua cazuri :
     1. partea de inserare in cazul in care in MinHeap nu se afla deja nodul din graful pentru algoritmul Dijkstra
     2. partea de actualizare in momentul in care, pe parcursul implementarii algoritmului , se va actualiza distanta de la nodul sursa catre nodul v
      * **OBS 1:** Avand in vedere ca MinHeap-ul este adaptat la cerintele algoritmului, este suficienta restaurarea proprietatii MinHeap prin heapify up ( deoarece in fiecare moment, se va actualiza cu o valoarea mai mica , iar acest lucru nu va afecta nivelurile de mai jos din Heap)
      * **OBS 2:**  Atentie la heapify up, interschimbarea pozitiilor din vectorul poz trebuie facuta la fiecare pas 
     - Pentru partea de **deleteNode**, se va scoate din MinHeap radacina si se va returna HeapNode-ul scos pentru utilizarea lui in algoritmul Dijkstra. Atunci cand se scoate HeapNode-ul , trebuie actualizata valoarea nodului scos in vectorul poz cu -1.
     
## Structuri folosite:
```c
//graph.h
typedef struct{
    int V;     //nr varfuri
    int E;     //nr muchii
    int **mat; //matrice de adiacenta
} Graph;

typedef struct{
    int *dist; //vectorul de distante minime fata de nodul sursa
    int *pred; //vectorul de predecesori
} DijkstraPath;

//heap.h
typedef struct{
    int v;        // nod
    int distanta; // distanta pana la nodul v de la un nod dat
} HeapNode;

typedef struct{
    int size;
    int capacity;
    int *poz;       //vectorul de pozitii ale elementelor din MinHeap
    HeapNode **arr; //vectorul cu distantele minime pana in mom respectiv
} MinHeap;
```
