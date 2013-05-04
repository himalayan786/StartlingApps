#include<stdio.h>
//functuions declaration
void clrscr();
void gotoxy(int,int);
void box(int,int,int);
//start of main()
int main()
{
int row=1,col=1;
int sleep_time=2000;
int color=46;
for(;;)
{
if(color>=41)
{
	for(col=1;col<161;)
		{
		box(row,col,color);
		usleep(sleep_time);
		col=col+1;
		clrscr();
		}
	for(row=1;row<=40;)
		{	
		box(row,col,color);
		usleep(sleep_time);
		row++;
		clrscr();
		}
	for(col=161;col>=1;col--)
		{ 	
		box(row,col,color);
		clrscr();
		usleep(sleep_time);
		}
	for(row=40;row>1;)
		{	
		box(row,col,color);
		usleep(sleep_time);
		row--;
		clrscr();
		}
color=color-1;
}
else color=46;
}
return 0;
}
void clrscr()
{
printf("%c[2J",27);
}
void gotoxy(int x,int y)
{
printf("%c[%d;%df",27,x,y);
}
void box(int row,int col,int color)
{
	gotoxy(row,col);
	printf("%c[%dm",27,color);
	printf("       ");
	fflush(stdout);
	printf("%c[0m",27);
	gotoxy(row+1,col);
	printf("%c[1;37;%dm",27,color);
	printf(" KUNAL ");
	fflush(stdout);
	gotoxy(row+2,col);
	printf("%c[%dm",27,color);
	printf("       ");
	fflush(stdout);
	printf("%c[0m",27);
}

