/*Exercícios -> Parte I -> Livro "Introdução à Estruturas de Dados" -> Waldemar Celes;

/* Exercício -> Funções Simples */

int dentro_ret ( int x0 , int y0 , int x1 , int y1 , int x , int y ){
    if ( x0 <= x && x <= x1 && y0 <= y && y <= y1 ){ // x pertence ao intervalo [ x0 , x1 ] e y pertence ao intervalo [ y0 , y1 ];
             return 1;
    }
    return 0;
}

int primo ( int n ){
    if (n <= 1) return 0;                 // Caso onde n é negativo ou igual a 1, não sendo primo;
    for ( int i = 2 ; i * i <= n ; i++ ){ // Definição do crivo de eratosthenes
        if ( n % i == 0 ) return 0; 
    }
    return 1;
}

int fibonnacci ( int n ){
    if ( n == 0 ) return 0;                             // Caso Base_1;
    if ( n == 1 || n == 2 ) return 1;                   // Caso Base_2;
    return fibonnacci ( n - 1 ) + fibonnacci ( n - 2 ); // Caso Recursivo;
}

int soma_impares ( int n ){
    if ( n <= 0 ) return -1;                // Código de Erro;
    int soma = 0;                           // Variável acumuladora;
    for ( int i = 1 ; i <= n ; i = i + 2 ){
        soma = soma + i;
    }
    return soma;
}

double pi ( int n ) {
    double soma = 0.0;                       // Variável Acumuladora;
    for ( int i = 0 ; i < n ; i++ ) {
        double termo = 1.0 / (2 * i + 1);    // Variável Local auxiliar;
        if (i % 2 == 0) {                    // Caso par soma, caso contrário, subtrai;
            soma = soma + termo;
        } else {
            soma = soma - termo;
        }
    }
    return 4.0 * soma;
}

/* Exercício -> Passagem de parâmetros por referência */

#include <math.h>

int raizes ( float a , float b , float c ,  float * x1 , float * x2 ){
    if ( a == 0 ) return -1;                         // Não é uma equação do segundo grau;
    float delta = b * b - 4 * a * c;                 // Calculo do delta da equação/
    if ( delta < 0 ) return 0;                       // Delta negativo -> Não há raizes reais;
    if ( delta == 0 ) {                              // Delta igual a zero -> Há uma raiz;
        * x1 = ( - b + sqrt ( delta ) ) / ( 2 * a );    
        * x2 = * x1;
        return 1;
    }
    * x1 = ( - b + sqrt ( delta ) ) / ( 2 * a );    // Delta positivo e diferente de zero -> Duas raizes reais;
    * x2 = ( - b - sqrt ( delta ) ) / ( 2 * a );
    return 2;
}

void calc_esfera ( float r , float * area , float * volume ){
    *area = 4 * 3.141593 * r * r;                        // Definição de cálculo de área de esferas;
    *volume = ( 4.0 / 3.0 ) * 3.141593 * r * r * r ;     // Definição de cálculo de volume de esferas;
}

/* Exercício -> Vetores */

int negativos ( int n , float * vet ){ 
    int soma = 0;                         // Variável acumuladora;
    for ( int i = 0 ; i < n ; i ++ ){ 
        if ( vet [i] < 0 ) soma ++;      // Percorre o vetor, caso o numero for negativo soma um à variável acumuladora;
    }
    return soma;
}

int pares ( int n , int * vet ){
    int soma = 0;                         // Variável acumuladora;
    for ( int i = 0 ; i < n ; i++ ){
        if ( vet [i] % 2 == 0 ) soma ++;  // Percorre o vetor, caso o numero for par soma um à variável acumuladora;
    }
    return soma;
}

void inverte(int n, int *vet) {
    if (n == 0) return;                 // Vetor sem elementos, não é possível inverter;
    int aux[n];
    for ( int i = 0 ; i < n ; i++ ) {   // Realiza a inversão da sequencia de inteiros e os armazena em uma vetor auxiliar;
        aux [ i ] = vet [n - 1 - i] ;
    }
    for ( int i = 0 ; i < n ; i++ ){    // Copia os elementos ao vetor original;
        vet [ i ] = aux [ i ];
    }
}

double avalia ( double * poli, int grau , double x ){
    double soma = 0.0;                                       // Variável Acumuladora;
    for ( int i = 0 ; i <= grau  ; i ++ ){
        soma = poli [ i ] * pow ( x , i ) + soma;            // Pega o elemento da sequencia e o multiplica por x ^ grau do elemento;
    }
    return soma;
}

void derivada(double *poli, int grau, double *out) {
    for ( int i = 1 ; i <= grau ; i++ ) {                   // i = 1 -> Derivada de constante = 0;
        out[i - 1] = poli [ i ] * i ;                       // Multiplica o elemento pelo seu coeficiente e armazena no auxiliar out;
    }
}

/* Exercício -> Cadeias de caracteres */

int conta_vogais ( char * str ){ // Conta a quantidade de vogais em uma string;
    char c = str [0];                            
    int i = 0; 
    int soma = 0; 
    while ( c != '\0'){ 
        c = str [i]; 
        if ( c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ) soma ++; // A cada vez que aparecer uma vogal soma 1 à variável local;
        i++; 
    } 
    return soma; 
}

int conta_char ( char * str , char c ){ // Conta a quantidade de caracteres em uma string;
    int i = 0; 
    int soma = 0; 
    while ( str [i] != '\0'){ 
        if ( str [i] == c ) soma ++; 
        i++; 
    } 
    return soma;
}

void minusculo ( char * str ){ // Cada vez que tiver um caractere maiusculo o transforma para minusculo;
    int i = 0; 
    while ( str [i] != '\0'){ 
        if ( str [i] >= 'A' && str [i] <= 'Z') str [i] = 'a' + ( str[i] - 'A' ); 
        i++; 
    } 
}

void shift_string ( char * str ){ // Sifra de césar aplicada à strings;
    int i = 0; 
    while ( str [i] != '\0'){ 
        char c = str [i]; 
        if ( (c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z')){ 
            str [i] ++; 
        } 
        if ( c == 'z') str [i] = 'a'; 
        if ( c == 'Z') str [i] = 'A'; 
        i++; 
    } 
}

void string_oposta ( char * str ){ // Pega a string oposta , a -> z , z -> a , ...
    int i = 0; 
    while ( str [i] != '\0'){ 
        char c = str [i]; 
        if ( (c >= 'a' && c <= 'z')) str [i] = 'z' - ( c - 'a'); 
        if ( (c >= 'A' && c <='Z')) str [i] = 'Z' - ( c - 'A'); 
        i++; 
    } 
}

/* Exercício -> Tipos estruturados */

typedef struct { // Estrutura de ponto ( x , y );
    float x; 
    float y; 
} Ponto; 

int dentroRet ( Ponto * v1 , Ponto * v2 , Ponto * p ){ 
    if ( (v1 -> x <= p -> x && p -> x <= v2 -> x) && (v1 -> y <= p -> y && p -> y <= v2 -> y)) return 1; // x pertence ao intervalo [ v1.x , x2.x ] e y pertence ao intervalo [ y1.y , y2.y ]; 
    return 0; 
}

typedef struct { // Estrutura de vetor ( x , y , z );
    float x; 
    float y; 
    float z;
} Vetor; 

float dot ( Vetor * v1 , Vetor * v2 ){ 
    return v1 -> x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z;  // Realiza o produto escalar entre os dois vetores; 
