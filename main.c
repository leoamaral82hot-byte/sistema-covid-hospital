
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente {
    char nome[100];
    char cpf[20];
    char telefone[20];
    char rua[100];
    char bairro[50];
    char cidade[50];
    char estado[5];
    char cep[15];
    char email[100];
    int dia, mes, ano;
    int diaDiag, mesDiag, anoDiag;
    int idade;
    char comorbidade[100];
};

int calcularIdade(int anoNascimento) {
    int anoAtual = 2025;
    return anoAtual - anoNascimento;
}

void cadastrarPaciente() {
    struct Paciente p;
    FILE *arquivo;
    FILE *grupoRisco;

    arquivo = fopen("pacientes.txt", "a");
    grupoRisco = fopen("grupo_risco.txt", "a");

    if (arquivo == NULL || grupoRisco == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    printf("\n--- CADASTRO DE PACIENTE COVID-19 ---\n");

    printf("Nome: ");
    fflush(stdin);
    gets(p.nome);

    printf("CPF: ");
    gets(p.cpf);

    printf("Telefone: ");
    gets(p.telefone);

    printf("Rua: ");
    gets(p.rua);

    printf("Bairro: ");
    gets(p.bairro);

    printf("Cidade: ");
    gets(p.cidade);

    printf("Estado: ");
    gets(p.estado);

    printf("CEP: ");
    gets(p.cep);

    printf("E-mail: ");
    gets(p.email);

    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &p.dia, &p.mes, &p.ano);

    printf("Data do diagnostico (dd mm aaaa): ");
    scanf("%d %d %d", &p.diaDiag, &p.mesDiag, &p.anoDiag);

    printf("Comorbidade (Nenhuma, diabetes, hipertensao, obesidade etc): ");
    fflush(stdin);
    gets(p.comorbidade);

    p.idade = calcularIdade(p.ano);

    fprintf(arquivo,
        "Nome: %s\nCPF: %s\nTelefone: %s\nEndereco: %s, %s, %s-%s\nCEP: %s\nE-mail: %s\nNascimento: %d/%d/%d\nDiagnostico: %d/%d/%d\nComorbidade: %s\nIdade: %d\n\n",
        p.nome, p.cpf, p.telefone, p.rua, p.bairro, p.cidade, p.estado, p.cep, p.email,
        p.dia, p.mes, p.ano, p.diaDiag, p.mesDiag, p.anoDiag, p.comorbidade, p.idade);

    if (p.idade >= 65 || strcmp(p.comorbidade, "Nenhuma") != 0) {
        fprintf(grupoRisco, "CEP: %s - Idade: %d\n", p.cep, p.idade);
        printf("Paciente pertence ao GRUPO DE RISCO!\n");
    }

    fclose(arquivo);
    fclose(grupoRisco);

    printf("Paciente cadastrado com sucesso!\n");
}

void login() {
    char usuario[20], senha[20];

    printf("Usuario: ");
    gets(usuario);

    printf("Senha: ");
    gets(senha);

    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "123") == 0) {
        printf("Login realizado com sucesso!\n");
        cadastrarPaciente();
    } else {
        printf("Usuario ou senha incorretos!\n");
    }
}

int main() {
    int opcao;

    do {
        system("cls");
        printf("=== SISTEMA COVID-19 - HOSPITAL ===\n");
        printf("1 - Login\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
        case 1:
            login();
            system("pause");
            break;
        case 0:
            printf("Encerrando o sistema...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            system("pause");
        }
    } while (opcao != 0);

    return 0;
}
