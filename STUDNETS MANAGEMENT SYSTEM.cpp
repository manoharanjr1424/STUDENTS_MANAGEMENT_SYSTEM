#include<stdio.h>  
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#pragma pack(1)
#define databasesize 1000
#define namemax 50
#define deptmax 50 

void newdata();
void showdata();
void deletedata();
void searchdata();
void gotoxy(int,int);
void border();
void loading();
void choice_page();
void delay(long);
void instruction();
void border_for_loading();
void database_();
void border_for_choice();
void search_name();
void search_regno();

struct database
{
	char name[namemax];
	char dept[deptmax];
	int rollno;
	long int regno;
}data[databasesize];

struct coordinate
{
    int x;
    int y;
    int direction;
};

int i=0,datanumber=0;
long cur=0;
int main()  
{
	while(1)
	{
	instruction();
	system("cls");
	loading();
	choice_page();
}
}  
void choice_page()
{
	unsigned int choice;
	system("cls");
	gotoxy(50,5);
	printf("ENTER THE OPTION");
	gotoxy(50,6);
		for(i=0;i<strlen("ENTER THE OPTION");i++)
	{
		printf("-");
	}
	gotoxy(15,8);
	printf("Press -> [1] Create New Data of the Student");
	gotoxy(15,9);
	printf("Press -> [2] Search Data of the Students");
	gotoxy(64,8);
	printf("Press -> [3] Delete Data of the Student");
	gotoxy(65,9);
	printf("\bPRESS -> [4] Open The Database");
	gotoxy(40,10);
	printf("Your Choice is =>");
	gotoxy(58,10);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			newdata();
			choice_page();
			break;
		case 2:
			searchdata();
			break;
		case 3:
			deletedata();
			break;
		case 4:
			showdata();
			break;
		default:
		 	system("cls");
			gotoxy(40,4);
			printf("Please wait your choice was processing");
			gotoxy(40,5);
			for(i=0;i<strlen("Please wait your choice was processing");i++)
			printf("-");
			loading();
			delay(0);
			system("cls");
			gotoxy(40,6);
			printf("THERE IS NO CHOICE LIKE YOU ENTERED ON THE DATA BASE");
			gotoxy(43,7);
			printf("*WARNING  : ENTER THE VLAID CHOICE");
			delay(150000000);
			system("cls");
		
	}
}
void newdata()
{
	fflush(stdin);
	system("cls");
	gotoxy(48,1);
	printf("WELCOME TO STUDENTS MANAGEMENT");
	////////////////////////////////////////////////
	gotoxy(50,2);
	printf("NAME OF THE STUDENT :");
	gotoxy(72,2);
	scanf("%[^\n]",data[datanumber].name);
	//////////////////////////////////////////////////
	gotoxy(50,4);
	printf("ROLL NO OF THE STUDENT :");
	gotoxy(74,4);
	scanf("%d",&data[datanumber].rollno);
	//////////////////////////////////////////////////// 
	fflush(stdin);
	gotoxy(50,6);
	printf("DEPARTMENT OF THE STUDENT :");
	scanf("%[^\n]",data[datanumber].dept);
	gotoxy(73,6);
	//////////////////////////////////////////////////////
	gotoxy(50,8);
	printf("REGNO OF THE STUDENT :");
	gotoxy(72,8);
	scanf("%ld",&data[datanumber].regno);

	gotoxy(40,12);
	printf("*ENTRED DATA WAS CORRECT PRESS => [y] (Yes Save)");
	gotoxy(40,14);
	printf("*ENTRED DATA WAS WRONG PRESS => [n] (Yes Save)");
	if(getch()=='y'||getch()=='Y')
	{
		database_();
		datanumber++;
	}
	else if(getch()=='n')
	{
	  newdata();
	}
	return;
}

