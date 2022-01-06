#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <cstdbool>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

/*Fisierele folosite in teste*/
#define TASK1_TEST_FILENAME1     "../data/test1-data.txt"
#define TASK1_TEST_FILENAME2     "../data/test1-data2.txt"
#define TASK2_TEST_FILENAME1    "../data/test2-data1.txt"
#define TASK3_TEST_FILENAME     "../data/test3-data.txt"
#define HEAP_TEST_FILENAME      "../data/heap-data.txt"
#define HEAP_MASK_FILENAME      "../data/heap-mask.txt"
/*Correct answers*/
#define TASK1_MASK_FILENAME1     "../data/test1-mask.txt"
#define TASK1_MASK_FILENAME2     "../data/test1-mask2.txt"

#define TASK2_MASK_FILENAME     "../data/test3-mask.txt"
#define TASK2_MASK_FILENAME2     "../data/test1-mask2.txt"

#define TASK3_MASK_FILENAME     "../data/test3-mask.txt"
#define TASK3_MASK_FILENAME2     "../data/test3-mask2.txt"

#define HEAP_DEBUG				"../tests/heap_debug.txt"

/*Fisierul de output pentru printPath*/
#define PRINT_PATH "path.txt"
#define WRITE_MODE "w+"
#define READ_MODE "r+"

#include "utils.h"
#include "graph.h"
#include "heap.h"
#include "catch.hpp"

Graph *studentTaskSetUp(const char *test_task_data);
Graph *beforeEach (const char *test_task_data);
std::vector<int> checker(int test_case, int type);