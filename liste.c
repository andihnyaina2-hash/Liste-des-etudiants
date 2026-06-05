#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
	struct date 
	{
                int day;
                int month;
                int year;
    };

	struct etudiant 
	{
		char nom[100];
	       	char prenom[100];
		struct date age;
		char adresse[100];
	};

FILE *stockprint() 
{
	FILE *f;
	char n[3];
	printf("Entrez votre niveau : ");
	scanf("%2s",n);
	printf("\n");
	if(strcmp(n,"L1")==0)
	{
		f=fopen("L1.csv","r+");
	}
	else if(strcmp(n,"L2")==0)
	{
		f=fopen("L2.csv","r+");
	}
	 else if(strcmp(n,"L3")==0)
        {	
                f=fopen("L3.csv","r+");
	}
	else
	{
		printf("The Helly\n");
		exit(0);
	}

	if(f==NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		exit(0);
	}
	return(f);
}
void etudiant(struct etudiant *L)
{ 
	FILE *f;
	f=stockprint();
	//insertion de l'identite del'etudiant
	printf("Veuillez saisir votre identite \n");
	printf("========================================================================================================\n");
	printf("NOM : ");
	scanf(" %[^\n]",L->nom);
	printf("PRENOM : ");
	scanf(" %[^\n]",L->prenom);
	printf("DATE DE NAISSANCE EN VERSION NUMERIQUE \n");
	printf("Day :");
	scanf("%d",&L->age.day);
	printf("Months :");
	scanf("%d",&L->age.month);
	printf("Year :");
	scanf("%d",&L->age.year);
	printf("ADRESSE : ");
	scanf(" %[^\n]",L->adresse);
	printf("Vous etes enregistrer enregistre \n");
	fseek(f,0,SEEK_END);
	fprintf(f,"%s,%s,%d/%d/%d,%s\n",L->nom,
					L->prenom,
					L->age.day,
					L->age.month,
					L->age.year,
					L->adresse);
	fclose(f);
}
void recup(struct etudiant LT[],int *taille)
{
	FILE *f=stockprint();
	int n;
	int i=0;
	while(fscanf(f,"%99[^,],%99[^,],%d/%d/%d,%99[^\n]\n",LT[i].nom,
				LT[i].prenom,
				&LT[i].age.day,
				&LT[i].age.month,
				&LT[i].age.year,
				LT[i].adresse)==6)
	{
		i++;
	}
	(*taille)=i;
	fclose(f);
}

void print(struct etudiant LT[],int *taille)
{
	int i;
	for(i=0;i<(*taille);i++)
	{
		printf(" NOM:%s\n PRENOM:%s\n DATE DE NAISSANCE:%d/%d/%d\n ADRESSE:%s\n",LT[i].nom,
											LT[i].prenom,
											LT[i].age.day,
											LT[i].age.month,
											LT[i].age.year,
											LT[i].adresse);
		printf("\n");
	}
}

void tri(struct etudiant LT[],int *taille)
{	 
	int i,j;
	char n[5];
	struct etudiant list_tmp;

	printf("saisisez le mode de triage 'n','p','d','a' : ");
	scanf("%4s",n);
	if((strcmp(n,"n"))==0)
	{
		for(i=0;i<(*taille-1);i++)
		{
			for(j=i+1;j<(*taille);j++)

			{
				if((strcasecmp(LT[i].nom,LT[j].nom)) > 0)
		      		{
					list_tmp=LT[i];
					LT[i]=LT[j];
					LT[j]=list_tmp;
				}
			}
		}
	}
	else if((strcmp(n,"p"))==0)
        {
                for(i=0;i<(*taille-1);i++)
                {
                        for(j=i+1;j<(*taille);j++)
                        {
                                if((strcasecmp(LT[i].prenom,LT[j].prenom)) > 0)
                                {
                                        list_tmp=LT[i];
                                        LT[i]=LT[j];
                                        LT[j]=list_tmp;


                                }
                        }
                }
        }

	else if((strcmp(n,"d"))==0)
        {
                for(i=0;i<(*taille-1);i++)
                {
                        for(j=i+1;j<(*taille);j++)
                        {
                                if(LT[i].age.year < LT[j].age.year) 
                                {
                                        list_tmp=LT[i];
                                        LT[i]=LT[j];
                                        LT[j]=list_tmp;
                                }
				else if(LT[i].age.year == LT[j].age.year)
				{
					if(LT[i].age.month > LT[j].age.month)
					{
						list_tmp=LT[i];
						LT[i]=LT[j];
						LT[j]=list_tmp;
					}
					else if(LT[i].age.month == LT[j].age.month)
					{
						if(LT[i].age.day < LT[j].age.day)
						{
							list_tmp=LT[i];
							LT[i]=LT[j];
							LT[j]=list_tmp;
						}
					}
				}
                        }
                }
        }

	else if((strcmp(n,"a"))==0)
        {
                for(i=0;i<(*taille-1);i++)
                {
                        for(j=i+1;j<(*taille);j++)
                        {
                                if((strcasecmp(LT[i].adresse,LT[j].adresse)) > 0)
                                {
                                        list_tmp=LT[i];
                                        LT[i]=LT[j];
                                        LT[j]=list_tmp;
                                }
                        }
                }
        }
	else
	{
		 printf("invalid syntax:\n n pour nom \n p pour prenoms \n date pour date de naissance \n adresse pour adresse \n");
		 exit(0);
        }


	for(j=0;j<(*taille);j++)
        {
                printf("%s,%s,%d/%d/%d,%s\n",LT[j].nom,
				             LT[j].prenom,
				             LT[j].age.day,
					     LT[j].age.month,
					     LT[j].age.year,
				             LT[j].adresse);     		 
        }
}	

