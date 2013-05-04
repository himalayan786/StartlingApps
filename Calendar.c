/*
Write a C Program to build a Calendar like as that of Linux Calendar which is displayed on Ubuntu's Top right corner.
Use keys from the keyboard to jump between months and years.
Keys:
A: To move to last month
D: To jump to next month
S: To jump to last year
W: To move to next year
Usage:
$ gcc Calendar.c -o Calendar.out
$ ./Calendar.out
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <termios.h>
#include <fcntl.h>
//fuction prototyping
int kbhit(void);
void clrscr(void);
void gotoxy(int x, int y);
void box_initial(int);
void design(int color_button,int color_line);
void sunbutton(int x,int y,int bg);
void monbutton(int x,int y,int bg);
void tuebutton(int x,int y,int bg);
void wedbutton(int x,int y,int bg);
void thubutton(int x,int y,int bg);
void fributton(int x,int y,int bg);
void satbutton(int x,int y,int bg);
void betweendays(int row,int color);
void instruction(void); 
int calculate_day(int month,int year);
void displaymonth_year(int month,int year);
void printmonth(int day,int month,int year,int color_date);
//void dispsunday(int row,int color);
void dispframe(int row,int color_button,int color_line);
//global variable declaration

static int arr[40][90];

int main()//starting main
{
clrscr();
//variable declaration
int row=0,col=0,i=0,color=41;
for(i=0;i<2;i++)
{
	for(color=41;color<=43;color++)
	{
	printf("%c[1m",27);
	gotoxy(20,61);
	printf("%c[0m",27);
	printf("Welcome to Calendar (Developed by: Kunal Sharma)");
	box_initial(color);
	usleep(500000);
	}
}
clrscr();
design(45,31);
instruction();
//--------------------------------------------------------------------------------------------------working with logic
int year,month;
int rem;
char ch;
gotoxy(15,100);
printf("%c[43m",27);
printf("Enter month and year(as 3/1992):");
fflush(stdout);
printf("%c[0m",27);
printf("   ");
scanf("%d%c%d",&month,&ch,&year);
displaymonth_year(month,year);
rem=calculate_day(month,year);
dispframe(14,44,32);
printmonth(rem,month,year,31);
printf("%c[0m",27);
while(1)
{
	while(kbhit())
	{	
	int key=getchar();
	if(key==97)//a
	 {month=month-1;clrscr();design(45,35);dispframe(14,43,35);displaymonth_year(month,year);rem=calculate_day(month,year);printmonth(rem,month,year,31);break;}
	if(key==100)//d
	 {month=month+1;clrscr();design(42,32);dispframe(14,43,32);displaymonth_year(month,year);rem=calculate_day(month,year);printmonth(rem,month,year,32);break;}
	if(key==115)//s
	 {year=year-1;clrscr();design(41,31);dispframe(14,43,31);displaymonth_year(month,year);rem=calculate_day(month,year);printmonth(rem,month,year,34);break;}
	if(key==119)//w
	 {year=year+1;clrscr();design(44,34);dispframe(14,43,34);displaymonth_year(month,year);rem=calculate_day(month,year);printmonth(rem,month,year,35);break;}
	}
}


//----------------------------------------------------------------------------------------------------
printf("%c[0m",27);
gotoxy(50,0);
return 0;
}
//defining functions
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}
void clrscr(void)
{
printf("%c[2J",27);
}
void gotoxy(int x, int y)
{
printf("%c[%d;%df",27,x,y);
}
void sunbutton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    SUN    ");
	gotoxy(x+1,y);
	printf("           ");
}
void monbutton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    MON    ");
	gotoxy(x+1,y);
	printf("           ");
}
void tuebutton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    TUE    ");
	gotoxy(x+1,y);
	printf("           ");
}
void wedbutton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    WED    ");
	gotoxy(x+1,y);
	printf("           ");
}
void thubutton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    THU    ");
	gotoxy(x+1,y);
	printf("           ");
}
void fributton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    FRI    ");
	gotoxy(x+1,y);
	printf("           ");
}
void satbutton(int x,int y,int bg)
{
	gotoxy(x-1,y);
	printf("%c[1;37;%dm",27,bg);
	printf("           ");
	gotoxy(x,y);
	printf("    SAT    ");
	gotoxy(x+1,y);
	printf("           ");
}
void instruction(void)
{
	gotoxy(1,100);
	printf("%c[1;4m",27);
	printf("Instructions:");
	printf("%c[0m",27);
	printf("%c[1m",27);
	gotoxy(2,100);
	printf("1) Press 'a' for last month.");
	gotoxy(3,100);
	printf("2) Press 'd' for next month.");
	gotoxy(4,100);
	printf("3) Press 's' for last year.");
	gotoxy(5,100);
	printf("4) Press 'w' for next year.");
}
void betweendays(int row,int color)
{
	int i=0;
	printf("%c[0m",27);
	for(i=2;i<=88;i++)
	{
	printf("%c[%dm",27,color);
	gotoxy(row,i);
	printf("-");
	printf("%c[0m",27);
	}
}
int calculate_day(int month,int year)
{
int n1,n;
n=1 + 2*month + (3*(month+1)/5) + year + (year/4) - (year/100) + (year/400) +2;	
n1=n%7;
return n1;
//n1====0 saturday,,1 sun,2 mon,3 tue,4 wed and so on....
}
void displaymonth_year(int month,int year)
{
	printf("%c[1m",27);
	gotoxy(6,62);
	printf("<%d>",year);
	gotoxy(6,27);
	if(month==1)
		printf("<January>");
	if(month==2)
		printf("<February>");	
	if(month==3)
		printf("<March>");
	if(month==4)
		printf("<April>");
	if(month==5)
		printf("<May>");
	if(month==6)
		printf("<June>");
	if(month==7)
		printf("<July>");
	if(month==8)
		printf("<August>");
	if(month==9)
		printf("<September>");
	if(month==10)
		printf("<October>");
	if(month==11)
		printf("<November>");
	if(month==12)
		printf("<December>");
	printf("%c[0m",27);
}
void printmonth(int rem,int month,int year,int color_date)
{
int date;
int leap_year=0;
int jan=1,feb=2,march=3,april=4,may=5,june=6,july=7,aug=8,sept=9,oct=10,nov=11,dec=12;
if(year%4==0)// && year%100==0 && year%400==0
	{leap_year=1; 
	gotoxy(20,100);
	printf("%c[43m",27);
	printf("%c[1m%d is a leap year",27,year);
	printf("%c[0m",27);}
else 
	leap_year=0;
//if no leap year
if(leap_year==0)
{
if(month<1 || month>12)
{
	clrscr();
	printf("%c[15;60f",27);
	printf("%c[41;1;37m",27);
	printf("!!!CAUTION!!!");
	fflush(stdout);
	printf("%c[0m",27);
	printf("%c[20;48f",27);
	printf("%c[47;1;31m",27);
	printf("Error: Month<January or Month>December");
	fflush(stdout);
	printf("%c[0m",27);
	printf("%c[25;38f",27);
	printf("%c[47;1m",27);
	printf("Enter either 'd' or 'a' for correct response respectively.");
	fflush(stdout);
	printf("%c[0m",27);
}
if(month>=1 && month<=12)
{
if(month==jan || month==march || month==may || month==july || month==aug || month==oct || month==dec)
{
	if(rem==1)//printing for first day to be sunday
	{	int row=14,col=9;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==2)//printing for first day to be monday
	{	int row=14,col=21;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==3)//printing for first day to be tuesday
	{	int row=14,col=33;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==4)//printing for first day to be wednesday
	{	int row=14,col=45;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==5)//printing for first day to be thursday
	{	int row=14,col=57;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==6)//printing for first day to be friday
	{	int row=14,col=69;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==0)//printing for first day to be saturday
	{	int row=14,col=81;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
}//closing the month with 31 days
if(month==april || month==june || month==sept ||month==nov)//opening for months with 30 days
{
	if(rem==1)//printing for first day to be sunday
	{	int row=14,col=9;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}
		}
	}
	if(rem==2)//printing for first day to be monday
	{	int row=14,col=21;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==3)//printing for first day to be tuesday
	{	int row=14,col=33;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==4)//printing for first day to be wednesday
	{	int row=14,col=45;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==5)//printing for first day to be thursday
	{	int row=14,col=57;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==6)//printing for first day to be friday
	{	int row=14,col=69;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==0)//printing for first day to be saturday
	{	int row=14,col=81;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
}//closig for months 30 days
if(month==feb)//opening the 28 days case
{
	if(rem==1)//printing for first day to be sunday
	{	int row=14,col=9;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==2)//printing for first day to be monday
	{	int row=14,col=21;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==3)//printing for first day to be tuesday
	{	int row=14,col=33;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==4)//printing for first day to be wednesday
	{	int row=14,col=45;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==5)//printing for first day to be thursday
	{	int row=14,col=57;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==6)//printing for first day to be friday
	{	int row=14,col=69;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==0)//printing for first day to be saturday
	{	int row=14,col=81;
		for(date=1;date<=28;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
}//closing the 28 days case
}
}//closing the not leap year case
if(leap_year==1)//leap year case
{
if(month<1 || month>12)
{
	clrscr();
	printf("%c[15;60f",27);
	printf("%c[41;1;37m",27);
	printf("!!!CAUTION!!!");
	fflush(stdout);
	printf("%c[0m",27);
	printf("%c[20;48f",27);
	printf("%c[47;1;31m",27);
	printf("Error: Month<January or Month>December");
	fflush(stdout);
	printf("%c[0m",27);
	printf("%c[25;38f",27);
	printf("%c[47;1m",27);
	printf("Enter either 'd' or 'a' for correct response respectively.");
	fflush(stdout);
	printf("%c[0m",27);
}
if(month>=1 && month<=12)
{
if(month==jan || month==march || month==may || month==july || month==aug || month==oct || month==dec)
{
	if(rem==1)//printing for first day to be sunday
	{	int row=14,col=9;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==2)//printing for first day to be monday
	{	int row=14,col=21;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==3)//printing for first day to be tuesday
	{	int row=14,col=33;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==4)//printing for first day to be wednesday
	{	int row=14,col=45;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==5)//printing for first day to be thursday
	{	int row=14,col=57;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==6)//printing for first day to be friday
	{	int row=14,col=69;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==0)//printing for first day to be saturday
	{	int row=14,col=81;
		for(date=1;date<=31;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
}//closing the month with 31 days
if(month==april || month==june || month==sept ||month==nov)//opening for months with 30 days
{
	if(rem==1)//printing for first day to be sunday
	{	int row=14,col=9;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	gotoxy(row,col+9);//removing the extra location
	printf("%c[37;47m",27);
	printf("%c[0m",27);
	}
	if(rem==2)//printing for first day to be monday
	{	int row=14,col=21;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	gotoxy(row,col+9);//removing the extra location
	printf("%c[37;47m",27);
	printf("%c[0m",27);
	}
	if(rem==3)//printing for first day to be tuesday
	{	int row=14,col=33;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	gotoxy(row,col+9);//removing the extra location
	printf("%c[37;47m",27);
	printf("%c[0m",27);
	}
	if(rem==4)//printing for first day to be wednesday
	{	int row=14,col=45;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	gotoxy(row,col+9);//removing the extra location
	printf("%c[37;47m",27);
	printf("%c[0m",27);
	}
	if(rem==5)//printing for first day to be thursday
	{	int row=14,col=57;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==6)//printing for first day to be friday
	{	int row=14,col=69;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	gotoxy(row,col+9);//removing the extra location
	printf("%c[37;47m",27);
	printf("%c[0m",27);
	}
	if(rem==0)//printing for first day to be saturday
	{	int row=14,col=81;
		for(date=1;date<=30;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	gotoxy(row,col+9);//removing the extra location
	printf("%c[37;47m",27);
	printf("%c[0m",27);
	}
}//closig for months 30 days
if(month==feb)//opening the 28 days case
{
	if(rem==1)//printing for first day to be sunday
	{	int row=14,col=9;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==2)//printing for first day to be monday
	{	int row=14,col=21;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==3)//printing for first day to be tuesday
	{	int row=14,col=33;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==4)//printing for first day to be wednesday
	{	int row=14,col=45;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==5)//printing for first day to be thursday
	{	int row=14,col=57;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==6)//printing for first day to be friday
	{	int row=14,col=69;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	if(rem==0)//printing for first day to be saturday
	{	int row=14,col=81;
		for(date=1;date<=29;date++)
		{
		printf("%c[1;%dm",27,color_date);
		gotoxy(row,col);
		printf("%d",date);
		printf("%c[0m",27);
		fflush(stdout);
		col=col+12;
		if(col>85)
			{
			row=row+4;
			col=9;
			continue;
			}			
		}
	}
	}

}
}//closing the leap year case
}//closing the function

//=========================================================================================================================================================
/*ERRORS to be completed here are:
1) WHy month 1,9 and 12 of 2012 are not getting printed???*/

