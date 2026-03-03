#include <stdio.h>
#include <ctype.h>

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

void resp(int n, double a, double b){

    double ans = 0;

    if(n == 4 && b == 0){
        printf("Erro: Divisão por zero não é permitida.\n");
        return;
    }
    else if(n == 1){
        ans = a + b;
        printf("Resultado: %.10g + %.10g = %.10g\n", a, b, ans);
    }
    else if(n == 2){
        ans = a - b;
        printf("Resultado: %.10g - %.10g = %.10g\n", a, b, ans);
    }
    else if(n == 3){
        ans = a * b;
        printf("Resultado: %.10g * %.10g = %.10g\n", a, b, ans);
    }
    else if(n == 4){
        ans = a / b;
        printf("Resultado: %.10g / %.10g = %.10g\n", a, b, ans);
    }
}

int main(){

    char d;

    while(1){

        menu();
        
        int n;

        // valida opção
        while(scanf("%d", &n) != 1 || n < 1 || n > 5){
            printf("Opção inválida!\n");
            printf("Selecione uma operação válida: ");
            while(getchar() != '\n'); // limpa buffer
        }

        if(n == 5){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        }

        double a, b;

        printf("Digite o primeiro número: ");
        scanf("%lf", &a);

        printf("Digite o segundo número: ");
        scanf("%lf", &b);

        resp(n, a, b);

        // pergunta se quer continuar
        while(1){
            printf("Deseja realizar outra operação? (s/n): ");
            scanf(" %c", &d);   // espaço antes do %c é importante
            d = tolower(d);

            if(d == 's' || d == 'n')
                break;

            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
        }

        if(d == 'n'){
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        }

    }
}
