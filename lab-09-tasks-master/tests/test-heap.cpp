#include "test-utils.hpp"


TEST_CASE("Cerinta 2: Heap") {
    FILE *input_data = fopen(HEAP_TEST_FILENAME, READ_MODE);
    FILE *input_mask = fopen(HEAP_MASK_FILENAME, READ_MODE);
	FILE *debug_data = fopen(HEAP_DEBUG, WRITE_MODE);
    int data_size;
    HeapNode *auxNode = NULL;
    MinHeap *min_heap = create(8);
    fscanf(input_data, "%d", &data_size);

    for (int i = 0; i < data_size; i++) {
        int varf, dist;
        fscanf(input_data, "%d %d", &varf, &dist);
        if (varf != -1 && dist != -1) {
            auxNode = createHeapNode(varf, dist);
            insert(min_heap, auxNode);
            // randul 1
            int mask_size;
            fscanf(input_mask, "%d", &mask_size);
            if (mask_size == 8) {
                fprintf(debug_data, "Testing insert round %2d:\n", i);
				for (int j = 0; j < mask_size; j++) {
                    int mask_elem;
                    fscanf(input_mask, "%d", &mask_elem);
					fprintf(debug_data, "%-50s  %-+3d == %+3d \n", "Testing poz vector (reference vs student_input) :", mask_elem, min_heap->poz[j]);
                    REQUIRE(mask_elem == min_heap->poz[j]);
                }
            }
            // perechi
            int size_perechi;
            fscanf(input_mask, "%d", &size_perechi);
            for (int j = 0; j < size_perechi; j++) {
                int pair1, pair2;
                fscanf(input_mask, "%d %d", &pair1, &pair2);
				fprintf(debug_data, "%-50s  %-+3d == %+3d \n", "Testing vertex (reference vs student_input) :", pair1, min_heap->arr[j]->v);
				fprintf(debug_data, "%-50s  %-+3d == %+3d \n", "Testing distance (reference vs student_input) :", pair2, min_heap->arr[j]->distanta);
                REQUIRE(pair1 == min_heap->arr[j]->v);
                REQUIRE(pair2 == min_heap->arr[j]->distanta);
            }
        } else {
            // randul 1
			fprintf(debug_data, "Testing delete round %2d:\n", i);
            deleteNode(min_heap);
            int mask_size;
            fscanf(input_mask, "%d", &mask_size);

            if (mask_size == 8) {
                for (int j = 0; j < mask_size; j++) {
                    int mask_elem;
                    fscanf(input_mask, "%d", &mask_elem);
					fprintf(debug_data, "%-50s  %-+3d == %+3d \n", "Testing poz vector (reference vs student_input) :", mask_elem, min_heap->poz[j]);
                    REQUIRE(mask_elem == min_heap->poz[j]);
                }
            }

            // perechi 
            int size_perechi;
            fscanf(input_mask, "%d", &size_perechi);

            for (int j = 0; j < size_perechi; j++) {
                int pair1, pair2;
                fscanf(input_mask, "%d %d", &pair1, &pair2);
				fprintf(debug_data, "%-50s  %-+3d == %+3d \n", "Testing vertex (reference vs student_input) :", pair1, min_heap->arr[j]->v);
				fprintf(debug_data, "%-50s  %-+3d == %+3d \n", "Testing distance (reference vs student_input) :", pair2, min_heap->arr[j]->distanta);
                REQUIRE(pair1 == min_heap->arr[j]->v);
                REQUIRE(pair2 == min_heap->arr[j]->distanta);
            }
        }	
    }
}