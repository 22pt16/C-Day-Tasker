#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

struct cal
{
    int date,year;
    char month;
    char day;
};//struct data//

int spaceforday(int year)
{
int d;
d=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
return d;
}//calendar formula

void day(struct cal c);//finding day

void calendar(struct cal c);//calendar

void countdown();//coundown func

int main()
{
        system("3F");//bg color
        int opt;
        char select;
        struct cal c;
        restart:
system("clear");
        printf("                   WELCOME TO OUR APPLICATION                         \n");
        printf("\n\nSelect your options to perform\n\n\n 1.YEARLY CALENDAR\n 2.TO FIND DAY FOR PARTICULAR DATE\n 3.STOP WATCH\n 4.COUNT DOWN\n");
        scanf("%d",&opt);

    switch(opt)
        {
        case 1:calendar(c);break;
        case 2: day(c);break;
//      case 3:stopwatch();break;
        case 4:countdown();break;
        default: {
                        printf("\n do you wish to restart?\n");
                        scanf("\n%c",&select);
                        if(select=='y')
                        {
                        goto restart;
                        };break;
                }
        }
return 0;
}

/******************************************************************************/

//2.find day//
void day(struct cal c)
{
 int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 char select,week[7][10] ;
 int date, mon, year, i, r, s = 0 ;


 strcpy(week[0], "Sunday") ;
 strcpy(week[1], "Monday") ;
 strcpy(week[2], "Tuesday") ;
 strcpy(week[3], "Wednesday") ;
 strcpy(week[4], "Thursday") ;
 strcpy(week[5], "Friday") ;
 strcpy(week[6], "Saturday");
//user input//
 printf("Enter a valid date (dd/mm/yyyy) : ");
 scanf("%d %d %d",&date, &mon, &year);

//error conditions//
if(mon>12||mon<0||date>31||date<0||year<1000)
{
printf("enter a valid date \n");
}

//formula//
 if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
 month[1]=29 ;
 for(i=0;i< mon-1;i++)
 s=s+month[i] ;
 s=s+(date + year + (year / 4) - 2) ;
 s=s%7;

system("clear");

printf("\nThe day on %d-%d-%d is\n : %s\n",date,mon,year,week[s]) ;

 }

/********************************************************************************************/

//1.calendar
void calendar(struct cal c)
{
char select;
system("Color 3F");

int i,year,dim,day,weekday=0,daystart;
printf("Enter year you want to explore\n");
scanf("%d",&year);

char*months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int noofdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
//condition
if((year%4==0&&year%100!=0)||(year%400==0))
{
noofdays[1]=29;
}

daystart=spaceforday(year);

system("clear");
for(i=0;i<12;i++)
    {
    dim=noofdays[i];
    printf("\n\n------------------%s--------------------\n",months[i]);
    printf("\n   SUN  MON  TUE  WED  THU  FRI  SAT\n");

    for(weekday=0;weekday<daystart;weekday++)
   printf("     ");

    for(day=1;day<=dim;day++)
        {
        printf("%5d",day);

        if(++weekday>6)
            {
                 printf("\n");
                 weekday=0;
            }

        daystart=weekday;
        }
    }

}

/**************************************************************************/
//4.count down
void countdown()
{
    int h,m,s;

    printf("Enter hours");
    scanf("%d",&h);
    printf("\nEnter minutes");
    scanf("%d",&m);
    printf("\nEnter seconds");
    scanf("%d",&s);

    while(1)
    {
        printf("\n%d : %d : %d",h,m,s);
        sleep(1);
        system("cls");
        s--;

        if(s==0&&m!=0)
        {
                s=59;
                m--;
        }
         if(s==0&&m==0&&h!=0)
        {
                h--;
                m=59;
                s=59;
        }
        if(h==0&&m==0&&s==0)
        {
        printf("\n  TIME UP /n");
        exit(0);

         }
   }
}



