/* a simple student dormitory residence information system using hashing
	Date started: 2018/3/11
	Date finished: 2018/3/14
*/ 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>

#define TS 100

typedef struct node *nd;
struct node
{
	char StudID[10];
	char LName[20];
	char FName[20];
	char MidInit[3];
	char Address[50];
	char Course[10];
	char Father[20];
	char Mother[20];
	int status;
	nd next;
}NODE;

typedef struct
{
	nd next;
}HASHTABLE;

void addNew(HASHTABLE[]);
bool searchID(HASHTABLE[], char []);
void logs(HASHTABLE[]);
void track(HASHTABLE[]);
void searchByID(HASHTABLE[]);
void searchByLName(HASHTABLE[]);
void deleteValue(HASHTABLE[]); 
void viewAll(HASHTABLE[]);
int hash(char[]);
void createTable(HASHTABLE[]);

int main(void)
{
	int ch;
	HASHTABLE hashTab[TS];
	createTable(hashTab);
	
	do{
		system("cls");
		printf("1. Add new Dorm Resident\n");
		printf("2. Log Dorm Resident\n");
		printf("3. Track Dorm Resident\n");
		printf("4. Search Dorm Resident by student ID\n");
		printf("5. Search Dorm Resident by student LastName\n");
		printf("6. Delete Dorm Resident\n");
		printf("7. Display All Dorm Residents\n");
		printf("8. Exit\n");
		printf("Choice: ");
		scanf("%d", &ch);
		fflush(stdin);
		switch(ch)
		{
			case 1 :	addNew(hashTab);
						break;
			case 2 :	logs(hashTab);
						break;	
			case 3 :	track(hashTab);
						break;
			case 4 :	searchByID(hashTab);
						break;
			case 5 :	searchByLName(hashTab);
						break;
			case 6 :	deleteValue(hashTab);
						break;
			case 7 :	viewAll(hashTab);
						getch();
						break;
			case 8 :	printf("\n\n closing....");
						Sleep(500);
						break;
			default:	printf("\n\nInvalid choice");
						Sleep(500);							
		}
	}while(ch!=8);
	return 0;
}

int hash(char data[])
{
	int key = 0;
	key=data[0]+(27*data[1])+(27*27*data[2]);
	return key;
}

void createTable(HASHTABLE hashTab[])
{
	int i;
	for(i=0;i<TS;i++)
	{
		hashTab[i].next = NULL;
	}
	return;
}

void addNew(HASHTABLE hashTab[])
{
	char a[10];
	int key, p;
	bool sear;
	nd temp;
	temp = malloc(sizeof(NODE));
	printf("Input the student ID: ");
	gets(a);
	fflush(stdin);
	sear = searchID(hashTab, a);
	if(sear)
	{
		printf("WRONG! This ID is already exist\n");
		printf("Return to main menu\n");
		getch();
		return;
	}
	else
	{
		strcpy(temp->StudID, a);
		fflush(stdin);
		printf("\nInput the student's Last Name: ");
		gets(temp->LName);
		fflush(stdin);
		printf("Input the student's First Name: ");
		gets(temp->FName);
		fflush(stdin);
		printf("Input the student's Middle Initial: ");
		fflush(stdin);
		gets(temp->MidInit);
		fflush(stdin);
		printf("Input the student's Home Address: ");
		fflush(stdin);
		gets(temp->Address);
		fflush(stdin);
		printf("Input the student's Course: ");
		gets(temp->Course);
		fflush(stdin);
		printf("Input the student's Father Name: ");
		gets(temp->Father);
		fflush(stdin);
		printf("Input the student's Mother Name: ");
		gets(temp->Mother);
		fflush(stdin);
		temp->status = 1;//in is 1, out is 0
		
		key=hash(a);
		p=key%TS;
	
		temp -> next = NULL;
		temp -> next = hashTab[p].next;
		hashTab[p].next = temp;
		getch();
		return;
	}
	
}

bool searchID(HASHTABLE hashTab[], char searchVal[])
{
	int key, p;
	nd tp = NULL;
	key=hash(searchVal);
	p=key%TS;
	
	tp = hashTab[p].next;
	
	while(tp != NULL)
	{
		if(strcmp(tp -> StudID, searchVal) == 0)
		{
			return true;
		}
		tp = tp -> next;
	}
	return false;
}

void logs(HASHTABLE hashTab[])
{
	int b, c, key, p;
	char a[10];
	nd tp;
	nd tp1;
	bool sear;
	printf("\nInput the student ID you want to log: ");
	gets(a);
	fflush(stdin);
	sear = searchID(hashTab, a);
	if(sear)
	{
		key=hash(a);
		p=key%TS;	
		tp = hashTab[p].next;	
		while(tp != NULL)
		{
			if(strcmp(tp -> StudID, a) == 0)
			{
				tp1=tp;
			}
			tp = tp -> next;
		}
		if(tp1->status == 1)
		{
			printf("This student is log in now, you want to log out?\n");
			printf("Press 0 to log out, press 1 to keep log in\n");
			scanf("%d", &b);
			if(b==0)
			{
				tp1->status=0;
				printf("Alteady log out.\n");
				printf("Back to main menu\n");
				getch();
				return;
			}
			else
			{
				printf("Back to main menu\n");
				getch();
				return;
			}
		}
		else
		{
			printf("This student is log out now, you want to log in?\n");
			printf("Press 1 to log in, press 0 to keep log out\n");
			scanf("%d", &c);
			if(c==1)
			{
				tp1->status=1;
				printf("Alteady log in.\n");
				printf("Back to main menu\n");
				getch();
				return;
			}
			else
			{
				printf("Back to main menu\n");
				getch();
				return;
			}
		}
	}
	else
	{
		printf("WRONG! This ID is not exist\n");
		printf("Return to main menu\n");
		getch();
		return;
	}
}

