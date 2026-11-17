#include <iostream>
#include "ordenacao1.hpp"

using namespace std;


void bubbleSort(Musica v[], int tamanho, int &comparacao, int &trocas){

    comparacao = 0;
    trocas = 0;

    for(int i = 0; i < tamanho - 1; i++){

        for(int j = 0; j < tamanho - 1 - i; j++){

            comparacao++;

            if(v[j].reproducoes < v[j + 1].reproducoes){

                Musica temp;

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;

                trocas++;
            }
        }
    }
}

void selectionSort (Musica v[], int tamanho, int &comparacao, int &trocas){
	
	comparacao = 0;
	trocas = 0;
	
	for(int i = 0; i < tamanho - 1; i++){
		
		int maiorIndice = i;
		
		for(int j = i + 1; j < tamanho; j++){
			
			comparacao ++;
			if(v[j].reproducoes > v[maiorIndice].reproducoes){
				maiorIndice = j;
			}	
		}
		if(maiorIndice != i){
			trocas ++;
			Musica temp; 
			
			temp = v[i];
			v[i] = v[maiorIndice];
			v[maiorIndice] = temp;
		}
	}	
}	
void quickSort (Musica v[], int tamanho, int &comparacao, int &trocas, int inicio, int fim){
	
if (inicio < fim){
	
	int meio = 	(inicio + fim)/2;
	int pivo = v[meio].reproducoes;
	
	int i = inicio;
	int j = fim;
	
	while(i <= j){
		
		while(i <= fim){
        	comparacao++;
			if(v[i].reproducoes > pivo){
        	i++;
        	} else {
        	break;
            }
        }
	
			while(j >= inicio){
                comparacao++;
                if(v[j].reproducoes < pivo){
                    j--;
                } else {
                    break;
                }
            }
		
	if (i <= j){

    	if(i < j){
        Musica temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        trocas++;
    	}

    i++;
    j--;
	}
}

quickSort (v, tamanho, comparacao, trocas, inicio, j);
quickSort (v, tamanho, comparacao, trocas, i, fim);
}
}

    
