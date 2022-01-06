<h1 align="center">
 lab-01: Alocare dinamica, structuri
</h1>

**Cerinte:**
-

- Se dă stuctura student: 
```
struct student{
char *nume; //numele de familie
char *prenume; //prenumele
char id[6];   //id-ul studentului
double note[5]; //notele obtinute in semestrul anterior
};
```


1. În main – declarați un vector student alocat dinamic și populați-l cu datele citite de la tastatură. Realizați o sortare după medie și mai apoi afișați studenții cu restanțe astfel: id, nume, prenume, număr de restanțe.

2. Realizați o funcție care șterge din vector toți studenții care au cel puțin o restanță (realocând spațiul ocupat).  Afișati vectorul rezultat. Care este complexitatea pentru secvența de ștergere a elementelor din vector cu realocare de spațiu ? 

3. Realizați o funcție care adaugă în vector un student nou, pe o anumită poziție (realocând spațiul ocupat).  Afișati vectorul rezultat. Care este complexitatea metodei folosite ?


``` 
Datele folosite in rularea testelor sunt indicate de macro-urile prezente in fisierul test-utils.hpp (ex: TASK1_TEST_FILENAME)
--- Cum arata fisierul de date? ---
    2           -> numarul de studenti
    Popescu     -> nume student no.1
    Ion         -> prenume student no.1
    77          -> id student no.1
    7 8 9 10 5  -> note student no.1
    Niculescu   -> nume student no.2
    Catrinel    -> prenume student no.2
    155         -> id student no.2
    10 8 10 5 8 -> note student no.2
```
#### Puteti afla mai multe legat de modul de lucru [aici](https://github.com/sda-ab/student-setup#indicatii-rezolvare-laborator)
