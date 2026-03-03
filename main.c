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
        printf("Error: Division by zero is not allowed.\n");
        return;
    }
    else if(n == 1){
        ans = a + b;
        printf("Result: %.10g + %.10g = %.10g\n", a, b, ans);
    }
    else if(n == 2){
        ans = a - b;
        printf("Result: %.10g - %.10g = %.10g\n", a, b, ans);
    }
    else if(n == 3){
        ans = a * b;
        printf("Result: %.10g * %.10g = %.10g\n", a, b, ans);
    }
    else if(n == 4){
        ans = a / b;
        printf("Result: %.10g / %.10g = %.10g\n", a, b, ans);
    }
}

int main(){

    char d;

    while(1){

        menu();
        
        int n;

        // valida opção (1 a 5)
        while(scanf("%d", &n) != 1 || n < 1 || n > 5){
            printf("Invalid option!\n");
            printf("Select a valid option: ");
            while(getchar() != '\n'); // limpa buffer
        }

        if(n == 5){
            printf("Thank you for using the calculator! See you next time.\n");
            return 0;
        }

        double a, b;

        printf("Enter the first number: ");
        scanf("%lf", &a);

        printf("Enter the second number: ");
        scanf("%lf", &b);

        resp(n, a, b);

        // pergunta se quer continuar
        while(1){
            printf("Do you want to perform another operation? (y/n): ");
            scanf(" %c", &d);
            d = tolower(d);

            if(d == 'y' || d == 'n')
                break;

            printf("Invalid response. Please enter 'y' for yes or 'n' for no.\n");
        }

        if(d == 'n'){
            printf("Thank you for using the calculator! See you next time.\n");
            return 0;
        }
    }
}
