#ifndef MACHINEINSTG_H_INCLUDED
#define MACHINEINSTG_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../fonctions.h"
#define max 30



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
    int EtatsG[max];
    int EtatInitG;
    int EtatFinG[max];
    InstructionG* InstructionsG;
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
