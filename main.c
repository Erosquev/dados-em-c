/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 25

int comparacao (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int diferente(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    FILE *input = fopen("dados.txt", "r");
    if (!input) {
        printf("Erro ao abrir o arquivo dados.txt\n");
        return 1;
    }
    
    int n;
    fscanf(input, "%d", &n); 
    if (n > MAX_NUMEROS || n < 3) {
        printf("Erro: Quantidade de números fora do limite permitido\n");
        fclose(input);
        return 1;
    }
    
    int numeros[MAX_NUMEROS];
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &numeros[i]);
    }
    fclose(input);
    
    int positivos = 0, negativos = 0, zeros = 0;
    int pares = 0, impares = 0;
    int diferentes[MAX_NUMEROS];
    int tamanho_diferentes = 0;
    
     for (int i = 0; i < n; i++) {
        if (numeros[i] > 0) {
            positivos++;
        } else if (numeros[i] < 0) {
            negativos++;
        } else {
            zeros++;
        }

        if (numeros[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        
        if (diferente(diferentes, tamanho_diferentes, numeros[i])) {
            diferentes[tamanho_diferentes++] = numeros[i];
        }
    }
    
    FILE *estatisticas = fopen("estatisticas.txt", "w");
    if (!estatisticas) {
        printf("Erro ao criar o arquivo estatisticas.txt\n");
        return 1;
    }
    fprintf(estatisticas, "Quantidade de numeros positivos: %d\n", positivos);
    fprintf(estatisticas, "Quantidade de numeros negativos: %d\n", negativos);
    fprintf(estatisticas, "Quantidade de numeros zero: %d\n", zeros);
    fprintf(estatisticas, "Quantidade de numeros pares: %d\n", pares);
    fprintf(estatisticas, "Quantidade de numeros impares: %d\n", impares);
    fclose(estatisticas);
    
    FILE *distintos_arquivo = fopen("distintos.txt", "w");
    if (!distintos_arquivo) {
        printf("Erro ao criar o arquivo distintos.txt\n");
        return 1;
    }
    for (int i = 0; i < tamanho_diferentes; i++) {
        fprintf(distintos_arquivo, "%d ", diferentes[i]);
    }
    fprintf(distintos_arquivo, "\n");
    fclose(distintos_arquivo);

  return 0;
}

    
    
    
    
    
    
    
