#include<stdio.h>

void saisir(char s[]) 
{
	printf("Saisir une chaine\n");
	scanf("%s", s);
}

int main() 
{
	char *s;
	// erreur classique : char *s;

    printf("Entrer votre prenom. ");
    saisir(s);
    printf("Bonjour %s!\n", s);
	
	return 0;
}
