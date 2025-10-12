/* Exercícios Lista Complementar Prof. André Backs -> Busca e Ordenação. Disponível em: https://programacaodescomplicada.wordpress.com/complementar */

/* Exercício 04 */

#include <stdio.h>
#include <stdlib.h>

int ehordenado ( int * vet , int N ){
    if ( vet == NULL || N <= 0 ) return 0;                // Verifica se o vetor não é nulo e se N não é negativo ou menor igual a 0;
    for ( int i = 0; i < N - 1 ; i ++ ){
        if ( * ( vet + i ) > * ( vet + i + 1 )) return 0; // Caso, dentro do vetor, houver um elemento fora de ordem retorna 0;
    }
    return 1;                                             // Caso o vetor estiver ordenado;
}

void imprimir_caso_Ordenado ( int * vet , int N ){
    int aux = ehordenado ( vet , N );     // Guarda , em um auxiliar, o valor 0 ( não ordenado ) ou 1 ( ordenado);
    if ( aux == 1 ){
        for ( int i = 0 ; i < N ; i ++ ){ // Realiza um Ciclo imprimindo os valores do vetor;
            printf ("%d ", *(vet + i ));
        }
    }
}

/* Exercício 05 */

void boubleSortDecrescente ( int * vet , int N ){
    int continua, aux;
    do{
        continua = 0;
        for ( int i = 0 ; i < N - 1 ; i++ ){     // Percorre o vetor trocando, quando necessário, os valores adjacentes "Empurrando os menores valores para o fim";
            if ( vet [i] < vet [ i + 1 ]){
                aux = vet [i];
                vet [i] = vet [ i + 1 ];
                vet [ i + 1 ] = aux;   
                continua = 1;                    // Faz com que as trocas sucessivas continuem até o vetor estiver ordenado; 
            }
        }
        N --;
    } while ( continua != 0 );
}

/* Exercício 06 */

int inserir_vetorordenado ( int * vet , int N , int valor ){
    if ( vet == NULL || N < 0 ) return 0;      // Vetor Nulo, ou N < 0;
    int indice = N;                            // Posição Padrão do indice;
    for ( int i = 0 ; i < N ; i++ ){           // Percorre o vetor até encontrar um elemento maior do que o valor, quebra o laço e atualiza o indice;
        if ( vet [i] > valor ){
            indice = i;
            break;
        }
    }
    for ( int j = N ; j > indice ; j-- ){ 
        vet [ j + 1 ] = vet [j];              // Desloca os elementos;
    }
    
    vet [indice] = valor;                     // Insere na posição vaga;
    
    return 1;
}

/* Exercício 07 */

int buscaemvetorordenado ( int * vet, int N , int valor ){
    if ( vet == NULL || N <= 0 ) return -1; // Vetor inválido ou N <= 0, impossível de realizar uma busca;
    for ( int i = 0 ; i < N ; i++ ){
        if ( vet [i] == valor ) return i;   // Encontrou o valor -> Retorna sua posição;
        if ( vet [i] > valor ) return -1;   // Como Ordenado, pode - se inferir que o valor não pertence ao vetor;
    }
    return -1;                              // Valor não encontrado;
}

/* Exercício 11 */

/*

-> BubbleSort "Ordenação por pares adjacentes" : Complexadade 0( n^2 ) , algoritmo estável, preserva a ordem relativa;
-> InsertionSort "Insere o elemento na posição correta" : Complexidade 0 ( n^2 ), algoritmo estável, preserva a ordem relativa de elementos;
-> SelectionSort "Procura o menor valor e o coloca na posição inicial" : Complexidade 0 ( n ^ 2 ), algoritmo não estável, não preserva a ordem relativa de elementos;
-> ShellSort "Melhoria do insertion sort ( comparações mais próxima sobre diretiva de um valor h)" : Complexidade 0 ( n ^ 1,25 até 1,6 . n ^ 1.25 ), não estável, não preserva a ordem relativa de elementos;

*/

/* Exercício 17 */

#include <string.h>

int inserir_nome_ordenaddo ( char ** Nomes, int N , char * str ){ // Inserção ordenada similar à ideia de InsertionSort;
    if ( str == NULL || N < 0 ) return 0; 
    int indice = N;
    for ( int i = 0; i < N ; i++ ){             // Encontra aquele elemento que é alfabeticamente maior do que a string;
        if ( strcmp ( Nomes [i] , str ) > 0 ){
            indice = i;
            break;
        }
    }
    for ( int j = N ; j > indice ; j -- ){      // Desloca os elementos para inserir no espaço vago;
        Nomes [ j + 1 ] = Nomes [j];
    }
    Nomes [indice] = str;                       // Adiciona o elemento no indice encontrado;
    return 1;
}

/* Exercício 18 */

void BubbleSortString ( char * str , int N ){
    if ( str == NULL || N <= 0 ) return;     // Vetor inválido ou n <= 0 , impossível realizar a ordenação;
    int continuar;
    char aux;
    do{
        continuar = 0;                       // BoubleSort padrão, compara-se com os adjacentes e compara com o necessário;
        for ( int i = 0 ; i < N - 1 ; i++ ){
            if ( str[i] > str [ i + 1 ]){
                aux = str [i];
                str[i] = str [ i + 1 ];
                str [ i + 1 ] = aux;
                continuar = 1;
                }
            }
        N --;
    } while ( continuar != 0 );
}

/* Exercício 19 */

#include <string.h>

void OrdenararPorTamanho ( char ** Nomes , int N ){              // Implementação de Selection Sort para Listas de Listas;
    if ( Nomes == NULL || N <= 0 ) return;
    for ( int i = 0 ; i < N - 1; i++ ){
        int menor = i;
        for ( int j = i + 1 ; j < N ; j++ ){
            if ( strlen ( Nomes [j]) < strlen ( Nomes [menor])) // Compara os tamanhos;
            menor = j;
        }
        if ( menor != i ){                                      // Troca os Elementos de Posição;
            char * str = Nomes [i];
            Nomes [i] = Nomes [menor];
            Nomes [menor] = str;
        }
    }
}
