#include <stdio.h>

// menu
void menu(){
    printf("===============================\n");
    printf("   Calculadora Simples         \n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");
}

void resp(int n, int a, int b){

    if(n == 4 && b == 0){
        printf("Erro: Divisão por zero não é permitida.\n");
        return;
    }

    int ans = 0;

    if(n == 1){
        ans = a + b;
        printf("Resultado: %d + %d = %d\n", a, b, ans);
    }
    else if(n == 2){
        ans = a - b;
        printf("Resultado: %d - %d = %d\n", a, b, ans);
    }
    else if(n == 3){
        ans = a * b;
        printf("Resultado: %d * %d = %d\n", a, b, ans);
    }
    else if(n == 4){
        ans = a / b;
        printf("Resultado: %d / %d = %d\n", a, b, ans);
    }
}

int main(){

    char d;

    while(1){   // while(true) em C vira while(1)

        menu();

        int n, a, b;
        scanf("%d", &n);

        while(n != 1 && n != 2 && n != 3 && n != 4 && n != 5){
            printf("Opção inválida!\n");
            printf("Selecione uma operação válida: ");
            scanf("%d", &n);
        }

        if(n == 5){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        }

        printf("Digite o primeiro número: ");
        scanf("%d", &a);

        printf("Digite o segundo número: ");
        scanf("%d", &b);

        resp(n, a, b);

        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &d);   // espaço antes do %c é IMPORTANTE

        if(d != 's'){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        }
    }

    return 0;
}