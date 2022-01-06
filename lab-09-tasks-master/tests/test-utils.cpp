/**
 * @brief in this file are defined all the common functions used in the
 * 		  test suite
 * @author Rusu Gabriel
 * 
 */
#include "test-utils.hpp"

Graph *studentTaskSetUp(const char *test_task_data) {
    FILE *file = fopen(test_task_data, "r+");
    Graph *g = createGraph(file);
    return g;
}

Graph *beforeEach (const char *test_task_data) {
    FILE *file = fopen(test_task_data, "r+");
    Graph *g = (Graph *)malloc(sizeof(Graph));
    fscanf(file, "%d %d", &g->V, &g->E);
    
    g->mat = (int **)malloc(g->V * sizeof(int *));
    for (int i = 0; i < g->V; i++)
        g->mat[i] = (int *)calloc(g->V, sizeof(int));

    for (int i = 0; i < g->V; ++i) {
        for (int j = 0; j < g->V; ++j)
            fscanf(file, "%d", &g->mat[i][j]);
    }
    return g;
}
/*
void read_heap_data (const char *data, const char *mask) {
    FILE *input_data = fopen(data, WRITE_MODE);
    FILE *input_mask = fopen(mask, WRITE_MODE);
    int data_size;
    fscanf(input_data, "%d", &data_size);

    for (int i = 0; i < data_size; i++) {
        int varf, dist;
        fscanf(input_data, "%d %d", &varf, &dist);
        MinHeap *min_heap = create(8);
        if (varf != -1 && dist != -1) {
            HeapNode *auxNode = createHeapNode(varf, dist);
            insert(min_heap, auxNode);
           
            int mask_size;
            fscanf(input_mask, "%d", &mask_size);
            if (mask_size == 8) {
                for (int j = 0; j < mask_size; j++) {
                    int mask_elem;
                    fscanf(input_mask, "%d", &mask_elem);
                    REQUIRE(mask_elem == min_heap->poz[j]);
                }
            }
           
            int size_perechi;
            fscanf(input_mask, "%d", &size_perechi);
            for (int j = 0; j < size_perechi; j++) {
                int pair1, pair2;
                fscanf(input_mask, "%d %d", &pair1, &pair2);
                REQUIRE(pair1 == min_heap->arr[j]->v);
                REQUIRE(pair2 == min_heap->arr[j]->distanta);
            }
        } else {
           
            deleteNode(min_heap);
            int mask_size;
            fscanf(input_mask, "%d", &mask_size);
            if (mask_size == 8) {
                for (int j = 0; j < mask_size; j++) {
                    int mask_elem;
                    fscanf(input_mask, "%d", &mask_elem);
                    REQUIRE(mask_elem == min_heap->poz[j]);
                }
            }
            
            int size_perechi;
            fscanf(input_mask, "%d", &size_perechi);
            for (int j = 0; j < size_perechi; j++) {
                int pair1, pair2;
                fscanf(input_mask, "%d %d", &pair1, &pair2);
                REQUIRE(pair1 == min_heap->arr[j]->v);
                REQUIRE(pair2 == min_heap->arr[j]->distanta);
        }
    }
}
*/
std::vector<int> checker(int test_case, int type) {
    std::vector<int> dist_answer;
    if (type == 2) {
        if (test_case == 3) {
            dist_answer.push_back(1);
            dist_answer.push_back(2);
            dist_answer.push_back(3);
        } else if (test_case == 5) {
            dist_answer.push_back(2);
            dist_answer.push_back(5);
        }
    } else if (type == 1) {
        switch(test_case) {
            case 0: {
                dist_answer.push_back(0);
                dist_answer.push_back(4);
                dist_answer.push_back(12);
                dist_answer.push_back(19);
                dist_answer.push_back(21);
                dist_answer.push_back(11);
                dist_answer.push_back(9);
                dist_answer.push_back(8);
                dist_answer.push_back(14);
                break;
            }
            case 2: {
                dist_answer.push_back(12);
                dist_answer.push_back(8);
                dist_answer.push_back(0);
                dist_answer.push_back(7);
                dist_answer.push_back(14);
                dist_answer.push_back(4);
                dist_answer.push_back(6);
                dist_answer.push_back(7);
                dist_answer.push_back(2);
                break;   
            }
            case 7: {
                dist_answer.push_back(8);
                dist_answer.push_back(11);
                dist_answer.push_back(7);
                dist_answer.push_back(14);
                dist_answer.push_back(13);
                dist_answer.push_back(3);
                dist_answer.push_back(1);
                dist_answer.push_back(0);
                dist_answer.push_back(7);
                break;
            }
        }
    }
    return dist_answer;
}