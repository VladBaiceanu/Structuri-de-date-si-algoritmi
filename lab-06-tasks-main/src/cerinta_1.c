#include "utils.h"
#include "bst.h"
/**
 * TODO: Implementati o functie ce creaza un arbore balansat din datele
 * 	din fisierul f. Arborele nu trebuie sa respecte alta proprietate decat
 *  cea mentionala anterior 
 * @note   
 * @param  N: Numarul de noduri ale arborelui
 * @param  *f: Fisierul din care sunt citite datele de intrare 
 * @retval	Nodul radacina al arborelui creat 
 */
BST *createBalanced(int N, FILE *f)
{
    int num;
    if (N <= 0){
        return NULL;
    }

    BST *root = (BST *)malloc(sizeof(BST));
    fscanf(f, "%d", &num);
    *root = (BST){num, createBalanced(N / 2, f), createBalanced(N - 1 - N / 2, f), NULL};
    
    if((root->left) != 0){
        root->left->parent = root;
    }

    if((root->right) != 0){
        root->right->parent = root;
    }

    return root;
}

/**
 * TODO:   Implementati o functie ce testeaza daca un arbore binar este
 * 	un arbore binar de cautare.
 * @note   
 * @param  root: Radacina arborelui
 * @param  max_value: Valoarea maxima intalnita pana la nodul curent
 * @param  min_value: Valoarea minima intalnita pana la nodul curent
 * @retval - true daca arborele este un BST, false in caz contrar
 */
bool checkBST(BST *root, int max_value, int min_value)
{
    if(root == NULL){
        return true;
    }

    if (root->data > max_value || root->data < min_value){
        return false;
    }

    return checkBST(root->left, root->data, min_value) && 
           checkBST(root->right, max_value, root->data);
}

/**
 * TODO:  Implementati o functie ce aloca memorie pentru un nod 
 * 	si salveaza datele in acesta
 * @note   
 * @param  data: Datele ce trebuie stocate in nod
 * @retval Nodul creat
 */

BST *createBSTNode(int data)
{
    BST *temp = (BST*)malloc(sizeof(BST));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
/**
 * TODO: Implementati o functie ce insereaza un nod nou intr-un BST cu
 * 	pastrarea proprietatiilor acestui tip de arbore binar
 * @note   
 * @param  root: Nodul radacina
 * @param  data: Valoarea ce trebuie inserata in arbore
 * @retval Radacina arborelui modificat anterior
 */
BST *insertInBST(BST *root, int data)
{
    if(root == NULL){
        return createBSTNode(data);
    }

    if(data > root->data){
        root->right = insertInBST(root->right,data);
        root->right->parent = root;
    }
    else if(data < root->data){
        root->left = insertInBST(root->left,data);
        root->left->parent = root;
    }
    return root;


}