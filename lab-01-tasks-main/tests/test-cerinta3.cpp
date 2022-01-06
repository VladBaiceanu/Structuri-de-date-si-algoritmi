#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "student.h"

TEST_CASE("Cerinta 3: Adaugare student pe pozitia X") {
    std::vector<student> data = beforeEach(TASK3_TEST_FILENAME);
    student *studenti = studentTaskSetUp(TASK3_TEST_FILENAME);
    student stud;
    FILE *f = openFile(TASK3_TEST_CREDENTIALS, READ_MODE);
    citire_fisier(&stud, 1, f);
    int size = data.size();
    
    SECTION("Adaugare student pe prima pozitie [pozitia 0]") {
        std::vector<student> result = beforeEach(TASK3_TEST_SOLUTION1);
        realocare_memorie(&studenti, ++size);
        adaugare_student(studenti, 0, size, stud);
        for (unsigned int i = 0; i < result.size(); i++) {
            REQUIRE(customCompare(result.at(i), studenti[i]));
        }
    }
    
    SECTION("Adaugare student pe ultima pozitie [pozitia n-1]") {
        std::vector<student> result = beforeEach(TASK3_TEST_SOLUTION2);
        realocare_memorie(&studenti, ++size);
        adaugare_student(studenti, size - 1, size, stud);

        for (unsigned int i = 0; i < result.size(); i++) {
            REQUIRE(customCompare(result.at(i), studenti[i]));
        }
    }

    SECTION("Adaugare student pe o anumita pozitie, in interiorul vectorului [pozitia 1]") {
        std::vector<student> result = beforeEach(TASK3_TEST_SOLUTION3);
        realocare_memorie(&studenti, ++size);
        adaugare_student(studenti, 1, size, stud);

        for (unsigned int i = 0; i < result.size(); i++) {
            REQUIRE(customCompare(result.at(i), studenti[i]));
        }
    }
}
