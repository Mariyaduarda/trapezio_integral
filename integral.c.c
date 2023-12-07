#include <stdio.h>
#include <stdlib.h>
#include <math.h> //inclusao da biblioteca matematica para uso de euler, log, raizes, potencias, erro abosulto/relativo etc

// 1ª função que chamarei no main
double funcao1(double x) {
    return 1.0 / x; // Corrigi a divisão
}

// 2ª função usando euler 
double funcao2(double x) {
    // número de euler = exp();
    return exp(x) * sin(10 * x) + 8;
}

// 3ª função usando logaritmo (ln)
double funcao3(double x) {
    // ln é uma função e não um número, portanto, usando log(x) em C
    return pow(x, 3) * log(x);
}

//formula de trapezio

float formula_trapezio(){
    
    float B; //base maior
    float b; //base menor
    float h; //altura do trapezio
    float area;
    
    printf("Digite a base maior do trapézio: \n");
    scanf("%f", &B);
    printf("Digite a base menor do trapézio: \n");
    scanf("%f", &b);
    printf("Digite a altura do trapézio: \n");
    scanf("%f", &h);
    
    //formula do calculo
     return ((B + b) * h)/ 2; //formula da area 
    
}


//integral trapezio
// Função para calcular a integral usando o método dos trapézios
double trapezio_integral(double a, double b, int n, double (*funcao)(double)) {
    double h = (b - a) / n; // Calcula a largura de cada trapezoide
    double soma = 0;

    //laço em q i tem q ser ir ate n para realizar o calculo do intervalo [a, b]
    for (int i = 1; i < n; i++) { // i tem q ser menor que n para o loop se concretizar
        double x = a + i * h; //calculando o valor da variavel x
        soma += funcao(x); //somando a função
    }

    double integral = h * (0.5 * funcao(a) + soma + 0.5 * funcao(b));
    return integral;
}


//calcular o erro absoluto
double calcularErroAbsoluto(double valorReal, double valorAproximado) {
    return fabs(valorReal - valorAproximado);
}

//calcular o erro relativo
double calcularErroRelativo(double valorReal, double valorAproximado) {
    if (valorReal != 0.0) {
        return fabs(valorReal - valorAproximado) / fabs(valorReal);
    } else {
        // Lidar com o caso em que o valor real é zero para evitar divisão por zero
        return fabs(valorReal - valorAproximado);
    }
}



int main() {
    double resultado; // Variável para armazenar o resultado das funções
    char op;
    int trap;
    int n = trap;//atribuindo n a trap

    // Imprimir o menu
    printf("=================== === ===== === ==================\n");
    printf("     \t\tMENU DAS FUNÇÕES:             \n");
    printf(" 1. Integral [1.0, 7.0] de f(x) = 1/x \n");
    printf(" 2. Integral [0.4, 2.0] de f(x) = e^x sen(10x) + 8 \n");
    printf(" 3. Integral [1.0, 3.0] de f(x) = x^3 ln(x) \n");
    scanf(" %c", &op);

    switch (op) {
        case '1':
            printf("Integral do intervalo [1, 7] de f(x) = 1/x\n");
            double valorReal1 = 1.94591; // valor real da função1

            //entrada do num de trapezios pelo ususario

            printf("Digite o número de trapezoides a usar na aproximação: ");
            scanf("%d", &trap);
            resultado = trapezio_integral(1.0, 7.0, trap, funcao1); //chamando a função da integral do trapezio
            printf("Resultado: %.5lf\n", resultado);

            //chamando funcções declaradas de erro absol/relat
            double erroAbsoluto1 = calcularErroAbsoluto(valorReal1, resultado);
            double erroRelativo1 = calcularErroRelativo(valorReal1, resultado);
            printf("Erro Absoluto: %.51f\n", erroAbsoluto1);
            printf("Erro Relativo: %.5lf\n", erroRelativo1);

            break;
        case '2':
            printf("Integral do intervalo [0.4, 2] de f(x) = e^x sen(10x) + 8\n");
            double valorReal2 = 12.48287; // valor real da função2
            
            //entrada do num de trapezios pelo ususario
            printf("Digite o número de trapezoides a usar na aproximação: ");
            scanf("%d", &trap);
            resultado = trapezio_integral(0.4, 2.0, trap, funcao2);
            printf("Resultado: %.5lf\n", resultado);

            //chamando funcções declaradas de erro absol/relat
            double erroAbsoluto2 = calcularErroAbsoluto(valorReal2, resultado);
            double erroRelativo2 = calcularErroRelativo(valorReal2, resultado);
            printf("Erro Absoluto: %.5lf\n", erroAbsoluto2);
            printf("Erro Relativo: %.5lf\n", erroRelativo2);

            break;
        case '3':
            printf("Integral do intervalo [1, 3] de f(x) = x^3 ln(x)\n");
            double valorReal3 = 17.2469; //valor real para a função 3
            //entrada do num de trapezios pelo ususario
            printf("Digite o número de trapezoides a usar na aproximação: ");
            scanf("%d", &trap);
            resultado = trapezio_integral(1.0, 3.0, trap, funcao3);
            printf("Resultado: %.5lf\n", resultado);

            //chamando funcções declaradas de erro absol/relati
            double erroAbsoluto3 = calcularErroAbsoluto(valorReal3, resultado);
            double erroRelativo3 = calcularErroRelativo(valorReal3, resultado);
            printf("Erro Absoluto: %.5lf\n", erroAbsoluto3); //imprime erro absoluto
            printf("Erro Relativo: %.5lf\n", erroRelativo3); //imprime erro relativo
            break;
        default:
            printf("Erro! Essa função não existe no menu.\n");

            break;
    }

    return 0;
}
