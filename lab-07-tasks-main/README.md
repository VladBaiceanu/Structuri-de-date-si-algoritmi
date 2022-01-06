<h1 align="center">
 lab-07: Heap  
</h1>

<h3> Cerinte: </h3>



1. Implementati functiile din fisierul heap.c astfel incat sa puteti construi un <b>min heap</b>. Folosind functiile din fisierul heap.c implementati in fisierul cerinte1.c heapsort impreuna cu functia de eliminare a unui nod dintr-un heap. Sortarea se face descrescator la aceasta cerinta.

3. Implementati un algoritm de aflare a celor mai mari k numere dintr-un vector folosind un heap. <b>Sortarea intregului vector duce la penalizari.</b>
	<ol>
	<li><b> Metoda I</b>: Folositi un min heap de dimensiune k pentru a stoca primele k elemente din vectorul primit ca parametru, apoi parcurgeti restul elementelor din vector. Daca elementul curent este mai mare decat varful heap-ului adaugati elementul in heap in locul varfului. 
	<b>Atentie</b>: Asigurati-va ca dupa ce adaugati elementul refaceti proprietatea de min heap! </li>
	<li> <b> Metoda II</b>: Creati un min heap folosind valorile opuse ale elementelor din vectorul primit ca parametru, eliminati pe rand varful heap-ului de k ori, numerele rezultate vor fi numerele cu semn schimbat ale solutiei.</li>
	</ol> 
3. Fie un vector k-sortat crescator de dimensiune n (n <= 1 000 000) sortati eficient vectorul folosind un heap. Un vector se numeste k-sortat daca fiecare element se afla la maxim k pozitii distanta de pozitia sa in cadrul vectorului sortat. <b>Sortarea cu o complexitate mai mare sau egala cu O(nlogn) duce la penalizari.</b> </br>
***Exemplu n = 10 k = 3***
		
		vectorul k-sortat: 1, -7, -21, 21, 27, 8, 3 ,7 ,101, 91  
		vectorul sortat:  -21, -7, 1, 3, 7, 8, 21, 27, 91, 101
		
	<b>Hint</b>:  Creati un min-heap de dimensiune k+1, populati-l cu primele k+1 elemente, apoi parcurgeti restul elementelor, la fiecare pas stocati varful in vectorul solutie si adaugati urmatorul element din vector in heap. Nu uitati ca la final sa adaugati si elementele ramase in heap in vectorul solutie.


Puteti afla mai multe legat de modul de lucru [aici](https://github.com/sda-ab/student-setup#indicatii-rezolvare-laborator)
