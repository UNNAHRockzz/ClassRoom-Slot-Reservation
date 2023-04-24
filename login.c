#include<stdio.h>
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="admin";
    do
{
	system("cls");
    printf("\n\n****************************************\n");
    printf("      CLASSROOM SLOT RESERVATION SYSTEM");
    printf("\n****************************************\n");
    printf("\n\n================= LOGIN FORM ================  ");
    printf("\n\n ENTER USERNAME: ");
	scanf("%s", &uname);
	printf(" \nENTER PASSWORD: ");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
	{
    printf("\n\t\t\t\t\t****************************************\n");
	printf("  \n\n   WELCOME USER !!!!");
	printf("\n\n\n   Press any key to continue...");
	getch();
	break;
	}
	else
	{
    printf("\n\t\t\t\t\t****************************************\n");
		printf("\n\n   LOGIN IS UNSUCESSFUL...PLEASE TRY AGAIN...");
		a++;

		getch();

	}
}while(a<=2);

	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
