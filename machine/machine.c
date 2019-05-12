#include <stdio.h>
#include <stdlib.h>
#include "./machine.h"
#include <string.h>


void allouer(Instruction** nouveau)
{
    *nouveau=(Instruction*) malloc(sizeof(Instruction));
}

void liberer(Instruction** ancien)
{
    free(*ancien); *ancien=NULL;
}

void aff_Etat1(Instruction* p,int q)
{
    p->Etat1=q;
}

void aff_Etat2(Instruction* p,int q)
{
    p->Etat2=q;
}

void aff_Lettre(Instruction* p, char l)
{
    p->lettre=l;
}

void aff_Adr(Instruction* p, Instruction* adr)
{
    p->suivant=adr;
}

int valEtat1(Instruction* p)
{
    return p->Etat1;
}

int valEtat2(Instruction* p)
{
    return p->Etat2;
}

char valLettre(Instruction* p)
{
    return p->lettre;
}

Instruction* Suivant(Instruction* p)
{
    return p->suivant;
}


//***************************************************************************************

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

void aff_MotG(InstructionG* p, char* m)
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

