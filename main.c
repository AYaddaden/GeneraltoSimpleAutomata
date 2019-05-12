#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "machine/machine.h"
//include "./machineInstG/machineInstG.h"





int main()
{
    InstructionG *p=NULL;
    Instruction  *q=NULL;
    int i=0;

    AutomateG* autoG=malloc(sizeof(AutomateG));
    Automate* autoSG=malloc(sizeof(Automate));

    int choix=0,stop=0;
    int cree=0;
    int sem=0;
    int sim=0;

    char EnsAlphabetG[max]="X*={";
    char EnsAlphabetSG[max]="Xsg={";
    char EnsAlphabetS[max]="Xs={";


    char EnsEtatG[max]="Sg={";
    char EnsEtatSG[max]="Ssg={";
    char EnsEtatS[max]="Ss={";

    char EnsFinalG[max]="Fg={";
    char EnsFinalSG[max]="Fsg={";
    char EnsFinalS[max]="Fs={";

    char EnsInstG[5*max]="IIg={";
    char EnsInstSG[5*max]="IIsg={";
    char EnsInstS[5*max]="IIs={";
    char chaine[max]="";

    FILE* f=NULL;
    f=fopen("trace.txt","a+");
    do
    {
        menu();
		choix=0;
		printf("\tVotre choix: ");
		scanf( " %d", &choix );
        printf( "\n" );

         switch(choix)
         {
            case 1:
                printf("Creation de l'automate generalise:\n");
                cree=ConstAG(autoG);
                sim=0;
                sem=0;
                //Inscriptions des donnees sur fichier
                sprintf(EnsAlphabetG,"%s","X*={");
                for(i=0;i<autoG->nbMot;i++)
                {
                   // printf("Alpha i %c\n",Alpha[i]);
                    strcat(EnsAlphabetG,autoG->AlphabetG[i].a);
                    //printf("%s\n",EnsAlphabet);
                   if(i!=(autoG->nbMot)-1) strcat(EnsAlphabetG, "; ");
                }
                strcat(EnsAlphabetG, "}");
                fputs("\nLes donnees de l'automate sont:\n\tL'alphabet: ",f);
                fputs(EnsAlphabetG,f);
                fputs("\n",f);
                sprintf(EnsEtatG,"%s","Sg={");
                for(i=0;i<autoG->EtatG;i++)
                {
                   // printf("Alpha i %c\n",Alpha[i]);
                    strcat(EnsEtatG,"S");
                    sprintf(chaine,"%d",i);
                    strcat(EnsEtatG,chaine);
                    sprintf(chaine,"%s","");
                    //printf("%s\n",EnsAlphabet);
                   if(i!=(autoG->EtatG)-1) strcat(EnsEtatG, "; ");
                }
                strcat(EnsEtatG, "}");
                fputs("\tL'ensemble des etats est: ",f);
                fputs(EnsEtatG,f);
                fputs("\n",f);
                sprintf(chaine,"%s","");
                sprintf(EnsFinalG,"%s","Fg={");
                for(i=0;i<autoG->nbFinal;i++)
                {
                   // printf("Alpha i %c\n",Alpha[i]);
                    strcat(EnsFinalG,"S");
                    sprintf(chaine,"%d",autoG->EtatFinG[i]);
                    strcat(EnsFinalG,chaine);
                    sprintf(chaine,"%s","");
                    //printf("%s\n",EnsAlphabet);
                   if(i!=(autoG->nbFinal)-1) strcat(EnsFinalG, "; ");
                }
                strcat(EnsFinalG, "}");
                fputs("\tL'ensemble des etats finaux est: ",f);
                fputs(EnsFinalG,f);
                fputs("\n",f);

                sprintf(chaine,"%s","");
                sprintf(EnsInstG,"%s","IIg={");
                p=autoG->InstructionsG;
                while(p!=NULL)
                {
                   // printf("Alpha i %c\n",Alpha[i]);
                    strcat(EnsInstG,"(S");
                    sprintf(chaine,"%d",valEtat1G(p));
                    strcat(EnsInstG,chaine);
                    strcat(EnsInstG,", ");
                    sprintf(chaine,"%s","");
                    sprintf(chaine,"%s",valMotG(p));
                    strcat(EnsInstG,chaine);
                    strcat(EnsInstG,", ");
                    strcat(EnsInstG,"S");
                    sprintf(chaine,"%s","");
                    sprintf(chaine,"%d",valEtat2G(p));
                    strcat(EnsInstG,chaine);
                    strcat(EnsInstG,")");
                    sprintf(chaine,"%s","");
                    p=SuivantG(p);
                    //printf("%s\n",EnsAlphabet);
                   if(p!=NULL) strcat(EnsInstG, "; ");
                }
                //printf("ok\n");
                //strncat(EnsAlphabet, &Alpha[strlen(Alpha)-1],1);
                strcat(EnsInstG, "}");
                //printf("%s\n",EnsInst);
                fputs("\tL'ensemble des instructions est: ",f);
                fputs(EnsInstG,f);
                fputs("\n",f);

                if (cree) printf("L'automate a ete cree avec succes!\n");
                break;
            case 2:
                printf("Afficher l'automate generalise:\n");
                if (cree)
                {
                    printf("%s\n",EnsAlphabetG);
                    printf("%s\n",EnsEtatG);
                    printf("%s\n",EnsFinalG);
                    printf("%s\n",EnsInstG);
                }
                else printf("Vous devez d'abord creer un automate generalise!!\n");

                break;
            case 3:
                printf("Creation de l'automate semi-generalise:\n");
                if(cree)
				{
					sem=SemiG(*autoG, autoSG);
					//sim=0;
					sprintf(EnsAlphabetSG,"%s","Xsg={");
					for(i=0;i<strlen(autoSG->Alphabet);i++)
					{
					   // printf("Alpha i %c\n",Alpha[i]);
										  // strncat(EnsAlphabet,&Alpha[i],1);

						strncat(EnsAlphabetSG,&(autoSG->Alphabet[i]),1);
						//printf("%s\n",EnsAlphabet);
					   if(i!=strlen(autoSG->Alphabet)-1) strcat(EnsAlphabetSG, "; ");
					}
					strcat(EnsAlphabetSG, "}");
					fputs("\nLes donnees de l'automate semi-generalise sont:\n\tL'alphabet: ",f);
					fputs(EnsAlphabetSG,f);
					fputs("\n",f);
					sprintf(EnsEtatSG,"%s","Ssg={");
					for(i=0;i<autoSG->Etats;i++)
					{
					   // printf("Alpha i %c\n",Alpha[i]);
						strcat(EnsEtatSG,"S");
						sprintf(chaine,"%d",i);
						strcat(EnsEtatSG,chaine);
						sprintf(chaine,"%s","");
						//printf("%s\n",EnsAlphabet);
					   if(i!=(autoSG->Etats)-1) strcat(EnsEtatSG, "; ");
					}
					strcat(EnsEtatSG, "}");
					fputs("\tL'ensemble des etats est: ",f);
					fputs(EnsEtatSG,f);
					fputs("\n",f);
					sprintf(chaine,"%s","");
					sprintf(EnsFinalSG,"%s","Fsg={");
					for(i=0;i<autoSG->nbFinal;i++)
					{
					   // printf("Alpha i %c\n",Alpha[i]);
						strcat(EnsFinalSG,"S");
						sprintf(chaine,"%d",autoSG->EtatFin[i]);
						strcat(EnsFinalSG,chaine);
						sprintf(chaine,"%s","");
						//printf("%s\n",EnsAlphabet);
					   if(i!=(autoSG->nbFinal)-1) strcat(EnsFinalSG, "; ");
					}
					strcat(EnsFinalSG, "}");
					fputs("\tL'ensemble des etats finaux est: ",f);
					fputs(EnsFinalSG,f);
					fputs("\n",f);

					sprintf(chaine,"%s","");
					sprintf(EnsInstSG,"%s","IIsg={");
					q=autoSG->Instructions;
					while(q!=NULL)
					{
					   // printf("Alpha i %c\n",Alpha[i]);
						strcat(EnsInstSG,"(S");
						sprintf(chaine,"%d",valEtat1(q));
						strcat(EnsInstSG,chaine);
						strcat(EnsInstSG,", ");
						sprintf(chaine,"%s","");
						sprintf(chaine,"%c",valLettre(q));
						strcat(EnsInstSG,chaine);
						strcat(EnsInstSG,", ");
						strcat(EnsInstSG,"S");
						sprintf(chaine,"%s","");
						sprintf(chaine,"%d",valEtat2(q));
						strcat(EnsInstSG,chaine);
						strcat(EnsInstSG,")");
						sprintf(chaine,"%s","");
						q=Suivant(q);
						//printf("%s\n",EnsAlphabet);
					   if(q!=NULL) strcat(EnsInstSG, "; ");
					}
					//printf("ok\n");
					//strncat(EnsAlphabet, &Alpha[strlen(Alpha)-1],1);
					strcat(EnsInstSG, "}");
					//printf("%s\n",EnsInst);
					fputs("\tL'ensemble des instructions est: ",f);
					fputs(EnsInstSG,f);
					fputs("\n",f);
					printf("L'automate semi-generalise a bien ete construit!\n");
                }
                else printf("Vous devez d'abord creer un automate generalise!!\n");
                break;
            case 4:
                printf("Afficher l'automate semi-generalise:\n");
                if (cree)
                {
                	if(sem)
					{
						printf("%s\n",EnsAlphabetSG);
						printf("%s\n",EnsEtatSG);
						printf("%s\n",EnsFinalSG);
						printf("%s\n",EnsInstSG);
                    }
                    else printf("Vous devez d'abord creer un automate semi-generalise!!\n");
                }
                else printf("Vous devez d'abord creer un automate generalise!!\n");
                 break;
            case 5:
                 printf("Creation de l'automate simple:\n");
                 if (cree)
                {
                	if(sem)
					{
						sim=Simple(autoSG);
						sprintf(EnsAlphabetS,"%s","Xs={");
						for(i=0;i<strlen(autoSG->Alphabet);i++)
						{
						   // printf("Alpha i %c\n",Alpha[i]);
											  // strncat(EnsAlphabet,&Alpha[i],1);

							strncat(EnsAlphabetS,&(autoSG->Alphabet[i]),1);
							//printf("%s\n",EnsAlphabet);
						   if(i!=strlen(autoSG->Alphabet)-1) strcat(EnsAlphabetS, "; ");
						}
						strcat(EnsAlphabetS, "}");
						fputs("\nLes donnees de l'automate simple sont:\n\tL'alphabet: ",f);
						fputs(EnsAlphabetS,f);
						fputs("\n",f);
						sprintf(EnsEtatSG,"%s","Ss={");
						for(i=0;i<autoSG->Etats;i++)
						{
						   // printf("Alpha i %c\n",Alpha[i]);
							strcat(EnsEtatS,"S");
							sprintf(chaine,"%d",i);
							strcat(EnsEtatS,chaine);
							sprintf(chaine,"%s","");
							//printf("%s\n",EnsAlphabet);
						   if(i!=(autoSG->Etats)-1) strcat(EnsEtatS, "; ");
						}
						strcat(EnsEtatS, "}");
						fputs("\tL'ensemble des etats est: ",f);
						fputs(EnsEtatS,f);
						fputs("\n",f);
						sprintf(chaine,"%s","");
						sprintf(EnsFinalS,"%s","Fs={");
						for(i=0;i<autoSG->nbFinal;i++)
						{
						   // printf("Alpha i %c\n",Alpha[i]);
							strcat(EnsFinalS,"S");
							sprintf(chaine,"%d",autoSG->EtatFin[i]);
							strcat(EnsFinalS,chaine);
							sprintf(chaine,"%s","");
							//printf("%s\n",EnsAlphabet);
						   if(i!=(autoSG->nbFinal)-1) strcat(EnsFinalS, "; ");
						}
						strcat(EnsFinalS, "}");
						fputs("\tL'ensemble des etats finaux est: ",f);
						fputs(EnsFinalS,f);
						fputs("\n",f);
						sprintf(chaine,"%s","");
						sprintf(EnsInstS,"%s","IIs={");
						q=autoSG->Instructions;
						while(q!=NULL)
						{
						   // printf("Alpha i %c\n",Alpha[i]);
							strcat(EnsInstS,"(S");
							sprintf(chaine,"%d",valEtat1(q));
							strcat(EnsInstS,chaine);
							strcat(EnsInstS,", ");
							sprintf(chaine,"%s","");
							sprintf(chaine,"%c",valLettre(q));
							strcat(EnsInstS,chaine);
							strcat(EnsInstS,", ");
							strcat(EnsInstS,"S");
							sprintf(chaine,"%s","");
							sprintf(chaine,"%d",valEtat2(q));
							strcat(EnsInstS,chaine);
							strcat(EnsInstS,")");
							sprintf(chaine,"%s","");
							q=Suivant(q);
							//printf("%s\n",EnsAlphabet);
						   if(q!=NULL) strcat(EnsInstS, "; ");
						}
						//printf("ok\n");
						//strncat(EnsAlphabet, &Alpha[strlen(Alpha)-1],1);
						strcat(EnsInstS, "}");
						//printf("%s\n",EnsInst);
						fputs("\tL'ensemble des instructions est: ",f);
						fputs(EnsInstS,f);
						fputs("\n",f);


						printf("L'automate simple a bien ete construit!\n");
					}
					else printf("Vous devez d'abord creer un automate semi-generalise!!\n");
                }
                else printf("Vous devez d'abord creer un automate generalise!!\n");
					/* q=autoSG->Instructions;
					 while(q!=NULL)
					 {
						printf("S%d %c S%d\n",valEtat1(q),valLettre(q),valEtat2(q));
						q=Suivant(q);
					 }*/

                 break;
            case 6:
                 printf("Afficher l'automate simple:\n");
                 if (cree)
                {
                	if(sem)
					{
						if (sim)
						{
							printf("%s\n",EnsAlphabetS);
							printf("%s\n",EnsEtatS);
							printf("%s\n",EnsFinalS);
							printf("%s\n",EnsInstS);
						}
						else printf("Vous devez d'abord creer un automate simple!!\n");

                    }
                    else printf("Vous devez d'abord creer un automate semi-generalise!!\n");
                }
                else printf("Vous devez d'abord creer un automate generalise!!\n");

                 break;
			default:
				printf("\nFin\n");
				stop=1;
				break;

         }
		if (cree && stop) fputs("\n*****************************************************************************************************\n",f);
        if((0<choix) && (choix<=6))
        {
            printf("\n\nAppuyez sur ENTREE pour continuer...");
            getchar();
            getchar();
        }
    }while(!stop);


    fclose(f);
    return 0;
}
