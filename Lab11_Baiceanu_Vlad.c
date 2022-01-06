#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item{
    int pi;
    int gi;
}item;

float ratio(x,y){
    return x/y;
}

void read(FILE *input,item aux){
    fscanf(input,"%d %d",&aux->pi,&aux->gi);
} 

void create(FILE *input,item array[N]){
    for(int i = 0; i < N; i++){
        read(*input,array[i]);
    } 
}

void rucsac()
int main{

}
















