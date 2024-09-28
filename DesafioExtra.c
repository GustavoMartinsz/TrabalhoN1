#include <stdio.h>

int main() {
    float n1 = 0, n2 = 0, ppd = 0, eu = 0, n3 = 0, media = 0;
    char resposta1, resposta2;


    // nota n1
    
    do {
	 printf("Digite a nota da n1( 0 a 4.5): ");
     scanf("%f", &n1);
        
        if (n1 < 0 || n1 > 4.5) {
     printf("DIGITE NOVAMENTE.\n");
        }
    } while (n1 < 0 || n1 > 4.5);

    // nota n2
    
    do {
     printf("Digite a nota da n2(0 a 4.5): ");
     scanf("%f", &n2);
        
        if (n2 < 0 || n2 > 4.5) {
     printf("DIGITE NOVAMENTE.\n");
        }
    } while (n2 < 0 || n2 > 4.5);

    // nota do ppd
    do {
     printf("Digite a nota do PPD(0 a 1): ");
     scanf("%f", &ppd);
        
        if (ppd < 0 || ppd > 1) {
     printf("DIGITE NOVAMENTE.\n");
        }
    } while (ppd < 0 || ppd > 1);

    // Exame Unificado
    
     printf("Se fez Exame Unificado digite 1: ");
     scanf(" %c", &resposta1);
    
    if (resposta1 == '1') {
        do {
     printf("Digite a nota do Exame Unificado(0 a 1): ");
     scanf("%f", &eu);
            
            if (eu < 0 || eu > 1) {
     printf("DIGITE NOVAMENTE.\n");
            }
        } while (eu < 0 || eu > 1);
    }

    // N3
    
     printf("Se fez N3 digite 1: ");
     scanf(" %c", &resposta2);
    
    if (resposta2 == '1') {
        do {
     printf("Digite a nota da N3(0 a 4.5): ");
     scanf("%f", &n3);
            
            if (n3 < 0 || n3 > 4.5) {
     printf("DIGITE NOVAMENTE.\n");
            }
        } while (n3 < 0 || n3 > 4.5);
    }

        // Calculando a média
    media = n1 + n2 + ppd + eu + n3;
    
     if (media > 10) {
     printf(" a soma das notas não pode ser maior que 10.\n");
    } else {
     printf("A soma das notas: %.2f\n", media);
        
         //aprovado ou reprovado (média >= 7)
         
     if (media >= 7) {
     printf(" Media maior que 7, Voce foi aprovado.\n");
        } else {
     printf(" Media menor que 7, Voce foi reprovado.\n");
        }
    }
    
    return 0;
}
