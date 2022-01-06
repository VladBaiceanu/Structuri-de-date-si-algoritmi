#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "heap.h"


TEST_CASE("Cerinta 2: Cele mai mari k numere") {
    SECTION("Cele mai mari 3 numere") {
		std::vector<int> data = beforeEach(TASK2_TEST_SOLUTION1);
		
		
		int *v = setUpKMax(TASK2_3_TEST_FILENAME1, 3);
		REQUIRE(v != NULL);
        
		for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == v[i]);
        }
        
    }

	SECTION("Cele mai mari 25 numere") {
		std::vector<int> data = beforeEach(TASK2_TEST_SOLUTION2);
		
		
		int *v = setUpKMax(TASK2_3_TEST_FILENAME2, 25);
		REQUIRE(v != NULL);
        
		for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == v[i]);
        }
        
    }
	SECTION("Cele mai mari 1000 de numere") {
		std::vector<int> data = beforeEach(TASK2_TEST_SOLUTION3);
		
		
		int *v = setUpKMax(TASK2_3_TEST_FILENAME3, 1000);
		REQUIRE(v != NULL);
		for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == v[i]);
        }
        
    }
	
}

