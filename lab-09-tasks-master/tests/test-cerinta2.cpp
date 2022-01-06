#include "test-utils.hpp"


TEST_CASE("Cerinta 2: Dijkstra")
{
	Graph *answer = beforeEach(TASK2_MASK_FILENAME);
	Graph *student = studentTaskSetUp(TASK2_TEST_FILENAME1);
	std::vector<int> dist_answer;
	DijkstraPath *dist = NULL;

	SECTION ("Verificare matrice de adiacenta") {
		for (int i = 0; i < answer->V; i++)
			for (int j = 0; j < answer->V; j++)
				REQUIRE(answer->mat[i][j] == student->mat[i][j]);
	}

	SECTION ("Verificare Dijkstra, nodul 0") {
		dist_answer = checker(0, 1);
		dist = Dijkstra(student, 0);

		for (int i = 0; i < answer->V; i++)
			REQUIRE(dist->dist[i] == dist_answer[i]);
	}

	SECTION ("Verificare Dijkstra, nodul 2") {
		dist_answer = checker(2, 1);
		dist = Dijkstra(student, 2);

		for (int i = 0; i < answer->V; i++)
			REQUIRE(dist->dist[i] == dist_answer[i]);
	}

	SECTION ("Verificare Dijkstra, nodul 7") {
		dist_answer = checker(7, 1);
		dist = Dijkstra(student, 7);

		for (int i = 0; i < answer->V; i++)
			REQUIRE(dist->dist[i] == dist_answer[i]);
	}
}

TEST_CASE ("Cerinta 2: Dijkstra - PrintPath") {
	Graph *answer = beforeEach(TASK2_MASK_FILENAME);
	Graph *student = studentTaskSetUp(TASK2_TEST_FILENAME1);
	FILE *output = fopen(PRINT_PATH, WRITE_MODE);
	int *vector_predecesori = (int *)calloc(2 * answer->V,sizeof(int));
	DijkstraPath *dist = NULL;
	std::vector<int> dist_answer;

	SECTION ("Verificare matrice de adiacenta") {
		for (int i = 0; i < answer->V; i++)
			for (int j = 0; j < answer->V; j++)
				REQUIRE(answer->mat[i][j] == student->mat[i][j]);
	}

	SECTION ("Verificare Print Path, nodul destinatie 3") {
		dist_answer = checker(3, 2);
		dist = Dijkstra(student, 0);

		printPath(vector_predecesori, 2, dist->pred, 3, output);
		for (int i = 0; i < 3; i++)
			REQUIRE(vector_predecesori[i] == dist_answer[i]);
		fclose(output);
	}

	SECTION ("Verificare Print Path, nodul destinatie 5") {
		dist_answer = checker(5, 2);
		dist = Dijkstra(student, 1);

		printPath(vector_predecesori, 1, dist->pred, 5, output);
		for (int i = 0; i < 2; i++)
			REQUIRE(vector_predecesori[i] == dist_answer[i]);

		fclose(output);
	}
}