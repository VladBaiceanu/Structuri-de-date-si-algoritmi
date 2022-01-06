#include "test-utils.hpp"


TEST_CASE("Cerinta 3: Floyd-Warshall")
{
	Graph *answer = beforeEach(TASK3_MASK_FILENAME);
	Graph *student = studentTaskSetUp(TASK3_TEST_FILENAME);
	
	SECTION ("Verificare matrice de adiacenta") {
		for (int i = 0; i < answer->V; i++)
			for (int j = 0; j < answer->V; j++) 
					REQUIRE(answer->mat[i][j] == student->mat[i][j]);
	}

	SECTION ("Verificare Floyd-Warshall") {
		Graph *FW = beforeEach(TASK3_MASK_FILENAME2);
		int **student_FW = Floyd_Warshall(student);
		for (int i = 0; i < FW->V; i++)
			for (int j = 0; j < FW->V; j++)
				if (i != j)
					REQUIRE(FW->mat[i][j] == student_FW[i][j]);
	}

}