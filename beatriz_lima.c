#include <stdio.h>
#include <stdlib.h>
/**************************************************
*
* Beatriz Lima Pereira
* Trabalho 1
* Professor(a): Diego Rubert
*
*/

// Armazena informações de uma capivara
typedef struct {
        int numero; //número da capivara (posição na largada)
        int ultrapass; //quantia de ultrapassagens feitas
} capivara;

//função auxiliar do mergesort
//ordena de acordo com a pontuação, decrescente
void intercala(int p, int q, int r, capivara v[])
{
    int i, j, k;
    capivara w[r - p];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r)
    {
        if (v[i].ultrapass > v[j].ultrapass)
        {
            w[k] = v[i];
            i++;
        }
        else if (v[i].ultrapass == v[j].ultrapass)
        {
            if (v[i].numero < v[j].numero)
            {
                w[k] = v[i];
                i++;
            }
            else
            {
                w[k] = v[j];
                j++;
            }
        }
        else
        {
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while (i < q)
    {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < r)
    {
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
        v[i] = w[i - p];
}

//mergesort
void mergesort(int p, int r, capivara v[])
{
    int q;
    if (p < r - 1)
    {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}
//função main
int main(){
  int n_ultrapassagem;
  int n;
  scanf("%d", &n);
  capivara capis[n];
  for(int i = 0; i < n; i++){
      capis[i].ultrapass = 0;
      capis[i].numero = i+1;
      /*inicializo o ultrapass com 0 e ordeno cada i do vetor capis que esta no registro capivara com os números de cada                 participante*/
   }

   while(scanf("%d" , &n_ultrapassagem) != EOF){
     for (int i = 0; i < n; i++)
        {
            if (capis[i].numero == n_ultrapassagem)
            {
                capis[i].ultrapass += 1;
                capivara aux = capis[i];
                capis[i] = capis[i - 1];
                capis[i - 1] = aux;
            }
        }
   }/*Ordeno o vetor capis de acordo com a a ordem de linha de chegada: li os numeros dos   
      participantes que fizeram uma ultrapassagem (marcaram ponto); em seguida, no for, se o 
      capis i do vetor 'numero' de capivara for igual ao número que fez a ultrapassagem, troco 
      o capis i pelo capis [i-1], simulando uma ultrapassagem.*/
  
   for(int i = 0; i < n; i++){
     printf("%d ", capis[i].numero);
     /*impreção das capis participantes de acordo com a ordem de chegada */

   }
   mergesort(0, n, capis);
   /*a função mergesort vai ordenar as capis participantes da que fez mais 
     pontos/ultrapassagens para a com menos pontos (ordem decrescente)*/
   printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", capis[i].numero);
  
    } /*impreção das capis seguindo a ordem de pontuação feitas*/
    printf("\n");
return 0;
}   