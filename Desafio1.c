#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 100

double f(double b, int x) {
    // Coeficientes
    double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    // Calcular f(x, b)
    return a0 + (a1 + b) * x + a2 * x * x + a3 * x * x * x + 
           a4 * x * x * x * x + a5 * x * x * x * x * x + 
           a6 * x * x * x * x * x * x + a7 * x * x * x * x * x * x * x;
}

void decodeMessage(int b, char *hexMessage) {
    char output[MAX_MSG_LENGTH + 1]; // +1 para o terminador nulo
    int index = 0;
    
    for (int i = 0; i < MAX_MSG_LENGTH; i += 2) {
        // Verificar se o caractere nulo (00) é encontrado
        if (hexMessage[i] == '0' && hexMessage[i + 1] == '0') {
            break; // Encerra a leitura
        }

        // Convertendo os dois caracteres hexadecimais em um valor decimal
        char hexChar[3] = { hexMessage[i], hexMessage[i + 1], '\0' };
        int charValue = (int)strtol(hexChar, NULL, 16);

        // Calcular a função f(x, b)
        double result = f(b, (index + 1));

        // Ignorar caracteres inválidos (não ASCII)
        if (charValue >= 32 && charValue <= 126) {
            output[index++] = (char)charValue;
        }
    }

    output[index] = '\0'; // Terminar a string

    printf("Mensagem decodificada: %s\n", output);
}

int main() {
    int numMessages;
    
    printf("Digite o número de mensagens interceptadas: ");
    scanf("%d", &numMessages);

    for (int i = 0; i < numMessages; i++) {
        int b;
        char hexMessage[MAX_MSG_LENGTH + 1]; // +1 para o terminador nulo

        printf("Digite o valor de b (-100 a 100) e a mensagem em hexadecimal: ");
        scanf("%d %s", &b, hexMessage);

        decodeMessage(b, hexMessage);
    }

    return 0;
}