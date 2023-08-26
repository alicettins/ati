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

void preencheAluno(Aluno* ptrAluno, 
                   int matricula,
                   float nota,
                   char* nome){
    (*ptrAluno).matricula = matricula;
    (*ptrAluno).nota = nota;
    strcpy((*ptrAluno).nome, nome);
}

void inicializaLista(ListaAlunos* listaAlunos){
    listaAlunos->numElem = 0;
}

void exibeLista(ListaAlunos* listaAlunos){
    int index;
    printf("Exibindo lista...\n");
    for(index = 0; index < listaAlunos->numElem; index++){
        printf("Aluno %d\n", index);
        printf("Nome: %s\n", listaAlunos->alunos[index].nome);
        printf("Matricula: %d\n", listaAlunos->alunos[index].matricula);
        printf("Nota: %.1f\n", listaAlunos->alunos[index].nota);
    }
}

bool insereAlunoNaLista(ListaAlunos* listaAlunos, 
                        Aluno aluno,
                        int posicao){
    if((listaAlunos->numElem >= MAXSIZE) || 
       (posicao < 0) || 
       (posicao > MAXSIZE) ||
       (posicao > listaAlunos->numElem)){
        printf("Insercao em posicao invalida!!!\n");
        return false;
    }
    int index;
    for(index = listaAlunos->numElem; index > posicao; index--){
        listaAlunos->alunos[index] = listaAlunos->alunos[index-1];
    }
    listaAlunos->alunos[posicao] = aluno;
    listaAlunos->numElem++;
    return true;
}

bool excluiElementoDaLista(ListaAlunos* listaAlunos, int posicao){
    if((listaAlunos->numElem >= MAXSIZE) || 
       (posicao < 0) || 
       (posicao > MAXSIZE) ||
       (posicao >= listaAlunos->numElem)){
        printf("Exclusao em posicao invalida!!!\n");
        return false;
    }
    int index;
    for(index = posicao; index < listaAlunos->numElem - 1; index++){
        listaAlunos->alunos[index] = listaAlunos->alunos[index+1];
    }
    listaAlunos->numElem--;
    return true;
}


int buscaAlunoPorNome(ListaAlunos* listaAlunos, const char* nome) {
    for (int i = 0; i < listaAlunos->numElem; i++) {
        if (strcmp(listaAlunos->alunos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1; 
}

int buscaAlunoPorMatricula(ListaAlunos* listaAlunos, int matricula) {
    for (int i = 0; i < listaAlunos->numElem; i++) {
        if (listaAlunos->alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1; 
}

Aluno retornaEnesimoAluno(ListaAlunos* listaAlunos, int n) {
    if (n >= 0 && n < listaAlunos->numElem) {
        return listaAlunos->alunos[n];
    }
    Aluno alunoVazio; 
    alunoVazio.matricula = -1;
    alunoVazio.nota = -1;
    alunoVazio.nome[0] = '\0';
    return alunoVazio;
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
    
    exibeLista(&listaAlunos);
    
    int posicaoNome = buscaAlunoPorNome(&listaAlunos, "Ana");
    if (posicaoNome != -1) {
        printf("Aluno encontrado por nome:\n");
        printf("Nome: %s\n", listaAlunos.alunos[posicaoNome].nome);
        printf("Matricula: %d\n", listaAlunos.alunos[posicaoNome].matricula);
        printf("Nota: %.1f\n", listaAlunos.alunos[posicaoNome].nota);
    } else {
        printf("Aluno não encontrado por nome.\n");
    }
    
    int posicaoMatricula = buscaAlunoPorMatricula(&listaAlunos, 15424242);
    if (posicaoMatricula != -1) {
        printf("Aluno encontrado por matricula:\n");
        printf("Nome: %s\n", listaAlunos.alunos[posicaoMatricula].nome);
        printf("Matricula: %d\n", listaAlunos.alunos[posicaoMatricula].matricula);
        printf("Nota: %.1f\n", listaAlunos.alunos[posicaoMatricula].nota);
    } else {
        printf("Aluno não encontrado por matricula.\n");
    }
    
    int enesimo = 1;
    Aluno alunoEnesimo = retornaEnesimoAluno(&listaAlunos, enesimo);
    printf("Enésimo aluno na lista:\n");
    printf("Nome: %s\n", alunoEnesimo.nome);
    printf("Matricula: %d\n", alunoEnesimo.matricula);
    printf("Nota: %.1f\n", alunoEnesimo.nota);
    
    return 0;
}

