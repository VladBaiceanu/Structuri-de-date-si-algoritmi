#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "heap.h"

TEST_CASE("Cerinta 1: Heapsort") {
    
    
	
    SECTION("Heapsort") {
		std::vector<int> data = beforeEach(TASK1_TEST_SOLUTION1);
		Heap *h = heapsortSetUp(TASK1_TEST_FILENAME);
        REQUIRE(h != NULL);
        for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == h->vec[i]);
        }
    }
}
TEST_CASE("Cerinta 1: Heapsort dupa eliminarea nodului i = 1") {
    
        std::vector<int> data = beforeEach(TASK1_TEST_SOLUTION2);
        Heap *h = heapsortWithDeleteSetUp(TASK1_TEST_FILENAME, 1);
        REQUIRE(h != NULL);
        for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == h->vec[i]);
        }
    
}

TEST_CASE("Cerinta 1: Heapsort dupa eliminarea nodului [i = ultimul element] din heap") {	
	
        std::vector<int> data = beforeEach(TASK1_TEST_SOLUTION3);
        Heap *h = heapsortWithDeleteSetUp(TASK1_TEST_FILENAME, data.size());
        REQUIRE(h != NULL);
        for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == h->vec[i]);
        }
     
}
