#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <cstdbool>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>


#include "student.h"
#include "utils.h"
#include "catch.hpp"

// Data for tests
#define TASK1_TEST_FILENAME "../data/test1-data.txt"
#define TASK2_TEST_FILENAME1 "../data/test2-data1.txt"
#define TASK2_TEST_FILENAME2 "../data/test2-data2.txt"
#define TASK2_TEST_FILENAME3 "../data/test2-data3.txt"
#define TASK3_TEST_FILENAME "../data/test3-data.txt"
#define TASK3_TEST_CREDENTIALS "../data/test3-credentials.txt"

//Answer for tests
#define TASK1_TEST_SOLUTION "../data/checker/test1-solution.txt"
#define TASK2_TEST_SOLUTION1 "../data/checker/test2-solution1.txt"
#define TASK2_TEST_SOLUTION2 "../data/checker/test2-solution2.txt"
#define TASK2_TEST_SOLUTION3 "../data/checker/test2-solution3.txt"
#define TASK3_TEST_SOLUTION1 "../data/checker/test3-solution1.txt"
#define TASK3_TEST_SOLUTION2 "../data/checker/test3-solution2.txt"
#define TASK3_TEST_SOLUTION3 "../data/checker/test3-solution3.txt"

std::vector<student> beforeEach(const char *);
student* studentTaskSetUp(const char *);
student person (std::ifstream *file);
bool customCompare(student first, student second);