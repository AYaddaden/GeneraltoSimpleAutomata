#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define max 30
typedef struct Instruction
{
    int Etat1;
    char lettre;
    int Etat2;
    struct Instruction* suivant;
}Instruction;

typedef struct Automate{
    char Alphabet[max];
    int Etats;
    //int EtatInit;
    int EtatFin[max];
    int nbFinal;
    Instruction* Instructions;
    int nbInst;
}Automate;


void allouer(Instruction** nouveau);

void liberer(Instruction** ancien);

void aff_Etat1(Instruction* p,int q);

void aff_Etat2(Instruction* p,int q);

void aff_Lettre(Instruction* p, char l);

void aff_Adr(Instruction* p, Instruction* adr);

int valEtat1(Instruction* p);

int valEtat2(Instruction* p);

char valLettre(Instruction* p);

Instruction* Suivant(Instruction* p);



//***************************************************************************************
//                               Automate généralisé
//***************************************************************************************

typedef struct InstructionG
{
    int Etat1;
    char mot[max];
    int Etat2;
    struct InstructionG* suivant;
}InstructionG;

typedef struct String{
    char a[10];
    }String;

typedef struct AutomateG{
    String AlphabetG[max];
    int nbMot;
    int EtatG;
    //int EtatsG[max];
    //int EtatInitG;
    int EtatFinG[max];
    int nbFinal;
    InstructionG* InstructionsG;
    int nbInstG;
}AutomateG;

void allouerG(InstructionG** nouveau);

void libererG(InstructionG** ancien);

void aff_Etat1G(InstructionG* p,int q);

void aff_Etat2G(InstructionG* p,int q);

void aff_MotG(InstructionG* p, char* m);

void aff_AdrG(InstructionG* p, InstructionG* adr);

int valEtat1G(InstructionG* p);

int valEtat2G(InstructionG* p);

char* valMotG(InstructionG* p);

InstructionG* SuivantG(InstructionG* p);








#endif // FONCTIONS_H_INCLUDED
