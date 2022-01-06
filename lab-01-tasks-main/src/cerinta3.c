#include "student.h"

/**
 * @param vector  - pointer catre vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 */
void realocare_memorie (student **vector, int dimensiune) {
	*vector = (student*)realloc(*vector,dimensiune*sizeof(student));
}

/**
 * Hint:
	- optional: se poate utiliza functia swap implementata la cerinta1
 * @param vector  - pointer catre vectorul de studenti 
 * @param poz - pozitia pe care trebuie adaugat noul student
 * @param dimensiune - dimensiunea vectorului
 * @param stud - reprezinta studentul care trebuie adaugat in vector (acesta are datele necesare deja completate -nume,prenume,etc-)
 */
void adaugare_student (student *vector, int poz, int dimensiune, student stud) {
	int i;
		
	for(i = (dimensiune-1); i >= poz+1; i--){
		vector[i] = vector[i-1];
	}
	vector[poz] = stud;
}

void adaugare_student1 (student *vector, int poz, int dimensiune, student stud) {
	int i;
	vector[dimensiune-1] = stud;	
	for(i = (dimensiune-1); i >= (poz+1); i--){
		swap(&vector[i],&vector[i-1]);
	}


//Complexitate de "dimensiune-poz-1"
}

