#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include "machine/machine.h"
#define max 30

int ConstAG(AutomateG *AG);

void isFinal(int *tab, int n,int *nbFinal);

void InstG(int nbInst, InstructionG** listInst, int nbEtat, int nbMot, String* Alpha );

int verifG(InstructionG* liste, InstructionG* inst);

int verifMot(String* Alpha, int taille, String mot );

int verifEtat(int nbEtat, int etat);

int SemiG(AutomateG AG, Automate *ASG);

int verifLettre(char *Tab, int taille, char lettre);

void menu();

int Simple(Automate *autoS);

void ajouterInst(Instruction *t, Instruction *p);

Instruction* supprimerInst(Instruction *tete, Instruction** p);

void rechInst(Instruction* tete, Instruction** pre, Instruction* p);

int verifFinal(int *Tab, int taille, int etat);

#endif // FONCTIONS_H_INCLUDED
