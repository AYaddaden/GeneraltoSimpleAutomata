#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "machine/machine.h"
#include <ctype.h>


//le & est le mot vide ε puisque cette dernière lettre n'éxiste pas sur tous les claviers

void menu()
{
    printf("Le menu:\n\n");
    printf("\t1) Construire l'automate generalise\n");
    printf("\t2) Voir l'automate generalise\n");
    printf("\t3) Construire l'automate semi-generalise\n");
    printf("\t4) Voir l'automate semi-generalise\n");
    printf("\t5) Construire l'automate simple\n");
    printf("\t6) Voir l'automate simple\n");
    printf("\t0) Sortir\n\n");
}

int ConstAG(AutomateG *AG)
{
    int nbMot=0;
    int i=0;
    char mot[max]="";
    int nbEtat=0;
    int nbFinal=0;
    int nbInst=0;
    while(nbMot<=0)// || (!autoCree))
    {
        printf("\nDonner le nombre de mots de X*: ");
        scanf("%d",&nbMot);
    }
    (AG->nbMot)=nbMot;
    for(i=0; i<nbMot; i++)
    {
        printf("\nMot %d:",i);
        sprintf(mot,"%s","");
        scanf("%s",mot);
        getchar();
        strcpy(AG->AlphabetG[i].a,mot);
    }
    while (nbEtat<=0)
    {
        printf("\nDonner le nombre d'etats: ");
        scanf("%d",&nbEtat);
    }
    AG->EtatG=nbEtat;
    nbFinal=0;
    while(nbFinal<=0)
    {
        isFinal(AG->EtatFinG, nbEtat, &nbFinal);
        if (nbFinal==0)
        {
            printf("\nAucun etat final! Recommencez.\n\n");
        }
    }
    AG->nbFinal=nbFinal;
    nbInst=0;
    while(nbInst<=0)
    {
        printf("Donnez le nombre d'instructions: ");
        scanf("%d",&nbInst);
    }
    AG->nbInstG=nbInst;
    InstG(nbInst, &(AG->InstructionsG), nbEtat, nbMot, AG->AlphabetG);
    /*InstructionG* p=AG->InstructionsG;
    while(p!=NULL)
    {
        printf("%d %s %d \n",valEtat1G(p),valMotG(p),valEtat2G(p));
        p=SuivantG(p);

    }*/
    return 1;
}

void InstG(int nbInst, InstructionG** listInst, int nbEtat, int nbMot, String* Alpha )
{
    int i=0;
    int etatDep=0;
    int etatArv=0;
    String mot;
    InstructionG *inst=NULL;
    InstructionG *k=NULL;
    //allouer(&inst);
    int exist=1;
    int appartient=0;
    *listInst=NULL;
    for(i=0;i<nbInst;i++)
    {
        printf("Nouvelle instruction:\n");
        k=inst;
        allouerG(&inst);
        exist=1;
        while(exist)
       {
            appartient=0;
            while (!appartient)
            {
                getchar();
                printf("Etat de depart: S");
                scanf("%d",&etatDep);
                appartient=verifEtat(nbEtat,etatDep);
                if (!appartient)
                {
                    printf("Cet etat n'existe pas dans la table des etats!\n");
                }
            }
            appartient=0;
            while(!appartient)
            {
                getchar();
                printf("Mot: ");
                scanf("%s", mot.a);
                appartient=verifMot(Alpha,nbMot,mot);
                if (!appartient)
                {
                    printf("Ce mot ne fait pas partie de X*!\n");
                }
            }
            appartient=0;
            while(!appartient)
            {
                getchar();
                printf("Etat d'arrivee: S");
                scanf("%d",&etatArv);
                appartient=verifEtat(nbEtat,etatArv);
                    if (!appartient)
                    {
                        printf("Cet etat n'existe pas dans la table des etats!\n");
                    }
            }
            //getchar();
            aff_AdrG(inst,NULL);
            aff_Etat1G(inst,etatDep);
            aff_Etat2G(inst,etatArv);
            aff_MotG(inst,mot.a);
            exist=verifG(*listInst, inst);
            if (!exist)
            {
                if(i==0)
                {
                        (*listInst)=inst;
                        aff_AdrG(*listInst, NULL);
                }
                else
                    {
                        aff_AdrG(k,inst);
                    }
                //printf("Inseree\n");
            }
            else {
                printf("Instruction deja existante\n");
            }
        }
    }
}

