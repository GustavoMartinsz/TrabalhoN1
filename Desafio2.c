#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#ifndef REMOVE_H
#define REMOVE_H
#endif

// Função para ter o valor arredondado
int calcular_valor(int x, int b) {
    double resultado = (double)x / b;
    return (int)round(resultado);
}

// Tabela 
void exibir_limites() {

    printf("| Tipo                   | Valor Minimo    | Valor Maximo |\n");
    printf("| char                   | %20d | %20d |\n", CHAR_MIN, CHAR_MAX);
    printf("| int                    | %20d | %20d |\n", INT_MIN, INT_MAX);
    printf("| short int              | %20d | %20d |\n", SHRT_MIN, SHRT_MAX);
    printf("| unsigned int           | %20u | %20u |\n", 0, UINT_MAX);
    printf("| long int               | %20ld | %20ld |\n", LONG_MIN, LONG_MAX);
    printf("| unsigned long int      | %20lu | %20lu |\n", 0UL, ULONG_MAX);
    printf("| long long int          | %20lld | %20lld |\n", LLONG_MIN, LLONG_MAX);
    printf("| unsigned long long int | %20llu | %20llu |\n", 0ULL, ULLONG_MAX);

}

// demonstra o overflow em unsigned char
void exemplo_overflow() {
    unsigned char a = 255;
    a++; // Incrementa a variável 'a' e provoca overflow
    printf("Valor de 'a' apos overflow: %u\n", a);
}

// Função que decifra a mensagem hexadecimal
void decifrar_mensagem(int b, const char *cifrada) {
    int tamanho = strlen(cifrada);
    printf("Mensagem decifrada: ");

    for (int i = 0; i < tamanho; i += 2) {
        char parte_hex[3] = {cifrada[i], cifrada[i+1], '\0'};
        int valor_decimal;
        sscanf(parte_hex, "%x", &valor_decimal);

        int valor_decifrado = calcular_valor(valor_decimal, b);
        if (valor_decifrado != 0) {
            printf("%c", valor_decifrado);
        }
    }
    printf("\n");
}

int main() {
    //  limites das variáveis
    exibir_limites();

    // Demonstra o overflow
    exemplo_overflow();

    // número de casos de teste
    int casos_de_teste;
    printf("Informe o numero de casos de teste: ");
    scanf("%d", &casos_de_teste);

    // Loop para processar cada caso de teste
    for (int i = 0; i < casos_de_teste; i++) {
        int b;
        char mensagem_cifrada[100];

        // Lê o valor de 'b' e a mensagem cifrada em hexadecimal
        printf("Informe o valor de b: ");
        scanf("%d", &b);

        printf("Digite a mensagem cifrada (em hexadecimal): ");
        scanf("%s", mensagem_cifrada);

        decifrar_mensagem(b, mensagem_cifrada);
    }

    return 0;
}
