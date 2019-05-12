#include <stdio.h>
#include <stdlib.h>
#include "./machineInstG.h"
#include <string.h>


void allouerG(InstructionG** nouveau)
{
    *nouveau=(InstructionG*) malloc(sizeof(InstructionG));
}

void libererG(InstructionG** ancien)
{
    free(*ancien); *ancien=NULL;
}

void aff_Etat1G(InstructionG* p,int q)
{
    p->Etat1=q;
}

void aff_Etat2G(InstructionG* p,int q)
{
    p->Etat2=q;
}

void aff_Mot(InstructionG* p, char* m)
{
    strcpy(p->mot,m);
}

void aff_AdrG(InstructionG* p, InstructionG* adr)
{
    p->suivant=adr;
}

int valEtat1G(InstructionG* p)
{
    return p->Etat1;
}

int valEtat2G(InstructionG* p)
{
    return p->Etat2;
}

char* valMotG(InstructionG* p)
{
    return p->mot;
}

InstructionG* SuivantG(InstructionG* p)
{
    return p->suivant;
}

