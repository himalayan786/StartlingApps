#include<stdio.h>
#include<unistd.h>
int main()
{
printf("%c[2J",27);//clear screen
//------------------------------------------------------------Designing
//Variable declaration part
int row=0,col=0,i=0,j=0;
printf("%c[1;0f",27);//cursor at (1,0)
//---------------------------------------------------design of top boundry
for(i=0;i<50;i++)
{
printf("%c[1m*",27);
fflush(stdout);
}
i=0;
printf("%c[2;0f",27);//cursor at (2,0)
for(i=0;i<50;i++)
{
printf("%c[1m-",27);
fflush(stdout);
}
//---------------------------------------------------header design
printf("%c[3;0f",27);//cursor at (3,0)
printf("%c[1;4;30m",27);
printf("%c[9CHimachal Pradesh Traffic Police",27);
printf("%c[0m",27);//resetting all attributes
printf("%c[1;35m",27);
printf("%c[4;0f",27);//cursor at (4,0)
printf("%c[14CWelcomes You at Shimla",27);
printf("%c[0m",27);//resetting all attributes
i=0;
printf("%c[5;0f",27);//cursor at (5,0)
for(i=0;i<50;i++)
{
printf("%c[1m-",27);
fflush(stdout);
}
//---------------------------------------------------
//left boundry design
i=0;
printf("%c[0;0f",27);
for(i=0;i<35;i++)
{
printf("%c[%d;0f",27,i);
printf("%c[1m*|",27);
fflush(stdout);
}
printf("%c[0;1;30m",27);
//right boundry design
i=0;
printf("%c[0;50f",27);
for(i=0;i<35;i++)
{
printf("%c[%d;50f",27,i);
printf("%c[1m|*",27);
fflush(stdout);
}
//bottom boundry design
i=0;
printf("%c[35;0f",27);
for(i=0;i<51;i++)
{
printf("%c[1m*",27);
fflush(stdout);
}
//--------------------------------------------------
//Designing the lights
//designing the left side of inner arrow
	printf("%c[1;30m",27);
	printf("%c[6;25f*",27);
	printf("%c[7;24f*",27);
	printf("%c[8;23f*",27);
	printf("%c[9;22f*",27);
	printf("%c[10;21f*",27);
	printf("%c[11;20f*",27);
	printf("%c[11;19f*",27);
	printf("%c[11;18f*",27);
	printf("%c[11;17f*",27);
//designing the right side of inner arrow
	printf("%c[7;26f*",27);
	printf("%c[8;27f*",27);
	printf("%c[9;28f*",27);
	printf("%c[10;29f*",27);
	printf("%c[11;30f*",27);
	printf("%c[11;31f*",27);
	printf("%c[11;32f*",27);
	printf("%c[11;33f*",27);
//in between arrows
	printf("%c[8;25f*",27);
	printf("%c[9;23f*",27);
	printf("%c[9;25f*",27);
	printf("%c[9;27f*",27);
	printf("%c[10;22f*",27);
	printf("%c[10;25f*",27);
	printf("%c[10;28f*",27);
	for(j=21;j<30;j++)
	{
	printf("%c[11;%df*",27,j);
	}
//designing the left pole
i=0;
for(i=12;i<35;i++)
{
printf("%c[%d;18f",27,i);
printf("%c[1m|*",27);
fflush(stdout);
}
//designing the right pole
i=0;
for(i=12;i<35;i++)
{
printf("%c[%d;31f",27,i);
printf("%c[1m*|",27);
fflush(stdout);
}
//designing boxes
int arr[30][50];
/*//designing the timer clock....................................................My Code Reduction
for(row=30;row<35;row++)
{
for(col=21;col<30;col++)`````````````````````````````````````````````````````````Code.....Is Reduced here.....
{
printf("%c[%d;%df",27,row,col);
arr[row][col]=34;
printf("%c[1;37;47m",27);
printf("%c",arr[row][col]);
fflush(stdout);
}
}*/
printf("%c[7;7fHelp Us To",27);
printf("%c[7;34fKeep You Safe",27);

//----------------------------------------------finished with design-------------------------working on timer control
int time;
arr[29][25]=0;
for(time=60;time>0;time--)
{
printf("%c[1;30;47m",27);
arr[29][25]=time;
printf("%c[32;24f%2d",27,arr[29][25]);
fflush(stdout);
printf("%c[0m",27);//resetting all attributes
usleep(1000000);
if(time<=60 && time>=30)
{
	//red signal
	//designing the red signal 
	for(row=12;row<17;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[41m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
	//green and yellow off
	for(row=18;row<23;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[1;37;47m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
	for(row=24;row<29;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[1;37;47m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
}
//designing the green signal
else if(time<=30 && time>=10)
{
	for(row=24;row<29;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[1;42m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
	//red and yellow off
	for(row=12;row<17;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[37;47m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
	for(row=18;row<23;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[1;47m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
}
else if(time<=10 && time>=0)
{
//designing the yellow signal
	for(row=18;row<23;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[1;43m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
	//off red and green
	for(row=24;row<29;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[1;47m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
	for(row=12;row<17;row++)
	{
	for(col=21;col<30;col++)
	{
	printf("%c[%d;%df",27,row,col);
	arr[row][col]=32;
	printf("%c[37;47m",27);
	printf("%c",arr[row][col]);
	fflush(stdout);
	}
	}
}
}
printf("%c[0m",27);//resetting all attributes
printf("%c[40;0f",27);
printf("%c[0m",27);//resetting all attributes
fflush(stdout);
return 0;
}
