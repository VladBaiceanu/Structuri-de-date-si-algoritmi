#include "test-utils.hpp"

bool customCompare(student first, student second) {
	if (strcmp(first.nume, second.nume) != 0 || strcmp(first.prenume, second.prenume) != 0 || strcmp(first.id, second.id) != 0)
		return false;
	for (int i = 0; i < 5; i++)
		if (first.note[i] != second.note[i])
			return false;
	return true;
}

student person (std::ifstream *file) {
	student stud;
	char num[25], pren[25];
	*file >> num >> pren >> stud.id;
	stud.nume = new char[sizeof(num) + 1];
	stud.prenume = new char[sizeof(pren) + 1];
	strcpy(stud.nume, num);
	strcpy(stud.prenume, pren);
	for (int i = 0; i < 5; i++)
		*file >> stud.note[i];
	
	return stud;	
}

std::vector<student> beforeEach(const char * test_task_data)
{
	std::ifstream file(test_task_data);
	std::vector<student> studentsVector;
	int size;
	file >> size;

	for (int i = 0; i < size; i++) {
		studentsVector.push_back(person(&file));
	}

	return studentsVector;
}


student * studentTaskSetUp(const char * test_task_data) {
	FILE *f = openFile(test_task_data, READ_MODE);
	REQUIRE(isNotNull(f));
	int size;
	fscanf(f, "%d", &size);
	student *vector = NULL;
	alocare_memorie(&vector, size);
	citire_fisier(vector, size, f);
	REQUIRE(isNotNull(vector));
	return vector;
}