int verifG(InstructionG* liste, InstructionG* inst)
{
    InstructionG* p=liste;
    int trouv=0;
    while((p!=NULL) && (!trouv))
    {
        printf("%d %s %d \n",valEtat1G(p),valMotG(p),valEtat2G(p));
        if (valEtat1G(p)==valEtat1G(inst))
        {
            if(valMotG(p)==valMotG(inst))
            {
                //printf("Même lettre\n");
                if (valEtat2G(p)==valEtat2G(inst))
                {
                    trouv=1;
                }
            }
        }
        p=SuivantG(p);
    }
    printf("VerifG\n");
    return trouv;
}

int verifMot(String* Alpha, int taille, String mot )
{
    int i=0;
    int trouv=0;
    while((!trouv) && (i<taille))
    {
        if (strcmp(Alpha[i].a,mot.a)==0)
        {
            trouv=1;
        }
        else i++;
    }
    return trouv;
}

int verifEtat(int nbEtat, int etat)
{
    int trouv=0;
    if ((etat>=0) && (etat<nbEtat))
    {
    trouv=1;
    }
    return trouv;
}

void isFinal(int *tab, int n,int *nbFinal)
{
    int i=0;
    int j=0;
    char rep;
    *nbFinal=0;
    for(i=0;i<n;i++)
    {
            getchar();
            printf("Est-ce que l'etat S%d est final? (o/n)",i);
            scanf("%c",&rep);
            //printf("rep=%c\n",tolower(rep));
            if(tolower(rep)=='o')
            {

                tab[j]=i;
                j++;
            }
    }
    *nbFinal=j;
}

/*
En entrée, elle prend un automate généralisé et en sortie,
elle renvoie un automate semi-généralisé.
*/
int SemiG(AutomateG AG, Automate *ASG)
{
    InstructionG *p=(AG.InstructionsG);
    Instruction  *q=NULL;
    Instruction *k=NULL;
    char chaine[3]="";
    //char c[2]="";
    //int nbEtat=AG->EtatG;
    int i=0;
    for(i=0;i<AG.nbFinal;i++)
    {
        ASG->EtatFin[i]=AG.EtatFinG[i];
    }
    ASG->nbFinal=AG.nbFinal;
    ASG->Etats=AG.EtatG;
    ASG->nbInst=0;
    sprintf(ASG->Alphabet,"%s","");
    while(p!=NULL)
    {

        for(i=0;i<strlen(valMotG(p));i++)
        {

            sprintf(chaine, "%s","");
            k=q;
            allouer(&q);
            aff_Adr(q,NULL);
            if (i==0)
            {
                aff_Etat1(q, valEtat1G(p));
                aff_Lettre(q, (valMotG(p))[i]);

                aff_Etat2(q, ASG->Etats);
                (ASG->Etats)++;

            }
            else
            {
                aff_Etat1(q, valEtat2(k));
                aff_Lettre(q, (valMotG(p))[i]);
                aff_Etat2(q,ASG->Etats);
                (ASG->Etats)++;

            }
            if (!(verifLettre((ASG->Alphabet),strlen(ASG->Alphabet),(valMotG(p))[i])))
            {

                sprintf(chaine, "%c",(valMotG(p))[i]);
                strcat(ASG->Alphabet, chaine);
                //(ASG->Alphabet)[strlen(ASG->Alphabet)]=(valMotG(p))[i];
                //(ASG->Alphabet)[strlen(ASG->Alphabet)]='\0';
            }
            if(ASG->nbInst==0) ASG->Instructions=q;
            else
            {
                aff_Adr(k,q);
            }
            (ASG->nbInst)++;
        }
        aff_Etat2(q,valEtat2G(p));
        (ASG->Etats)--;
        p=SuivantG(p);
    }
    return 1;
}

