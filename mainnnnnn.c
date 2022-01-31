#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct routine
{
    char day[20];
    char first[20];
    char second[10];
    char third[20];
    char fourth[20];
    char fifth[20];
};
int main()
{
    char ch;
	gotoxy(15,8);
    printf("<--:Routine Management System:-->");
    gotoxy(19,15);
    printf("Press F to continue.");
    ch = getch();
	if(ch=='F'||ch=='f')
	{
		menu();
	}
    else
    {
    	printf("You have pressed the wrong key !!");
	}
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MAIN MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add New Routine.");
    gotoxy(10,8);
    printf("2 : View Routine.");
    gotoxy(10,9);
    printf("3 : Search Routine Of A Particular Day.");
    gotoxy(10,10);
    printf("4 : Modify Routine.");
    gotoxy(10,11);
    printf("5 : Delete Routine.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct routine std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD NEW ROUTINE:-->");
        gotoxy(10,5);
        printf("Enter the new routine");
        gotoxy(10,7);
        printf("Enter DAY ");
        gets(std.day);
        gotoxy(10,8);
        printf("Enter FIRST PERIOD : ");
        gets(std.first);
        gotoxy(10,9);
        printf("Enter SECOND PERIOD: ");
        gets(std.second);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter THIRD PERIOD : ");
        gets(std.third);
        gotoxy(10,11);
        printf("Enter FOURTH PERIOD: ");
        gets(std.fourth);
        gotoxy(10,12);
        printf("Enter FIFTH PERIOD : ");
        gets(std.fifth);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("Want to add of another day's routine'? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct routine std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No    DAY       First        Second         Third        TIFFIN BREAK       Fourth          Fifth");
    gotoxy(10,6);
    printf("              (09:30-10:20) (10:30-11:20) (11:30-12:20)    (30 Minutes)    (01:10-02:00)   (02:10-04:00)        ");
    gotoxy(10,7);
    printf("--------------------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,9);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-11s%-13s%-15s%-32s%-16s%-10s",i,std.day,std.first,std.second,std.third,std.fourth,std.fifth);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct routine std;
    char stday[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH ROUTINE:-->");
    gotoxy(10,5);
    printf("Enter DAY : ");
    fflush(stdin);
    gets(stday);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stday,std.day) == 0){
            gotoxy(10,8);
            printf("DAY %s",std.day);
            gotoxy(10,9);
            printf("FIRST PERIOD  : %s",std.first);
            gotoxy(10,10);
            printf("SECOND PERIOD : %s",std.second);
            gotoxy(10,11);
            printf("THIRD PERIOD  : %s",std.third);
            gotoxy(10,12);
            printf("FOURTH PERIOD : %s",std.fourth);
            gotoxy(10,13);
            printf("FIFTH PERIOD  : %s",std.fifth);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char stday[20];
    FILE *fp;
    struct routine std;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY ROUTINE:-->");
    gotoxy(10,5);
    printf("Enter which day's routine you want to modify ");
    fflush(stdin);
    gets(stday);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stday,std.day) == 0){
            gotoxy(10,7);
            printf("Enter DAY : ");
            gets(std.day);
            gotoxy(10,8);
            printf("Enter FIRST PERIOD : ");
            gets(std.first);
            gotoxy(10,9);
            printf("Enter SECOND PERIOD : ");
            gets(std.second);
            gotoxy(10,10);
            printf("Enter THIRD PERIOD  : ");
            gets(std.third);
            gotoxy(10,11);
            printf("Enter FOURTH PERIOD : ");
            gets(std.fourth);
            printf("Enter FIFTH PERIOD : ");
            gets(std.fifth);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stday[20];
    FILE *fp,*ft;
    struct routine std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE ROUTINE:-->");
    gotoxy(10,5);
    printf("Enter which day's routine you want to delete': ");
    fflush(stdin);
    gets(stday);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stday,std.day)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
