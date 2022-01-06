#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "heap.h"




TEST_CASE("Cerinta 3: Vector k - sortat") {
    
	SECTION("Vector 3 - sortat") {
		std::vector<int> data = beforeEach(TASK3_TEST_SOLUTION1);
		
		
		int *v = setUpKSorted(TASK2_3_TEST_FILENAME1, 3);
		REQUIRE(v != NULL);
		for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == v[i]);
        }
        
    }
    SECTION("Vector 25 - sortat") {
		std::vector<int> data = beforeEach(TASK3_TEST_SOLUTION2);
		
		
		int *v = setUpKSorted(TASK2_3_TEST_FILENAME2, 25);
		REQUIRE(v != NULL);
		for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == v[i]);
        }
        
    }
	SECTION("Vector 1000 - sortat") {
		std::vector<int> data = beforeEach(TASK3_TEST_SOLUTION3);
		
		
		int *v = setUpKSorted(TASK2_3_TEST_FILENAME3, 1000);
		REQUIRE(v != NULL);
		for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == v[i]);
        }
        
    }
}