void track(HASHTABLE hashTab[])
{
	nd tp, tp1;
	int key, p;
	char a[10];
	bool sear;
	printf("\nInput the student ID you want to track: ");
	gets(a);
	fflush(stdin);
	sear = searchID(hashTab, a);
	if(sear)
	{
		key=hash(a);
		p=key%TS;	
		tp = hashTab[p].next;	
		while(tp != NULL)
		{
			if(strcmp(tp -> StudID, a) == 0)
			{
				tp1=tp;
			}
			tp = tp -> next;
		}
		printf("Student's name is : %s %s %s\n", tp1->FName, tp1->MidInit, tp1->LName);
		if(tp1->status == 1)
		{
			printf("\nStatus is IN");
		}
		else
		{
			printf("\nStatus is OUT");
		}
		getch();
	}
	else
	{
		printf("WRONG! This ID is not exist\n");
		printf("Return to main menu\n");
		getch();
		return;
	}
}

void searchByID(HASHTABLE hashTab[])
{
	nd tp, tp1;
	int key, p;
	char a[10];
	bool sear;
	printf("Input the student ID you want to track: ");
	gets(a);
	fflush(stdin);
	sear = searchID(hashTab, a);
	if(sear)
	{
		key=hash(a);
		p=key%TS;	
		tp = hashTab[p].next;	
		while(tp != NULL)
		{
			if(strcmp(tp -> StudID, a) == 0)
			{
				tp1=tp;
			}
			tp = tp -> next;
		}
		printf("Student ID is : %s\n", tp1->StudID);
		printf("Student's name is : %s %s %s\n", tp1->FName, tp1->MidInit, tp1->LName);
		printf("Student's address is : %s\n", tp1->Address);
		printf("Student's course is : %s\n", tp1->Course);
		printf("Student's Father is : %s\n", tp1->Father);
		printf("Student's Mother is : %s\n", tp1->Mother);
		if(tp1->status == 1)
		{
			printf("\nStatus is IN\n");
		}
		else
		{
			printf("\nStatus is OUT");
		}
		getch();
	}
	else
	{
		printf("WRONG! This ID is not exist\n");
		printf("Return to main menu\n");
		getch();
		return;
	}
	
}

void searchByLName(HASHTABLE hashTab[])
{
	int i, j=0;
	nd tp;
	char a[20];
	printf("Input the student last Name you want to track: ");
	gets(a);
	fflush(stdin);
	for(i=0;i<TS;i++)
	{
		tp = hashTab[i].next;
		while(tp != NULL)
		{
			if(strcmp(tp->LName, a)==0)
			{
				printf("Student ID is : %s\n", tp->StudID);
				printf("Student's name is : %s %s %s\n", tp->FName, tp->MidInit, tp->LName);
				printf("Student's address is : %s\n", tp->Address);
				printf("Student's course is : %s\n", tp->Course);
				printf("Student's Father is : %s\n", tp->Father);
				printf("Student's Mother is : %s\n", tp->Mother);
			}
			tp = tp->next;
		}
	}
	getch();
}

void deleteValue(HASHTABLE hashTab[])
{
	nd tp, tp1 = NULL; 
	int key, p;
	char a[10];
	bool sear, deleted;
	printf("\nInput the student ID you want to delete: ");
	gets(a);
	fflush(stdin);
	sear = searchID(hashTab, a);
	if(sear)
	{
		key=hash(a);
		p=key%TS;	
		tp = hashTab[p].next;
		if(strcmp(tp -> StudID, a) == 0)
		{
			hashTab[p].next=tp->next;
			free(tp);
			printf("\nDelete Successful!\n");
		} 
		else
		{
			while(tp!=NULL)
			{
				tp1 = tp;
				tp=tp->next;
				if(strcmp(tp -> StudID, a) == 0)
				{
					tp1->next=tp->next;
					free(tp);
					printf("\nDelete Successful!\n");
				}
			}
		}
	}
	else
	{
		printf("WRONG! This ID is not exist\n");
		printf("Return to main menu\n");
		getch();
		return;
	}
	getch();
	return;
}

void viewAll(HASHTABLE hashTab[])
{
	int i, j=0;
	nd tp;
	for(i=0;i<TS;i++)
	{
		tp = hashTab[i].next;
		if(tp==NULL)
		{
			j++;
		}
		while(tp != NULL)
		{
			printf("Student ID is : %s\n", tp->StudID);
			printf("Student's name is : %s %s %s\n", tp->FName, tp->MidInit, tp->LName);
			printf("Student's address is : %s\n", tp->Address);
			printf("Student's course is : %s\n", tp->Course);
			printf("Student's Father is : %s\n", tp->Father);
			printf("Student's Mother is : %s\n\n", tp->Mother);
			tp = tp->next;
		}
	}
	if(j==TS)
	{
		printf("\nThe table is empty.\n");
	}
	return;	
}