int verifLettre(char *Tab, int taille, char lettre)
{
    int i=0;
    int trouv=0;
    while((!trouv) && (i<taille))
    {
        if (Tab[i]==lettre)
        {
            trouv=1;
        }
		else i++;
	}
	return trouv;
}

int Simple(Automate *autoS)
{
	int i=0,j=0,trouv=0;
    Instruction *p=NULL,*q=NULL;
    Instruction *parc=NULL,*k=NULL;
    p=autoS->Instructions;

    while(p!=NULL)
	{
		k=p;
		if(valLettre(p)=='&')
		{
			//printf("trans spontanee S%d %c S%d\n",valEtat1(p),valLettre(p),valEtat2(p));
			trouv = verifFinal(autoS->EtatFin,autoS->nbFinal,valEtat2(p));
			if(trouv)
			{
				trouv=verifFinal(autoS->EtatFin,autoS->nbFinal,valEtat1(p));
				if(!trouv)
				{
					autoS->EtatFin[autoS->nbFinal]= valEtat1(p);
					(autoS->nbFinal)++;
				}
			}
			parc=autoS->Instructions;
			while(parc!=NULL)
			{
				//printf("parcour\n");
				if(valEtat1(parc)==valEtat2(p))
				{
					allouer(&q);
					aff_Etat1(q,valEtat1(p));
					aff_Etat2(q,valEtat2(parc));
					aff_Lettre(q,valLettre(parc));
					aff_Adr(q,NULL);
					ajouterInst(autoS->Instructions,q);
					//printf("ajoute S%d %c S%d\n",valEtat1(q),valLettre(q),valEtat2(q));
				}
				parc=Suivant(parc);
			}

			p=Suivant(p);
			(autoS->Instructions)=supprimerInst((autoS->Instructions),&k);
			//printf("sortir\n");
		}
		else
		{
			p=Suivant(p);
		}
	}
	//Mise a jour de l'alphabet
	while(autoS->Alphabet[i]!='&') i++;
	j=i;
	while(j<(strlen(autoS->Alphabet)-1))
	{
		autoS->Alphabet[j]=autoS->Alphabet[j+1];
		j++;
	}
	autoS->Alphabet[j]='\0';
	//printf("Alphabet=%s\n",autoS->Alphabet);
	/*printf("Les etats finaux\n");
	for(i=0;i<autoS->nbFinal;i++) printf("S%d\n",autoS->EtatFin[i]);
	*/

	return 1;
}

void ajouterInst(Instruction *tete, Instruction *p)
{
	Instruction *k=NULL;
	Instruction *f=tete;
	while(f!=NULL)
	{
		k=f;
		f=Suivant(f);
	}
	aff_Adr(k,p);
	aff_Adr(p,NULL);
}

Instruction* supprimerInst(Instruction *tete, Instruction** p)
{
	Instruction *k=tete;
	Instruction *q=NULL;
	//int trouv=0;
	rechInst(tete,&q,*p);

	while((k!=(*p)) && (k!=NULL))
	{
		q=k;
		k=Suivant(k);
	}
	if (k!=NULL)
	{
		if((*p)==(tete))
		{
			(tete)=Suivant(tete);
			liberer(p);
		}
		else
		{
			aff_Adr(q,Suivant(*p));
			liberer(p);
		}
	}
	return tete;
}

void rechInst(Instruction* tete, Instruction** pre, Instruction* p)
{
	*pre=NULL;
	while((tete!=NULL) && (tete!=p))
	{
		*pre=tete;
		tete=Suivant(tete);
	}
}

int verifFinal(int *Tab, int taille, int etat)
{
    int i=0;
    int trouv=0;
    while((!trouv) && (i<taille))
    {
        if (Tab[i]==etat)
        {
            trouv=1;
        }
		else i++;
	}
	return trouv;
}
