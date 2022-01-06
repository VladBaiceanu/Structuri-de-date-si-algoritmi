#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "student.h"

TEST_CASE("Cerinta 1: Creare & sortare vector") {
    student *studenti = studentTaskSetUp(TASK1_TEST_FILENAME);
    
    SECTION("Alocare dinamica si populare cu date") {
        std::vector<student> data = beforeEach(TASK1_TEST_FILENAME);
        for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(customCompare(data.at(i), studenti[i]));
        }
    }
    
    SECTION("Sortare vector in functie de medie (crescator)") {
        std::vector<student> data = beforeEach(TASK1_TEST_SOLUTION);
        sortare_vector(studenti, data.size());
        for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(customCompare(data.at(i), studenti[i]));
        }
    }   
}
