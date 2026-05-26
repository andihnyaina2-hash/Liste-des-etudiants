#include <stdio.h>
#include <stdlib.h>
	struct etudiant //information concernant l'eleve
	{
		char nom[100];
	       	char prenom[100];
		char naissance[100];
		char adresse[100];
	};
void etudiant(struct etudiant *L);
void stockprint(FILE *f,struct etudiant *l);	
void etudiant(struct etudiant *L)
{ 
	//insertion de l'identite del'etudiant
	printf("Veuillez saisir votre identite \n");
	printf("========================================================================================================\n");
	printf("NOM : ");
	scanf(" %[^\n]",L->nom);
	printf("PRENOM : ");
	scanf(" %[^\n]",L->prenom);
	printf("DATE DE NAISSANCE : ");
	scanf(" %[^\n]",L->naissance);
	printf("ADRESSE : ");
	scanf(" %[^\n]",L->adresse);
	printf("----------------------------\nStudent : %s enregistre \n",L->nom);
}

char stockprint(FILE *f,struct etudiant *L) //ecriture en fichier
{
	char n[3];
	printf("Entrez votre niveau : ");
	scanf("%s",n);
	printf("\n");
	if(n[0]='L' && n[1]=='1')
	{
		f=fopen("L1.txt","a+");
		if(f==NULL)
		{
			printf("Impossible de creer votre fichier \n");
			exit(1);
		}
		fprintf(f," %s               %s                %s      %s \n",L->nom,L->prenom,L->naissance,L->adresse);
		fclose(f);
	}
	else if(n[0]=='L' && n[1]=='2')
	{
		f=fopen("L2.txt","a+");
                if(f==NULL)
                {
                        printf("Impossible de creer votre fichier \n");
                        exit(1);
                }
		fprintf(f," %s               %s                %s      %s \n",L->nom,L->prenom,L->naissance,L->adresse);
                fclose(f);
	}
	 else if(n[0]=='L' && n[1]=='3')
        {
                f=fopen("L3.txt","a+");
                if(f==NULL)
                {
                        printf("Impossible de creer votre fichier \n");
                        exit(1);
                }
		fprintf(f," %s               %s                %s      %s \n",L->nom,L->prenom,L->naissance,L->adresse);
                fclose(f);
	}
	else
	{
		printf("The Helly\n");
		exit(1);
	}
	return(n);
}

int main()
{	FILE *f;
	struct etudiant L;
	char n[3];
	etudiant(&L);
	n=stockprint(f,&L);
	return(0);
}	

