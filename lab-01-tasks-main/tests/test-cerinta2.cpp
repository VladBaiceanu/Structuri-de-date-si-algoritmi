#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "student.h"

TEST_CASE("Cerinta 2: Eliminarea studentilor restantieri - exista studenti restantieri") {
    SECTION("Eliminare restantieri - exista restantieri") {
        std::vector<student> result = beforeEach(TASK2_TEST_SOLUTION1);
        std::vector<student> data = beforeEach(TASK2_TEST_FILENAME1);
        student *studenti = studentTaskSetUp(TASK2_TEST_FILENAME1);

        int initial_size = data.size();
        studenti = eliminare_restantieri(studenti, &initial_size);

        for (unsigned int i = 0; i < result.size(); i++) {
            REQUIRE(customCompare(result.at(i), studenti[i]));
        }
    }
}

TEST_CASE("Cerinta 2: Eliminarea studentilor restantieri - nu exista studenti restantieri") {
    SECTION("Nu exista restantieri") {
        std::vector<student> result = beforeEach(TASK2_TEST_SOLUTION2);
        std::vector<student> data = beforeEach(TASK2_TEST_FILENAME2);
        student *studenti = studentTaskSetUp(TASK2_TEST_FILENAME2);

        int initial_size = data.size();
        studenti = eliminare_restantieri(studenti, &initial_size);

        for (unsigned int i = 0; i < result.size(); i++) {
            REQUIRE(customCompare(result.at(i), studenti[i]));
        }
    }
}

TEST_CASE("Cerinta 2: Eliminarea studentilor restantieri - toti studentii sunt restantieri") {
    SECTION("Toti studentii sunt restantieri") {
        std::vector<student> data = beforeEach(TASK2_TEST_FILENAME3);
        student *studenti = studentTaskSetUp(TASK2_TEST_FILENAME3);
        int initial_size = data.size();

        studenti = eliminare_restantieri(studenti, &initial_size);
        REQUIRE(initial_size == 0);
    }
}
