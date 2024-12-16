#include <stdio.h>
#include <stdbool.h> // Para usar booleanos

// Função para calcular a média das duas maiores notas
float calculateAverage(float grade1, float grade2, float grade3) {
    float minGrade;

    // Identifica a menor nota
    if (grade1 <= grade2 && grade1 <= grade3) {
        minGrade = grade1;
    } else if (grade2 <= grade1 && grade2 <= grade3) {
        minGrade = grade2;
    } else {
        minGrade = grade3;
    }

    // Soma as duas maiores notas e calcula a média
    return (grade1 + grade2 + grade3 - minGrade) / 2;
}

// Função para obter uma entrada de número inteiro com validação
bool getInputInt(const char *prompt, int *value, int min, int max) {
    int temp;
    while (true) {
        printf("%s", prompt);
        if (scanf("%d", &temp) == 1 && temp >= min && temp <= max) {
            *value = temp;
            return true;
        }
        printf("Entrada inválida! Insira um valor entre %d e %d.\n", min, max);
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
}

// Função para obter uma entrada de float com validação
bool getInputFloat(const char *prompt, float *value, float min, float max) {
    float temp;
    while (true) {
        printf("%s", prompt);
        if (scanf("%f", &temp) == 1 && temp >= min && temp <= max) {
            *value = temp;
            return true;
        }
        printf("Entrada inválida! Insira um valor entre %.2f e %.2f.\n", min, max);
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
}

int main() {
    // Variáveis principais
    int option;
    float ap1, ap2, ap3;
    char name[50];
    char subject[50];
    int attendanceDays;
    float average;

    // Menu inicial
    printf("Seja bem-vindo à Escola Futuro Brilhante\n");
    printf("Informe o nome do aluno:\n");
    scanf("%s", name);

    while (true) {
        printf("Bem-vindo %s, escolha uma das opções abaixo:\n", name);
        printf("1 - Média do aluno\n");
        printf("2 - Frequência do aluno\n");
        printf("3 - Resultado geral\n");
        printf("4 - Sair\n");

        // Obtém a opção do usuário
        if (!getInputInt("Digite sua escolha: ", &option, 1, 4)) continue;

        // Processa a opção selecionada
        switch (option) {
            case 1:
                printf("%s, informe a matéria que deseja ver a média:\n", name);
                scanf("%s", subject);

                // Entrada das notas
                getInputFloat("Informe qual foi sua nota na AP1 (0 a 10):\n", &ap1, 0, 10);
                getInputFloat("Informe qual foi sua nota na AP2 (0 a 10):\n", &ap2, 0, 10);
                getInputFloat("Informe qual foi sua nota na AP3 (0 a 10):\n", &ap3, 0, 10);

                // Calcula a média
                average = calculateAverage(ap1, ap2, ap3);
                printf("A média das duas maiores notas em %s é: %.2f\n", subject, average);
                break;

            case 2:
                printf("%s, informe o número de dias que compareceu (0 a 30):\n", name);
                getInputInt("Digite o número de dias: ", &attendanceDays, 0, 30);

                int attendancePercentage = (attendanceDays * 100) / 30;
                printf("Frequência calculada: %d%%\n", attendancePercentage);

                if (attendancePercentage >= 75) {
                    printf("Frequência suficiente: %d%%.\n", attendancePercentage);
                } else {
                    printf("Frequência insuficiente: %d%%.\n", attendancePercentage);
                }
                break;

            case 3:
                printf("%s, informe a matéria que deseja ver o resultado geral:\n", name);
                scanf("%s", subject);

                // Entrada das notas e frequência
                getInputFloat("Informe qual foi sua nota na AP1 (0 a 10):\n", &ap1, 0, 10);
                getInputFloat("Informe qual foi sua nota na AP2 (0 a 10):\n", &ap2, 0, 10);
                getInputFloat("Informe qual foi sua nota na AP3 (0 a 10):\n", &ap3, 0, 10);
                getInputInt("Informe o número de dias que compareceu (0 a 30):\n", &attendanceDays, 0, 30);

                attendancePercentage = (attendanceDays * 100) / 30;

                // Calcula a média e verifica aprovação
                average = calculateAverage(ap1, ap2, ap3);
                printf("Resultado geral para %s:\n", subject);
                printf("Média: %.2f\n", average);
                printf("Frequência: %d%%\n", attendancePercentage);

                if (average >= 7.0 && attendancePercentage >= 75) {
                    printf("Situação: Aprovado\n");
                } else {
                    printf("Situação: Reprovado\n");
                }
                break;

            case 4:
                printf("Obrigado por usar o programa. Até logo!\n");
                return 0;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}