void design(int color_button,int color_line)
{
int row=0,col=0,i=0;
//designing section-------------------------------------------
//top border
for(col=1;col<=89;col++)
{
arr[1][col]=32;
gotoxy(1,col);
printf("%c[40m",27);
printf("%c",arr[1][col]);
}
//bottom border
for(col=1;col<=89;col++)
{
arr[39][col]=32;
gotoxy(39,col);
printf("%c[40m",27);
printf("%c",arr[39][col]);
}
//left border
for(row=1;row<=39;row++)
{
arr[row][1]=32;
gotoxy(row,1);
printf("%c[40m",27);
printf("%c",arr[row][1]);
}
//right border 
for(row=1;row<=39;row++)
{	
arr[row][89]=32;
gotoxy(row,89);
printf("%c[40m",27);
printf("%c",arr[row][89]);
}
//header top
for(col=2;col<=88;col++)
{
arr[2][col]=32;
gotoxy(2,col);
printf("%c[43m",27);
printf("%c",arr[2][col]);
}
//title
printf("%c[0m",27);
printf("%c[1;%dm",27,color_line);
gotoxy(3,30);
printf("**********JMS Calendar**********");
fflush(stdout);
printf("%c[0m",27);
//header bottom
for(col=2;col<=88;col++)
{
arr[4][col]=32;
gotoxy(4,col);
printf("%c[43m",27);
printf("%c",arr[4][col]);
}
//screen starting
for(col=2;col<=88;col++)
{
arr[5][col]=32;
gotoxy(5,col);
printf("%c[46m",27);
printf("%c",arr[5][col]);
}
//screen showing Year and Month
printf("%c[0m",27);
gotoxy(6,20);
printf("%c[1;%dmMONTH:",27,color_line);//Location here is 6,9
gotoxy(6,55);
printf("%c[1%dmYEAR:",27,color_line);//location here is 6,39
printf("%c[0m",27);
//screen endings
for(col=2;col<=88;col++)
{
arr[7][col]=32;
gotoxy(7,col);
printf("%c[46m",27);
printf("%c",arr[7][col]);
}

//showing days
sunbutton(10,4,color_button);
monbutton(10,16,color_button);
tuebutton(10,28,color_button);
wedbutton(10,40,color_button);
thubutton(10,52,color_button);
fributton(10,64,color_button);
satbutton(10,76,color_button);

//showing bars 
betweendays(8,color_line);
betweendays(12,color_line);
betweendays(16,color_line);
betweendays(20,color_line);
betweendays(24,color_line);
betweendays(28,color_line);
betweendays(32,color_line);
betweendays(36,color_line);

//instructions for help
printf("%c[0m",27);
//copyrights
printf("%c[1;37;%dm",27,color_line+10);
printf("%c[37;28fAll rights reserved with Kunal Sharma",27);
printf("%c[0m",27);
}	
void dispframe(int row,int color_button,int color_line)
{
int col=7;
for(row=14;row<=34;)
{
	gotoxy(row-1,col);
	printf("%c[1;%d;%dm",27,color_button,color_line);
	printf("|----|");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(row,col);
	printf("%c[1;%d;%dm",27,color_button,color_line);
	printf("|");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(row,col+5);
	printf("%c[1;%d;%dm",27,color_button,color_line);
	printf("|");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(row+1,col);
	printf("%c[1;%d;%dm",27,color_button,color_line);
	printf("|----|");
	fflush(stdout);
	printf("%c[0m",27);
 row=row+4;
}
}void box_initial(int color)
{
int row,col=0;
printf("%c[%dm",27,color);
for(row=1;row<=19;row++)
{
	for(col=1;col<=80;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
printf("%c[%dm",27,color+1);
for(row=1;row<=19;row++)
{
	for(col=81;col<=160;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
printf("%c[%dm",27,color+2);
for(row=21;row<=39;row++)
{
	for(col=1;col<=80;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
printf("%c[%dm",27,color+3);
for(row=21;row<=39;row++)
{
	for(col=81;col<=160;col++)
	{
	gotoxy(row,col);
	printf(" ");
	fflush(stdout);
	}
}
printf("%c[0m",27);
}
