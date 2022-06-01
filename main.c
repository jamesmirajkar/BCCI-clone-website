/*

----------Designing the BCCI ( BOARD OF CONTROL FOR CRICKET IN INDIA ) Clone website using data structures--------

Constraints :
Players can be searched using only one parameter.
Displaying only 15 players details at given time.

Functionalities :
--Display players details
--Searching the players by
       1) Name
       2) Grade
       3) Age
       4) DOB (date of birth)
       5) Role
--News headlines
--Current Fixtures display
--Fixtures display by their type of match
--Displaying the results of different formats (ODI , T20 and TEST)
--Polls with voting
--Redirecting to social handles
--Redirecting to IPL( Indian premiere league ) websites for more information

Details --
CODE BY : JAMES SAMUEL MIRAJKAR
SUBJECT : DSA
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

/// Structure to store the player details
typedef struct PLAYER_DETAILS
{
       char pname[50];
       int age;

       int day[2], month[2], year[2];
       char state[10];
       char Role[30];
       char GRADE[2];

       int MATS[3], RUNS[3], NO[3], INN[3], HS[3], CEN[3], HCEN[3];
       float AVE[3], SR[3];
       int MAT[3], BALL[3], RUN[3], WK[3], INNN[3], WK4[3];
       float ECO[3];

       struct PLAYER_DETAILS *next;
} * NODE;
typedef struct NEWS
{
       int day, month, year;
       char new[500];
       struct NEWS *next;
} * nNODE;
typedef struct POLLS
{
       char que[80], ch1[20], ch2[20], ch3[20], ch4[20];
       int ans1, ans2, ans3, ans4;
       struct POLLS *next;
} * pNODE;
void welcome();
NODE getnode();
NODE createlist(NODE head);
void display(NODE head);
void search(NODE head);
void search_name(NODE head);
void grade(NODE head);
void age(NODE head);
void DOB(NODE head);
void role(NODE head);
// void sort(NODE head);
nNODE news(nNODE nhead);
void displaynews(nNODE nhead);
void searchnews(nNODE nhead);
void currentfixtures();
void venue();
void result_role();
void ODIresults();
void TESTresults();
void T20results();
pNODE polls(pNODE phead);
void displatpolls(pNODE phead);
void insta();
void facebook();
void twe();
void ipl();
void shop();
void main()
{
       NODE head = NULL;
       nNODE nhead = NULL;
       pNODE phead = NULL;
       welcome();
       head = createlist(head);
       nhead = news(nhead);
       while (1)
       {
              int choice;
              printf("\n\nSelect the options from below\n");
              printf("1:Players details\n");
              printf("2:Search the players\n");
              printf("3:News \n");
              printf("4:Search news\n");
              printf("5:Fixtures\n");
              printf("6:Venue details\n");
              printf("7:Results by match type\n");
              printf("8:Polls\n");
              printf("9:For IPL details\n");
              printf("10:Follows us on instagram\n");
              printf("11:Follows us on facbook\n");
              printf("12:Follows us on twitter\n");
              printf("13:Shop\n");
              printf("14:exit\n");
              scanf("%d", &choice);
              switch (choice)
              {
              case 1:
                     display(head);
                     break;
              case 2:
                     search(head);
                     break;
              case 3:
                     displaynews(nhead);
                     break;
              case 4:
                     searchnews(nhead);
                     break;
              case 5:
                     currentfixtures();
                     break;
              case 6:
                     venue();
                     break;
              case 7:
                     result_role();
                     break;
              case 8:
                     phead = polls(phead);
                     displatpolls(phead);
                     break;
              case 9:
                     ipl();
                     break;
              case 10:
                     insta();
                     break;
              case 11:
                     facebook();
                     break;
              case 12:
                     twe();
                     break;
              case 13:
                     shop();
                     break;
              case 14:
                     exit(0);
                     break;
              default:
                     break;
              }
       }
}
NODE getnode()
{
       NODE newnode;
       newnode = (NODE)malloc(sizeof(struct PLAYER_DETAILS));
       if (newnode == NULL)
       {
              printf("Node not created\n");
              exit(0);
       }
       newnode->next = NULL;
       return newnode;
}
NODE createlist(NODE head)
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("PLAYER.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }

       /// Until the end of the file, read all the file data
       NODE newnode;
       while (!feof(fp))
       {
              newnode = getnode();
              fscanf(fp, "%s %d %d %d %d %d %d %d %s %s", newnode->pname, &newnode->age,
                     &newnode->day[0], &newnode->month[0], &newnode->year[0],
                     &newnode->day[1], &newnode->month[1], &newnode->year[1],
                     newnode->Role, newnode->GRADE);

              fscanf(fp, "%d %d %d %d %d %f %f %d %d",
                     &newnode->MATS[0], &newnode->INN[0], &newnode->NO[0],
                     &newnode->RUNS[0], &newnode->HS[0], &newnode->AVE[0],
                     &newnode->SR[0], &newnode->CEN[0], &newnode->HCEN[0]);
              fscanf(fp, "%d %d %d %d %d %f %f %d %d",
                     &newnode->MATS[1], &newnode->INN[1], &newnode->NO[1],
                     &newnode->RUNS[1], &newnode->HS[1], &newnode->AVE[1],
                     &newnode->SR[1], &newnode->CEN[1], &newnode->HCEN[1]);
              fscanf(fp, "%d %d %d %d %d %f %f %d %d",
                     &newnode->MATS[2], &newnode->INN[2], &newnode->NO[2],
                     &newnode->RUNS[2], &newnode->HS[2], &newnode->AVE[2],
                     &newnode->SR[2], &newnode->CEN[2], &newnode->HCEN[2]);

              fscanf(fp, "%d %d %d %d %d %f %d",
                     &newnode->MAT[0], &newnode->INNN[0], &newnode->BALL[0],
                     &newnode->RUN[0], &newnode->WK[0], &newnode->ECO[0],
                     &newnode->WK4[0]);
              fscanf(fp, "%d %d %d %d %d %f %d",
                     &newnode->MAT[1], &newnode->INNN[1], &newnode->BALL[1],
                     &newnode->RUN[1], &newnode->WK[1], &newnode->ECO[1],
                     &newnode->WK4[1]);
              fscanf(fp, "%d %d %d %d %d %f %d\n",
                     &newnode->MAT[2], &newnode->INNN[2], &newnode->BALL[2],
                     &newnode->RUN[2], &newnode->WK[2], &newnode->ECO[2],
                     &newnode->WK4[2]);
              if (head == NULL)
              {
                     head = newnode;
              }
              else
              {
                     NODE temp = head;
                     while (temp->next != NULL)
                            temp = temp->next;

                     temp->next = newnode;
              }
       }
       fclose(fp);
       return head;
}
void display(NODE head)
{
       NODE newnode = head;
       while (newnode != NULL)
       {
              printf("NAME : %s\nAGE : %d\nDEBUT : %d %d %d\nDOB : %d %d %d\nROLE : %s\nGRADE : %s\n", newnode->pname, newnode->age,
                     newnode->day[0], newnode->month[0], newnode->year[0],
                     newnode->day[1], newnode->month[1], newnode->year[1],
                     newnode->Role, newnode->GRADE);
              printf("BATTING\n");
              printf("ODI -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                     newnode->MATS[0], newnode->INN[0], newnode->NO[0],
                     newnode->RUNS[0], newnode->HS[0], newnode->AVE[0],
                     newnode->SR[0], newnode->CEN[0], newnode->HCEN[0]);
              printf("TEST -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                     newnode->MATS[1], newnode->INN[1], newnode->NO[1],
                     newnode->RUNS[1], newnode->HS[1], newnode->AVE[1],
                     newnode->SR[1], newnode->CEN[1], newnode->HCEN[1]);
              printf("T20 -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                     newnode->MATS[2], newnode->INN[2], newnode->NO[2],
                     newnode->RUNS[2], newnode->HS[2], newnode->AVE[2],
                     newnode->SR[2], newnode->CEN[2], newnode->HCEN[2]);
              printf("BOWLING\n");
              printf("ODI -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                     newnode->MAT[0], newnode->INNN[0], newnode->BALL[0],
                     newnode->RUN[0], newnode->WK[0], newnode->ECO[0],
                     newnode->WK4[0]);
              printf("TEST -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                     newnode->MAT[1], newnode->INNN[1], newnode->BALL[1],
                     newnode->RUN[1], newnode->WK[1], newnode->ECO[1],
                     newnode->WK4[1]);
              printf("T20 -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n\n\n",
                     newnode->MAT[2], newnode->INNN[2], newnode->BALL[2],
                     newnode->RUN[2], newnode->WK[2], newnode->ECO[2],
                     newnode->WK4[2]);
              newnode = newnode->next;
       }
}
void search(NODE head)
{
       int choice;
       printf("Enter choice to search with\n1:Name\n2:Grade\n3:Age\n4:Birth Year\n5:Role\n6:Exit\n");
       scanf("%d", &choice);
       switch (choice)
       {
       case 1:
              search_name(head);
              break;
       case 2:
              grade(head);
              break;
       case 3:
              age(head);
              break;
       case 4:
              DOB(head);
              break;
       case 5:
              role(head);
              break;
       case 6:
              exit(0);
              break;
       default:
              break;
       }
}
void search_name(NODE head)
{
       char s[50];
       printf("Enter the name : ");
       scanf("%s", s);
       NODE newnode = head;
       while (newnode != NULL)
       {
              if (strcmp(newnode->pname, s) == 0)
              {
                     printf("NAME : %s\nAGE : %d\nDEBUT : %d %d %d\nDOB : %d %d %d\nROLE : %s\nGRADE : %s\n", newnode->pname, newnode->age,
                            newnode->day[0], newnode->month[0], newnode->year[0],
                            newnode->day[1], newnode->month[1], newnode->year[1],
                            newnode->Role, newnode->GRADE);
                     printf("BATTING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[0], newnode->INN[0], newnode->NO[0],
                            newnode->RUNS[0], newnode->HS[0], newnode->AVE[0],
                            newnode->SR[0], newnode->CEN[0], newnode->HCEN[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[1], newnode->INN[1], newnode->NO[1],
                            newnode->RUNS[1], newnode->HS[1], newnode->AVE[1],
                            newnode->SR[1], newnode->CEN[1], newnode->HCEN[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[2], newnode->INN[2], newnode->NO[2],
                            newnode->RUNS[2], newnode->HS[2], newnode->AVE[2],
                            newnode->SR[2], newnode->CEN[2], newnode->HCEN[2]);
                     printf("BOWLING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[0], newnode->INNN[0], newnode->BALL[0],
                            newnode->RUN[0], newnode->WK[0], newnode->ECO[0],
                            newnode->WK4[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[1], newnode->INNN[1], newnode->BALL[1],
                            newnode->RUN[1], newnode->WK[1], newnode->ECO[1],
                            newnode->WK4[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n\n\n",
                            newnode->MAT[2], newnode->INNN[2], newnode->BALL[2],
                            newnode->RUN[2], newnode->WK[2], newnode->ECO[2],
                            newnode->WK4[2]);
              }
              newnode = newnode->next;
       }
}
void grade(NODE head)
{
       char k[3];
       printf("Enter the Grade : ");
       scanf("%s", k);
       NODE newnode = head;
       while (newnode != NULL)
       {
              if (strcmp(newnode->GRADE, k) == 0)
              {
                     printf("NAME : %s\nAGE : %d\nDEBUT : %d %d %d\nDOB : %d %d %d\nROLE : %s\nGRADE : %s\n", newnode->pname, newnode->age,
                            newnode->day[0], newnode->month[0], newnode->year[0],
                            newnode->day[1], newnode->month[1], newnode->year[1],
                            newnode->Role, newnode->GRADE);
                     printf("BATTING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[0], newnode->INN[0], newnode->NO[0],
                            newnode->RUNS[0], newnode->HS[0], newnode->AVE[0],
                            newnode->SR[0], newnode->CEN[0], newnode->HCEN[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[1], newnode->INN[1], newnode->NO[1],
                            newnode->RUNS[1], newnode->HS[1], newnode->AVE[1],
                            newnode->SR[1], newnode->CEN[1], newnode->HCEN[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[2], newnode->INN[2], newnode->NO[2],
                            newnode->RUNS[2], newnode->HS[2], newnode->AVE[2],
                            newnode->SR[2], newnode->CEN[2], newnode->HCEN[2]);
                     printf("BOWLING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[0], newnode->INNN[0], newnode->BALL[0],
                            newnode->RUN[0], newnode->WK[0], newnode->ECO[0],
                            newnode->WK4[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[1], newnode->INNN[1], newnode->BALL[1],
                            newnode->RUN[1], newnode->WK[1], newnode->ECO[1],
                            newnode->WK4[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n\n\n",
                            newnode->MAT[2], newnode->INNN[2], newnode->BALL[2],
                            newnode->RUN[2], newnode->WK[2], newnode->ECO[2],
                            newnode->WK4[2]);
              }
              newnode = newnode->next;
       }
}
void age(NODE head)
{
       int k;
       printf("Enter the age : ");
       scanf("%d", &k);
       NODE newnode = head;
       while (newnode != NULL)
       {
              if (newnode->age == k)
              {
                     printf("NAME : %s\nAGE : %d\nDEBUT : %d %d %d\nDOB : %d %d %d\nROLE : %s\nGRADE : %s\n", newnode->pname, newnode->age,
                            newnode->day[0], newnode->month[0], newnode->year[0],
                            newnode->day[1], newnode->month[1], newnode->year[1],
                            newnode->Role, newnode->GRADE);
                     printf("BATTING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[0], newnode->INN[0], newnode->NO[0],
                            newnode->RUNS[0], newnode->HS[0], newnode->AVE[0],
                            newnode->SR[0], newnode->CEN[0], newnode->HCEN[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[1], newnode->INN[1], newnode->NO[1],
                            newnode->RUNS[1], newnode->HS[1], newnode->AVE[1],
                            newnode->SR[1], newnode->CEN[1], newnode->HCEN[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[2], newnode->INN[2], newnode->NO[2],
                            newnode->RUNS[2], newnode->HS[2], newnode->AVE[2],
                            newnode->SR[2], newnode->CEN[2], newnode->HCEN[2]);
                     printf("BOWLING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[0], newnode->INNN[0], newnode->BALL[0],
                            newnode->RUN[0], newnode->WK[0], newnode->ECO[0],
                            newnode->WK4[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[1], newnode->INNN[1], newnode->BALL[1],
                            newnode->RUN[1], newnode->WK[1], newnode->ECO[1],
                            newnode->WK4[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n\n\n",
                            newnode->MAT[2], newnode->INNN[2], newnode->BALL[2],
                            newnode->RUN[2], newnode->WK[2], newnode->ECO[2],
                            newnode->WK4[2]);
              }
              newnode = newnode->next;
       }
}
void DOB(NODE head)
{
       int k;
       printf("Enter the Year : ");
       scanf("%d", &k);
       NODE newnode = head;
       while (newnode != NULL)
       {
              if (newnode->year[1] == k)
              {
                     printf("NAME : %s\nAGE : %d\nDEBUT : %d %d %d\nDOB : %d %d %d\nROLE : %s\nGRADE : %s\n", newnode->pname, newnode->age,
                            newnode->day[0], newnode->month[0], newnode->year[0],
                            newnode->day[1], newnode->month[1], newnode->year[1],
                            newnode->Role, newnode->GRADE);
                     printf("BATTING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[0], newnode->INN[0], newnode->NO[0],
                            newnode->RUNS[0], newnode->HS[0], newnode->AVE[0],
                            newnode->SR[0], newnode->CEN[0], newnode->HCEN[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[1], newnode->INN[1], newnode->NO[1],
                            newnode->RUNS[1], newnode->HS[1], newnode->AVE[1],
                            newnode->SR[1], newnode->CEN[1], newnode->HCEN[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[2], newnode->INN[2], newnode->NO[2],
                            newnode->RUNS[2], newnode->HS[2], newnode->AVE[2],
                            newnode->SR[2], newnode->CEN[2], newnode->HCEN[2]);
                     printf("BOWLING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[0], newnode->INNN[0], newnode->BALL[0],
                            newnode->RUN[0], newnode->WK[0], newnode->ECO[0],
                            newnode->WK4[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[1], newnode->INNN[1], newnode->BALL[1],
                            newnode->RUN[1], newnode->WK[1], newnode->ECO[1],
                            newnode->WK4[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n\n\n",
                            newnode->MAT[2], newnode->INNN[2], newnode->BALL[2],
                            newnode->RUN[2], newnode->WK[2], newnode->ECO[2],
                            newnode->WK4[2]);
              }
              newnode = newnode->next;
       }
}
void role(NODE head)
{
       char s[50];
       printf("Enter the Role : ");
       scanf("%s", s);
       NODE newnode = head;
       while (newnode != NULL)
       {
              if (strcmp(newnode->Role, s) == 0)
              {
                     printf("NAME : %s\nAGE : %d\nDEBUT : %d %d %d\nDOB : %d %d %d\nROLE : %s\nGRADE : %s\n", newnode->pname, newnode->age,
                            newnode->day[0], newnode->month[0], newnode->year[0],
                            newnode->day[1], newnode->month[1], newnode->year[1],
                            newnode->Role, newnode->GRADE);
                     printf("BATTING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[0], newnode->INN[0], newnode->NO[0],
                            newnode->RUNS[0], newnode->HS[0], newnode->AVE[0],
                            newnode->SR[0], newnode->CEN[0], newnode->HCEN[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[1], newnode->INN[1], newnode->NO[1],
                            newnode->RUNS[1], newnode->HS[1], newnode->AVE[1],
                            newnode->SR[1], newnode->CEN[1], newnode->HCEN[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, NOTOUTS : %d, RUNS :%d, HIGHEST SCO : %d, AVG : %f, SR : %f, '100's : %d, '50's : %d\n",
                            newnode->MATS[2], newnode->INN[2], newnode->NO[2],
                            newnode->RUNS[2], newnode->HS[2], newnode->AVE[2],
                            newnode->SR[2], newnode->CEN[2], newnode->HCEN[2]);
                     printf("BOWLING\n");
                     printf("ODI -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[0], newnode->INNN[0], newnode->BALL[0],
                            newnode->RUN[0], newnode->WK[0], newnode->ECO[0],
                            newnode->WK4[0]);
                     printf("TEST -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n",
                            newnode->MAT[1], newnode->INNN[1], newnode->BALL[1],
                            newnode->RUN[1], newnode->WK[1], newnode->ECO[1],
                            newnode->WK4[1]);
                     printf("T20 -- MATCHES : %d, INN : %d, BALL : %d, RUNS : %d, WICKETS : %d, ECON : %f, 4 WKT HAULS  : %d\n\n\n",
                            newnode->MAT[2], newnode->INNN[2], newnode->BALL[2],
                            newnode->RUN[2], newnode->WK[2], newnode->ECO[2],
                            newnode->WK4[2]);
              }
              newnode = newnode->next;
       }
}
nNODE news(nNODE nhead)
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("NEWS.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              nNODE newnode;
              newnode = (nNODE)malloc(sizeof(struct NEWS));
              if (newnode == NULL)
              {
                     printf("Node not created\n");
                     exit(0);
              }
              newnode->next = NULL;
              fscanf(fp, "%d %d %d %s", &newnode->day, &newnode->month, &newnode->year, newnode->new);
              if (nhead == NULL)
              {
                     nhead = newnode;
              }
              else
              {
                     nNODE temp = nhead;
                     while (temp->next != NULL)
                            temp = temp->next;

                     temp->next = newnode;
              }
       }
       fclose(fp);
       return nhead;
}
void displaynews(nNODE nhead)
{
       nNODE newnode = nhead;
       while (newnode != NULL)
       {
              printf("Date : %d %d %d\nNews : %s\n\n", newnode->day, newnode->month, newnode->year, newnode->new);
              newnode = newnode->next;
       }
}
void searchnews(nNODE nhead)
{
       int da, mon, yr;
       printf("Enter the date in dd mm yyyy format to search news : ");
       scanf("%d %d %d", &da, &mon, &yr);
       nNODE newnode = nhead;
       while (newnode != NULL)
       {
              if (newnode->day == da && newnode->month == mon && newnode->year == yr)
              {
                     printf("Date : %d %d %d\nNews : %s\n\n", newnode->day, newnode->month, newnode->year, newnode->new);
              }
              newnode = newnode->next;
       }
}
void currentfixtures()
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("FIXTURES.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              int day, month, year;
              char fname[100];
              float tm;
              char am_pm[2];
              char opponent[40];
              char mat_type[10];
              int mat_no;
              char std[100];
              fscanf(fp, "%s %d %d %d %f %s %s %s %d %s", fname, &day,
                     &month, &year, &tm, am_pm, opponent,
                     mat_type, &mat_no, std);
              printf("\nFixture Name: %s\nDate: %d\\%d\\%d \nTime: %0.2f %s\nOpponent: %s\nMatch_Type: %s\nMatch_NO: %d\nStadium: %s\n",
                     fname, day, month, year, tm, am_pm, opponent, mat_type, mat_no, std);
       }
}
void venue()
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("VENUE.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              int nmb;
              char vname[50];
              int capacity;
              char location[30];
              char vstate[30];

              fscanf(fp, "%d %s %d %s %s", &nmb, vname, &capacity, location, vstate);
              printf("Name : %s\nCapacity : %d\nLocation : %s\nState : %s\n\n", vname, capacity, location, vstate);
       }
       fclose(fp);
}
void result_role()
{
       int choice;
       printf("Enter\n1:ODI results\n2:TEST results\n3:T20 results\n4:Exit\n");
       scanf("%d", &choice);
       switch (choice)
       {
       case 1:
              ODIresults();
              break;
       case 2:
              TESTresults();
              break;
       case 3:
              T20results();
              break;
       case 4:
              exit(0);
              break;
       default:
              break;
       }
}
void ODIresults()
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("RESULTS_ODI.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              char s_name[100];
              char opp[50];
              int op_run, day, month, year;
              int op_wc;
              float op_over;
              int in_run;
              int in_wc;
              float in_over;
              char res[100];
              fscanf(fp, "%s %s %d %d %d %d %d %f %d %d %f %s", s_name, opp, &day, &month, &year,
                     &op_run, &op_wc, &op_over, &in_run, &in_wc, &in_over, res);

              printf("\nODI Results\n");
              printf("\nSeries Name: %s\n", s_name);
              printf("Date: %d\\%d\\%d\n", day, month, year);
              printf("%s\n", opp);
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", op_run, op_wc, op_over);
              printf("INDIA:\n");
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", in_run, in_wc, in_over);
              printf("Result: %s\n", res);
       }
       fclose(fp);
}
void TESTresults()
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("RESULTS_TEST.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              char s_name[100];
              char opp[50];
              int op_run1, day, month, year;
              int op_wc1;
              float op_over1;
              int op_run2;
              int op_wc2;
              float op_over2;
              int in_run1;
              int in_wc1;
              float in_over1;
              int in_run2;
              int in_wc2;
              float in_over2;
              char res[100];
              fscanf(fp, "%s %s %d %d %d %d %d %f %d %d %f %d %d %f %d %d %f %s", s_name, opp,
                     &day, &month, &year, &op_run1, &op_wc1, &op_over1, &op_run2, &op_wc2, &op_over2,
                     &in_run1, &in_wc1, &in_over1, &in_run2, &in_wc2, &in_over2, res);

              printf("\nTEST Results\n");
              printf("Series Name: %s\n", s_name);
              printf("Date: %d\\%d\\%d\n", day, month, year);
              printf("%s\n", opp);
              printf("First Innings\n");
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", op_run1, op_wc1, op_over1);
              printf("Second Innings\n");
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", op_run2, op_wc2, op_over2);
              printf("INDIA:\n");
              printf("First Innings\n");
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", in_run1, in_wc1, in_over1);
              printf("Second Innings\n");
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", in_run2, in_wc2, in_over2);
              printf("Reslut: %s\n", res);
       }
       fclose(fp);
}
void T20results()
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("RESULTS_T20.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              char s_name[100];
              char opp[50];
              int op_run, day, month, year;
              int op_wc;
              float op_over;
              int in_run;
              int in_wc;
              float in_over;
              char res[100];
              fscanf(fp, "%s %s %d %d %d %d %d %f %d %d %f %s", s_name, opp, &day, &month, &year,
                     &op_run, &op_wc, &op_over, &in_run, &in_wc, &in_over, res);

              printf("\nODI Results\n");
              printf("\nSeries Name: %s\n", s_name);
              printf("Date: %d\\%d\\%d\n", day, month, year);
              printf("%s\n", opp);
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", op_run, op_wc, op_over);
              printf("INDIA:\n");
              printf("Runs: %d Wickets: %d Overs: %0.2f\n", in_run, in_wc, in_over);
              printf("Result: %s\n", res);
       }
       fclose(fp);
}
pNODE polls(pNODE phead)
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("POLLS.txt", "r");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       while (!feof(fp))
       {
              pNODE newnode;
              newnode = (pNODE)malloc(sizeof(struct POLLS));
              if (newnode == NULL)
              {
                     printf("Node not created\n");
                     exit(0);
              }
              newnode->next = NULL;
              fscanf(fp, "%s %s %s %s %s %d %d %d %d", newnode->que, newnode->ch1, newnode->ch2, newnode->ch3, newnode->ch4, &newnode->ans1, &newnode->ans2, &newnode->ans3, &newnode->ans4);

              if (phead == NULL)
              {
                     phead = newnode;
              }
              else
              {
                     pNODE temp = phead;
                     while (temp->next != NULL)
                            temp = temp->next;

                     temp->next = newnode;
              }
       }
       fclose(fp);
       return phead;
}
void displatpolls(pNODE phead)
{
       FILE *fp;
       /// Open the file in read mode
       fp = fopen("POLLS.txt", "r+");

       /// Check if the file was successfully opened
       if (fp == NULL)
       {
              printf("File Not found\n");
              exit(0);
       }
       pNODE temp = phead;
       while (temp != NULL)
       {
              printf("Question : %s \n 1) %s\t2) %s \t3) %s\t 4) %s\n", temp->que, temp->ch1, temp->ch2, temp->ch3, temp->ch4);
              int k = 0;
              scanf("%d", &k);
              switch (k)
              {
              case 1:
                     temp->ans1++;
                     break;
              case 2:
                     temp->ans2++;
                     break;
              case 3:
                     temp->ans3++;
                     break;
              case 4:
                     temp->ans4++;
                     break;
              default:
                     break;
              }
              fprintf(fp, "%s %s %s %s %s %d %d %d %d\n", temp->que, temp->ch1, temp->ch2, temp->ch3, temp->ch4, temp->ans1, temp->ans2, temp->ans3, temp->ans4);
              int sum = temp->ans1 + temp->ans2 + temp->ans3 + temp->ans4;
              printf("1 %d\t\t 2 %d\t\t 3 %d\t\t 4 %d\n", ((temp->ans1 * 100) / sum), ((temp->ans2 * 100) / sum), ((temp->ans3 * 100) / sum), ((temp->ans4 * 100) / sum));
              temp = temp->next;
       }
       fclose(fp);
}
void insta()
{
       printf("\nRedirecting To Instagram\n");
       system("start https://www.instagram.com/indiancricketteam/");
}
void facebook()
{
       printf("\nRedirecting To Facebook\n");
       system("start https://www.facebook.com/IndianCricketTeam/");
}
void twe()
{
       printf("\nRedirecting To Twitter\n");
       system("start https://twitter.com/BCCI");
}
void ipl()
{
       printf("Redirecting IPL\n");
       system("start https://iplt20.com/");
}
void shop()
{
       printf("Redirecting Shopping\n");
       system("start https://mplsports.in/pages/bcci");
}
void welcome()
{
       for (int k = 0; k < 2; k++)
       {
              for (int i = 0; i < 20; i++)
              {
                     if (i == 19)
                            printf("BCCI");
                     else
                            printf("BCCI_");
              }
              printf("\n");
       }

       printf("\n\n\n\t\t\t\t\tWELCOME TO THE BCCI!!!");
       printf("\n\t\t\t\tTHE BOARD OF CONTROL FOR CRICKET IN INDIA");

       /// Declare the two Date structures
       SYSTEMTIME t, t2;

       /// Fills out the t with the IST system date and time
       GetLocalTime(&t);

       /// Fills out the t2 with the UTC system date and time
       GetSystemTime(&t2);

       printf("\n\n\t\t\t\t     IST\t\t\tUTC");
       printf("\n\t\t\t\tDate:%d/%d/%d", t.wDay, t.wMonth, t.wYear);
       printf("\t\t   Date:%d/%d/%d", t2.wDay, t2.wMonth, t2.wYear);

       printf("\n\t\t\t\tTime:%d:%d:%d", t.wHour, t.wMinute, t.wSecond);
       printf("\t\t   Time:%d:%d:%d", t2.wHour, t2.wMinute, t2.wSecond);

       printf("\n\n\n\n");

       for (int k = 0; k < 2; k++)
       {
              for (int i = 0; i < 20; i++)
              {
                     if (i == 19)
                            printf("BCCI");
                     else
                            printf("BCCI_");
              }
              printf("\n");
       }

       printf("\n");
}
