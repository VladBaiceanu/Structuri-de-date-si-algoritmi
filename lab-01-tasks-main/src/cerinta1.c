#include "student.h"

//----- Prelucrarea informatiilor pentru un student -----

/**
 * @param stud - studentul a carui numar de restante trebuie aflat
 * @return numarul de restante
 */
int nr_restante (student stud) {
	int i;
	int cont = 0;
	for(i = 0; i < 5; i++){
		if(stud.note[i] < 5){
			cont++;
		}
	}
	
	return cont;
}

/**
 * @param stud - studentul a carei medie trebuie calculata
 * @return valoare mediei aritmetice 
 */
double medie (student stud) {
	double med;

	for(int i = 0; i < 5; i++){
		med = med + stud.note[i];
	}
	med = med / 5;
	return med;
}

//----- Instantierea & popularea vectorului de studenti -----

/**
 * Hint: 
	- numele si prenumele se aloca in timpul citirii datelor pentru fiecare student
 * @param vector - pointer catre vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 */
void alocare_memorie (student **vector, int dimensiune) {
 *vector = (student *)calloc(dimensiune, sizeof(student));
}
/** 
 * @param vector - vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 * @param input - fisierul de date
 */
void citire_fisier(student *vector, int dimensiune, FILE *input) {
	int i,j;
    fscanf(input, "%d", &dimensiune);

    for(i = 0; i < dimensiune; i++){
        vector[i].nume=(char*)malloc(50*sizeof(char));
        	fscanf(input, "%s", vector[i].nume);
        vector[i].nume=(char*)realloc(vector[i].nume, strlen(vector[i].nume)*sizeof(char));

        vector[i].prenume=(char*)malloc(50*sizeof(char));
        	fscanf(input, "%s", vector[i].prenume);
        vector[i].prenume=(char*)realloc(vector[i].prenume, strlen(vector[i].prenume)*sizeof(char));
        
		fscanf(input, "%s", vector[i].id);

		for(j = 0; j < dimensiune; j++){
			fscanf(input,"%lf",&vector[i].note[j]);
		}
	}

}

/**
 * @param vector  - vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 */
void afisare_fisier(student *vector, int dimensiune){
//Am inteles ca informatiile trebuie afisate pe ecran 

	int i,j;
	for(i = 0; i < dimensiune; i++){
		printf("Nume: %s\n",vector[i].nume);
		printf("Prenume: %s\n",vector[i].prenume);
		printf("Id: %s\n",vector[i].id);
		printf("Note: ");
		for(j = 0; j < 5; j++){
			printf("%lf ",vector[i].note[j]);
		}
		printf("\n");
		if(nr_restante(vector[i]) > 0){
			printf("Nr. restante: %d\n",nr_restante(vector[i]));
		}		
	}

	/*Exemplu afisare in fisier:
	Nume: Petrescu
	Prenume: Camil
	Id: 99
	Note: 10 10 10 10 10 
	Nume: Popesescu
	Prenume: Gigel
	Id: 100
	Note: 4 12 12 12 12
	Nr. restante: 1
	Nume: Cineva
	Prenume: Marian
	Id: 101
	Note: 5 5 5 5 5
	*/
}

/**
 * Hint: 
	- datele sunt citite de la tastatura
 * @param vector - vectorul de studenti ce trebuie populat cu date
 * @param dim - dimensiunea vectorului
 */
void populare_vector(student *vector, int dimensiune) {
	char aux[30];
	int j,i;
	for( i = 0; i < dimensiune; i++){
		printf("Nume:");	scanf("%s",aux);	printf("\n");
		vector[i].nume =(char*)malloc((strlen(aux)+1)*sizeof(char));
		strcpy(vector[i].nume,aux);

		printf("Prenume:");	scanf("%s",aux);	printf("\n");
		vector[i].prenume =(char*)malloc((strlen(aux)+1)*sizeof(char));
		strcpy(vector[i].prenume,aux);

		printf("Id:");	scanf("%s",vector[i].id); printf("\n");

		for(j = 0; j < 5; j++){
			printf("Nota %d: ",j+1);
			scanf("%lf ",&vector[i].note[j]);
		}
		printf("\n");
	}
}
/*
 * De afisat: nume, prenume, id, note, nr_restante
 * @param stud - studentul a carui date o sa fie afisate
*/ 
void afisare_student(student stud) {
	int i;
	printf("Nume: %s\n",stud.nume);
	printf("Prenume: %s\n",stud.prenume);
	printf("Id: %s\n",stud.id);

	printf("Note: ");
	for(i = 0; i < 5; i++){
		printf("%lf ",stud.note[i]);
	}
	printf("\n");
	printf("Nr restante: %d",nr_restante(stud));	
}

//----- Sortarea vectorului de studenti -----

/**
 * @param first_stud  - primul student
 * @param second_stud - al 2-lea student
 */
void swap(student *first_stud, student *second_stud) {
	student aux;

	aux = *first_stud;
	*first_stud = *second_stud;
	*second_stud = aux;
}

/**
 * Hint:
	- pentru sortare se foloseste metoda swap
 * @param vector  - vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 */
void sortare_vector(student *vector, int dimensiune) {
	int i,j;

	for(i = 0; i < dimensiune-1; i++){
		for(j = i+1; j < dimensiune; j++){
			if(medie(vector[i]) > medie(vector[j])){
				swap(&vector[i],&vector[j]);
			}
		}
	}

}