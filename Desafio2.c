#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#ifndef REMOVE_H
#define REMOVE_H
#endif
int func_val(int x, int b);

//  retorna o valor arredondado 
int func_val(int x, int b) {
    double result = x / (double)b;
    return round(result);
}
//  tabela com os limites das variaveis
void print_limits() {
	
    printf("-------------------------------------------------------------------------\n");
    printf("| Tipo                    | Minimo               | Maximo               |\n");
    printf("-------------------------------------------------------------------------\n");

    printf("| char                    | %20d | %20d |\n", CHAR_MIN, CHAR_MAX);
    
    printf("| int                     | %20d | %20d |\n", INT_MIN, INT_MAX);
    
    printf("| short int               | %20d | %20d |\n", SHRT_MIN, SHRT_MAX);

    printf("| unsigned int            | %20u | %20u |\n", 0, UINT_MAX);

    printf("| long int                | %20ld | %20ld |\n", LONG_MIN, LONG_MAX);
  
    printf("| unsigned long int       | %20lu | %20lu |\n", 0UL, ULONG_MAX);
    
    printf("| long long int           | %20lld | %20lld |\n", LLONG_MIN, LLONG_MAX);

    printf("| unsigned long long int  | %20llu | %20llu |\n", 0ULL, ULLONG_MAX);
    
    printf("-------------------------------------------------------------------------\n");

}
// Função de overflow
void demonstrate_overflow() {
    unsigned char a = 255; 
    a += 1; 
    printf("Valor de 'a' apos exceder o limite: %u (overflow ocorreu)\n", a);
}
//  decifrar a mensagem hexadecimal
void decrypt_message(int b, char *ciphered) {
    int len = strlen(ciphered);
    printf("Mensagem decifrada: ");
    
    for (int i = 0; i < len; i += 2) {
        char hex[3];
        hex[0] = ciphered[i];
        hex[1] = ciphered[i + 1];
        hex[2] = '\0';

        int decimal_value;
        sscanf(hex, "%x", &decimal_value);

        int val = func_val(decimal_value, b);
        if (val != 0) {
            printf("%c", val);
        }
    }
    printf("\n");
}

int main() {
    //  Limites das variáveis
    print_limits();
    
    // Exemplo de overflow
    demonstrate_overflow();
    
    // Decifrar a mensagem
    int test_cases;
    printf("Digite o numero de casos de teste: ");
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        int b;
        char ciphered[100];

        printf("Digite o valor de b: ");
        scanf("%d", &b);

        printf("Digite a mensagem cifrada (em hexadecimal): ");
        scanf("%s", ciphered);

        decrypt_message(b, ciphered);
    }
    return 0;
}
