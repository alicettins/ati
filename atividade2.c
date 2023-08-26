#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct Aluno {
    char nome[20];
    int matricula;
    float nota;
} Aluno;

typedef struct ListaAlunos {
    Aluno alunos[MAXSIZE];
    int numElem;
} ListaAlunos;

void insereAlunoEmOrdem(ListaAlunos* listaAlunos, Aluno aluno) {
    int index = listaAlunos->numElem;
    while (index > 0 && strcmp(aluno.nome, listaAlunos->alunos[index - 1].nome) < 0) {
        listaAlunos->alunos[index] = listaAlunos->alunos[index - 1];
        index--;
    }
    listaAlunos->alunos[index] = aluno;
    listaAlunos->numElem++;
}

int buscaSequencialComSentinela(ListaAlunos* listaAlunos, const char* nome) {
    
    Aluno sentinela;
    strcpy(sentinela.nome, nome);
    listaAlunos->alunos[listaAlunos->numElem] = sentinela;

    int index = 0;
    while (strcmp(nome, listaAlunos->alunos[index].nome) != 0) {
        index++;
    }

    if (index < listaAlunos->numElem) {
        return index;
    }
    
    return -1;
}

int buscaBinariaPorNome(ListaAlunos* listaAlunos, const char* nome) {
    int inicio = 0;
    int fim = listaAlunos->numElem - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int comparacao = strcmp(nome, listaAlunos->alunos[meio].nome);

        if (comparacao == 0) {
            return meio;
        } else if (comparacao < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

int main(){
    ListaAlunos listaAlunos;
    inicializaLista(&listaAlunos);

    Aluno aluno0, aluno1, aluno2;
    preencheAluno(&aluno0, 15424242, 9.5, "Joao");
    preencheAluno(&aluno1, 10101011, 10, "Ana");
    preencheAluno(&aluno2, 22222222, 7, "Bia");

    insereAlunoNaLista(&listaAlunos, aluno0, 0);
    insereAlunoNaLista(&listaAlunos, aluno1, 0);
    insereAlunoNaLista(&listaAlunos, aluno2, 1);

    for (int i = 1; i < listaAlunos.numElem; i++) {
        insereAlunoEmOrdem(&listaAlunos, listaAlunos.alunos[i]);
    }
    
    exibeLista(&listaAlunos);

    printf("Busca sequencial com sentinela:\n");
    int posicaoSentinela = buscaSequencialComSentinela(&listaAlunos, "Ana");
    if (posicaoSentinela != -1) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", listaAlunos.alunos[posicaoSentinela].nome);
        printf("Matricula: %d\n", listaAlunos.alunos[posicaoSentinela].matricula);
        printf("Nota: %.1f\n", listaAlunos.alunos[posicaoSentinela].nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    printf("Busca binária por nome:\n");
    int posicaoBinaria = buscaBinariaPorNome(&listaAlunos, "Ana");
    if (posicaoBinaria != -1) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", listaAlunos.alunos[posicaoBinaria].nome);
        printf("Matricula: %d\n", listaAlunos.alunos[posicaoBinaria].matricula);
        printf("Nota: %.1f\n", listaAlunos.alunos[posicaoBinaria].nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    return 0;
}

