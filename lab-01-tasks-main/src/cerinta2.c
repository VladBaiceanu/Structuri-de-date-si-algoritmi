#include "student.h"

/**
 * Hint:
	- dimensiunea se schimba
	- se creeaza un vector auxiliar
 * @param vector  - vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 * @return vectorul de studenti fara restanta
 */
student* eliminare_restantieri(student *vector, int *dimensiune) {

	student *flag = (student*)malloc(sizeof(student)*(*dimensiune));
	int i,dim_flag = 0;
	for(i = 0; i < (*dimensiune); i++){
		if(nr_restante(vector[i]) == 0){
			flag[dim_flag] = vector[i];
			dim_flag++;
		}
	}
	free(vector);
	flag = (student*)realloc(flag,dim_flag*sizeof(student));
	return flag;

//Complexitate o "dimensiune"
}