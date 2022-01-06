#include "test-utils.hpp"

TEST_CASE("Cerinta 1: Verificare instantiere")
{
	Graph *answer = beforeEach(TASK1_MASK_FILENAME1);
	Graph *student = studentTaskSetUp(TASK1_TEST_FILENAME1);
	SECTION("Numar de varfuri?") {
		REQUIRE(student->V == answer->V);
	}

	SECTION ("Numar de muchii?") {
		REQUIRE(student->E == answer->E);
	}

	SECTION ("Matricea de adiacenta") {
		for (int i = 0; i < answer->V; i++)
			for (int j = 0; j < answer->V; j++) {
				REQUIRE(answer->mat[i][j] == student->mat[i][j]);
			}
	}
}

TEST_CASE("Cerinta 1: Verificare instantiere 2")
{
	Graph *answer = beforeEach(TASK1_MASK_FILENAME2);
	Graph *student = studentTaskSetUp(TASK1_TEST_FILENAME2);
	SECTION("Numar de varfuri?") {
		REQUIRE(student->V == answer->V);
	}

	SECTION ("Numar de muchii?") {
		REQUIRE(student->E == answer->E);
	}

	SECTION ("Matricea de adiacenta") {
		for (int i = 0; i < answer->V; i++)
			for (int j = 0; j < answer->V; j++) {
				REQUIRE(answer->mat[i][j] == student->mat[i][j]);
			}
	}
}