void search(struct etudiant *LT,int *taille)
{
	char n[10],seek[100];
	int i,donne_existe=0;
	printf("saisir le mode de recherche 'n','p','date','adresse': ");
	scanf("%9s",n);
	if((strcmp(n,"n"))==0)
	{
		printf("Entrer le nom que vous rechercher : ");
		scanf("%99s",seek);
		for(i=0;i<(*taille);i++)
		{
			if((strcasestr(LT[i].nom,seek))!=NULL)
			{
				donne_existe++;
				printf(" ligne :%d\n NOM:%s\n PRENOM:%s\n DATE DE NAISSANCE:%d/%d/%d\n ADRESSE:%s\n",i,LT[i].nom,
														     LT[i].prenom,
														     LT[i].age.day,
														     LT[i].age.month,
														     LT[i].age.year,
														     LT[i].adresse);
			}
		}
		if(donne_existe==0)
		{
			printf("aucun chaine trouve\n");
		}
		else
		{
			printf("%d trouve \n",donne_existe);
		}
	}
	else if((strcmp(n,"p"))==0)
	{
		printf("Entrer le(s) prenom(s) : ");
		scanf(" %99[^\n]",seek);
		for(i=0;i<(*taille);i++)
		{
			if((strcasestr(LT[i].prenom,seek))!=NULL)
			{
				donne_existe++;
				printf(" ligne :%d\n NOM:%s\n PRENOM:%s\n DATE DE NAISSANCE:%d/%d/%d\n ADRESSE:%s\n",i,LT[i].nom,
													       LT[i].prenom,
													       LT[i].age.day,
													       LT[i].age.month,
													       LT[i].age.year,
													       LT[i].adresse);
			}
		}
		if(donne_existe==0)
		{
			printf("aucune chaine trouve\n");
		}
		else
		{
			printf("%d trouve \n",donne_existe);
		}
	}
	else if((strcmp(n,"date"))==0)
	{
		char birthday[50][25];
		printf("Entrer la date de naissance de format jj/mm/yyyy : ");
		scanf(" %99[^\n]",seek);
		for(i=0;i<(*taille);i++)
		{
			sprintf(birthday[i],"%d/%d/%d",LT[i].age.day,
						       LT[i].age.month,
						       LT[i].age.year);
		}
		for(i=0;i<(*taille);i++)
		{
			if((strcasestr(birthday[i],seek))!=NULL)
				{
					donne_existe++;
					printf(" ligne :%d\n NOM:%s\n PRENOM:%s\n DATE DE NAISSANCE:%d/%d/%d\n ADRESSE:%s\n",i,LT[i].nom,
															LT[i].prenom,
															LT[i].age.day,
															LT[i].age.month,
															LT[i].age.year,
															LT[i].adresse);
				}
		}	
		if(donne_existe==0)
		{
			printf("aucun chaine trouve\n");
		}
		else
		{
			printf("%d trouve \n",donne_existe);
		}
	}
	else if((strcmp(n,"adresse"))==0)
	{
		printf("Entrer l'adresse: ");
                scanf(" %99[^\n]",seek);
		for(i=0;i<(*taille);i++)
		{
                	if((strcasestr(LT[i].adresse,seek))!=NULL)
				{
					donne_existe++;
					printf(" ligne :%d\n NOM:%s\n PRENOM:%s\n DATE DE NAISSANCE:%d/%d/%d\n ADRESSE:%s\n",i,LT[i].nom,
							                                                                       LT[i].prenom,
															       LT[i].age.day,
															       LT[i].age.month,
															       LT[i].age.year,
															       LT[i].adresse);
				}
		}
		if(donne_existe==0)
		{
			printf("aucun chaine trouve\n");
		}
		else
		{
			printf("%d trouve \n",donne_existe);
		}
        }
	else
	{
		printf("invalid syntax:\n n pour nom \n p pour prenoms \n date pour date de naissance \n adresse pour adresse \n");
	}	
}

void CMD(int argv , char **argc)
{
	struct etudiant L;
	struct etudiant T[100];
	int taille;
	char n[3];
	if(argv != 2)
	{
		printf("invalid syntax , check help\n");
		exit(0);
	}
	else
	{
		if(strcmp(argc[1],"a")==0)
		{
			etudiant(&L);
		}
		else if(strcmp(argc[1],"p")==0)
		{
			recup(T,&taille);
			print(T,&taille);
		}
		else if(strcmp(argc[1],"t")==0)
		{
			recup(T,&taille);
			print(T,&taille);
			tri(T,&taille);
		}
		else if(strcmp(argc[1],"s")==0)
		{
			recup(T,&taille);
			search(T,&taille);
		}
		else if(strcmp(argc[1],"help")==0)
		{
			printf(" a :ajouter un eleve\n p :afficher les elements du fichiers \n t : triage \n s : rechercher \n help : aide aux commandes\n");
		}
		else 
		{
			printf("invalid syntax , check help\n");
		}
	}
}

int main(int argv , char **argc)
{	
	CMD(argv,argc);
	return(0);
}	