void searchdata()
{
	int choice;
	gotoxy(40,1);
	printf("ENTER THE SEARCH METHOD");
	gotoxy(40,2);
	printf("PRESS [1] SEARCH BY NAME\n PRESS [2] SEARCH BY REGNO\n");
	gotoxy(40,7);
	printf("Your Choice is =>");
	gotoxy(58,10);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    search_name();
			break;
		case 2:
			search_regno();
			break;
		default:
		 	system("cls");
			gotoxy(40,4);
			printf("Please wait your choice was processing");
			gotoxy(40,5);
			for(i=0;i<strlen("Please wait your choice was processing");i++)
			printf("-");
			loading();
			delay(0);
			system("cls");
			gotoxy(40,6);
			printf("THERE IS NO CHOICE LIKE YOU ENTERED ON THE DATA BASE");
			gotoxy(43,7);
			printf("*WARNING  : ENTER THE VLAID CHOICE");
			delay(150000000);
			system("cls");
		
	}
}

void deletedata()
{

}
 void showdata()
{

}
void search_name()
{

}
void search_regno()
{
	
}
void border()
{
	unsigned int  i;
	for(i=25;i<50;i++)
	{
		gotoxy(i,1);
		printf("=");
		gotoxy(i,5);
		printf("=");
	}
	for(i=1;i<6;i++)
	{
		gotoxy(25,i);
		printf("|");
		gotoxy(50,i);
		printf("|");
	}
}
void border_for_loading()
{
		unsigned int  i;
	for(i=50;i<70;i++)
	{
		gotoxy(i,10);
		printf("=");
		gotoxy(i,15);
		printf("=");
	}
	for(i=10;i<16;i++)
	{
		gotoxy(50,i);
		printf("V");
		gotoxy(70,i);
		printf("V");
	}
	
}
void loading()
{
	int i,j;
	border_for_loading();
	gotoxy(56,12);
	printf("Loading");
	gotoxy(53,14);
	for(i=0;i<12;i++)
	{
		printf(".");
		delay(0);
	}
}

void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void delay(long a)
{
	if(a==0)
	{
	for(i=0;i<100000000;i++);
	}
	else 
	{
	for(i=0;i<a;i++);
	}
	a=0;
}
void instruction()
{
	gotoxy(50,1);
	printf("CLASS MONITORING SYSYEM");
	gotoxy(50,2);
	for(int i=0;i<25;i++)
	{
		printf("-");
	}
	gotoxy(1,3);
	printf("* Afte loading page the section will show");
	gotoxy(1,4);
	printf("* IF your going to use this software Intialze");
	gotoxy(1,5);
	printf("After Read the Instrction Click the Enter");
	gotoxy(48,6);
	printf("* \bDEVELOPED BY\b");
	gotoxy(50,7);
	printf("* \bMANOHARAN\b");
	while(!getch());
}

void database_()
{
	system("cls");
	gotoxy(40,8);
	printf("DATA WAS STORED INTO THE THE DATA BASE\n");
	loading();
	system("cls");
	///////////////////////////////////
	gotoxy(48,10);
	printf("NAME :");
	gotoxy(55,10);
	printf("%s",data[datanumber].name);
	//////////////////////////////////////
	gotoxy(48,11);
	printf("REGNO :");
	gotoxy(55,11);
	printf("%ld",data[datanumber].regno);
	///////////////////////////////////////
	gotoxy(48,12);
	printf("DEPT :");
	gotoxy(55,12);
	printf("%s",data[datanumber].dept);
	////////////////////////////////////////
	gotoxy(48,13);
	printf("ROLLNO :");
	gotoxy(56,13);
	printf("%d",data[datanumber].rollno);
	FILE *filename;
	filename=fopen("database_of_students_list.txt","a");
	fprintf(filename,"Name= %s \n DEPT = %s \n ROLL NO= %d \n REG NO= %ld \n",data[datanumber].name,data[datanumber].dept,data[datanumber].rollno,data[datanumber].regno);
	fprintf(filename,"\n");
	fclose(filename);
	
	gotoxy(40,7);
	printf("DATA STORED ON DATABSE SUCESSFULLY");
	gotoxy(46,16);
	printf("Press Esc to Exit");
	while(!(getch()==27));
	fflush(stdin);
}
