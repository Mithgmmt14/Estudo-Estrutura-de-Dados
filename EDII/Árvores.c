/* Exercícios Lista Complementar Prof. André Backs -> Árvores. Disponível em: https://programacaodescomplicada.wordpress.com/complementar */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no * esq;
    int valor;
    struct no * dir;
} No;

typedef struct no * Arv_bin;

/* Exercício 02 */

int conta_nos ( Arv_bin arv ){
    if ( arv == NULL ) return 0;             // Árvore vazia, sem nós.
    int conta_esq = conta_nos ( arv -> esq );  // Calcula , recursivamente, a quantidade de nós filhos á esquerda;
    int conta_dir = conta_nos ( arv -> dir );  // Calcula , recursivamente, a quantidade de nós filhos á direita;
    return conta_dir + conta_esq + 1 ;
}

/* Exercício 03 */

int conta_nos_nao_folha ( Arv_bin arv ){
    if ( arv == NULL ) return 0;                                 // Árvore vazia, sem nós;
    if ( arv -> esq == NULL && arv -> dir == NULL ) return 0;    // Caso for um nó folha não adiciona à soma;
    int conta_esq = conta_nos_nao_folha ( arv -> esq );            // Calcula , recursivamente, a quantidade de nós filhos á esquerda;
    int conta_dir = conta_nos_nao_folha ( arv -> dir );            // Calcula , recursivamente, a quantidade de nós filhos á direita;
    return conta_dir + conta_esq + 1 ;
}

/* Exercício 04 */

int conta_nos_folha ( Arv_bin arv ){ 
    if ( arv == NULL ) return 0;                                 // Árvore vazia, sem nós;                                
    if ( arv -> esq == NULL && arv -> dir == NULL ) return 1;    // Caso for um nó folha adiciona 1 à soma;
    int conta_esq = conta_nos_folha ( arv -> esq );                // Calcula , recursivamente , a quantidad de nós folha á esquerda;
    int conta_dir = conta_nos_folha ( arv -> dir );                // Calcula , recursivamente , a quantidad de nós folha á direita;
    return conta_dir + conta_esq ; 
}

/* Exercício 05 */

int altura_arv ( Arv_bin arv ){
    if ( arv == NULL ) return 0;              // Árvore vazia, sem nós;
    int alt_esq = altura_arv ( arv -> esq );  // Calcula a altura da árvore à esquerda;
    int alt_dir = altura_arv ( arv -> dir );  // Calcula a altura da árvore à direita;
    if ( alt_esq > alt_dir )                  // Se a altura a esquerda for maior, retorna ela e soma mais 1 do nó atual, caso contrário retorna a altura a direita somada a 1;
        return alt_esq + 1;                   
    else  
        return alt_dir + 1;
}

/* Exercício 06 */

int encontrar_impar ( Arv_bin arv ){
    if ( arv == NULL ) return 0;                       // Árvore vazia, sem nós;
    if ( arv -> valor % 2 != 0 ) return arv -> valor;  // Caso encontrar um valor impar, retorna seu valor;
    int esq = encontrar_impar ( arv -> esq );          // Procura no ramo esquerdo;
    if ( esq != 0 ) return esq;
    int dir = encontrar_impar ( arv -> dir );          // Procura no ramo direito;
    if ( dir != 0 ) return dir;
    
    return 0;                                          // Se não houver ímpar, retorna 0;
}
