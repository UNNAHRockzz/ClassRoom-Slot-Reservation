#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char room[10][130]={"A101","A102","A103","A104","A105","A106","A107","A108"};
char time[20][20]={"09:00","10:00","11:10","12:10","13:10","13:50","14:50","15:50"};
char bookarr[1000][1000]={'\0'};
char facname[40];
int rno,ts;
struct login                  
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};
void login ();
void registration ();

struct book
{
	char bookarr[1000];
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void login (void)
{
    char user[30],pswd[20];
    FILE *log;

    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    struct login l;

    printf("\nPlease Enter your login details below\n\n");
    printf("Username:  ");
    gets(user);//, 30, stdin);
    printf("\nPassword: ");
    printf("\n");
    gets(pswd);//, 20, stdin);

    while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(user,l.username)==0 && strcmp(pswd,l.password)==0)

            {   
                printf("\n Login Successful\n");
                getch();
            }
        else 
            {
                printf("\nIncorrect Login Details \n Please enter the correct details\nPress any key to continue\n");
                getch();
                system("cls");
                login();
            }
        }

    fclose(log);

    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void registration(void)
{
    char firstname[15];
    FILE *log;

    log=fopen("login.txt","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }


    struct login l;

    printf("\nWelcome\nPlease enter the details for registration.\n\n");
    printf("\nEnter First Name:\n");
    scanf("%s",l.fname);
    printf("\nEnter Surname:\n");
    scanf("%s",l.lname);

    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\n"); 

    printf("\nEnter Username:\n");
    scanf("%s",l.username);
    printf("\nEnter Password:\n");
    scanf("%s",l.password);


    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",l.fname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
        getchar();
        getch();
    system("CLS");
    login();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void roomdisp()
{
	char c;
    system("cls");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\tClassRoom Slot Reservation");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  ROOM & TIME LIST  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n\n");
    printf("   [1]  =>  %s\t\t\t[1]  =>  %s\n\n",room[0],time[0]);
    printf("   [2]  =>  %s\t\t\t[2]  =>  %s\n\n",room[1],time[1]);
	printf("   [3]  =>  %s\t\t\t[3]  =>  %s\n\n",room[2],time[2]);
	printf("   [4]  =>  %s\t\t\t[4]  =>  %s\n\n",room[3],time[3]);
	printf("   [5]  =>  %s\t\t\t[5]  =>  %s\n\n",room[4],time[4]);
	printf("   [6]  =>  %s\t\t\t[6]  =>  %s\n\n",room[5],time[5]);
	printf("   [7]  =>  %s\t\t\t[7]  =>  %s\n\n",room[6],time[6]);
	printf("   [8]  =>  %s\t\t\t[8]  =>  %s\n\n",room[7],time[7]);
	getch();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void booking()
{
int i,j;
struct book b;
char facfname[30],faclname[30];
FILE *fp;
fp=fopen("roombook.txt","w");
char numstr[100];
system("cls");
printf("\n\n\t\t\t\t\t****************************************\n");
printf("\t    ClassRoom Slot Reservation");
printf("\n\n\t\t\t\t\t****************************************\n");
roomdisp();
printf("   ENTER THE ROOM NUMBER: ");
scanf("%d",&rno);
printf(" ENTER THE TIME SLOT");
scanf("%d",&ts);
if(ts==5)
{
system("cls");
printf("\t\t!!\tLUNCH TIME\t!!\n!!\tCANT BOOK ANY ROOM FOR THIS TIME SLOT\t!!");
}
/**else if(bookarr[ts-1]!=0)
{
	printf("The room is already booked by %s",bookarr[ts-1]);
}**/
else
{
	fflush(stdin);
	printf("Enter the Name of Faculty's name'\n");
	fgets(facname,30,stdin);
    strcpy((char *)bookarr[ts-1],facname);
    /**fgets(bookarr[rno-1][ts-1],1,stdin);
	printf("\n%s\n",bookarr[rno-1][ts-1]);**/
	fwrite(&b,sizeof(b),1,fp);
	fclose(fp);
	
}

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cancle()
{
	/**	struct book b;
	FILE *fp;
	fread(&b,sizeof(b),1,fp);**/
	system("cls");
	roomdisp();
	printf("Enter the Room no to be released");
	scanf("%d",&rno);
	printf("Enter the Time Slot");
	scanf("%d",&ts);	
	if(ts==5)
	{
		printf("NO Room can be booked or released during LUNCH Time");
	}
	else
	{
		bookarr[rno-1][ts-1]='\0';
		printf("Room no %s has been released for the  time slot of %s",room[rno-1],time[ts-1]);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void availablity()
{
	system("cls");
	roomdisp();
	printf("Enter the Room no to be Checked for");
	scanf("%d",&rno);
	printf("Enter the Time Slot for the check");
	scanf("%d",&ts);
	if(ts==5)
	{
		printf("ALL Rooms are vacant but can't be booked for this time slot");
	}
	else
	{
		if(bookarr[ts-1]=='\0')
		{
			printf("The room %s is Empty for the time slot %s",room[rno-1],time[ts-1]);		 	
		}
		else
		{
		    printf("The room %s is booked by %s for the time slot %s",room[rno-1],bookarr[ts-1],time[ts-1]);
	    }
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	int option;
	system("cls");
    printf("\n\n****************************************\n");
    printf("      CLASSROOM SLOT RESERVATION SYSTEM");
    printf("\n****************************************\n");
    printf("\n\n================= LOGIN FORM ================\n\n\n  ");
    printf("\tPress '1' to Register\n\n\n\tPress '2' to Login\n\n");
    scanf("%d",&option);
    getchar();   
    if(option == 1)
        {
            system("CLS");
            registration();
        }
    else if(option == 2)
        {
            system("CLS");
            login();
        }
    
    int num,i;
    do{
    system("cls");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t ClassRoom Slot Reservation");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  MAIN MENU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   [1] View Room List\n\n");
    printf("   [2] Book Room\n\n");
    printf("   [3] Cancel/Check Out Booking\n\n");
    printf("   [4] Room Availability\n\n");
    printf("   [5] Exit\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   ENTER YOUR CHOICE: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        roomdisp();
        getch();
        break;
    case 2:
        booking();
        getch();
        break;
    case 3:
        cancle();
        getch();
        break;
    case 4:
        availablity();
        getch();
        break;
    }
    }while(num != 5);
    system("CLS");
    printf("\n\n************************************************************\n");
    printf("THANK YOU FOR USING THIS CLASSROOM SLOT RESERVATION SYSTEM");
    printf("\n************************************************************\n");
    getch();
    return 0;
}

