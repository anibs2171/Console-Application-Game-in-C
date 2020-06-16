#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include<string.h>





int p=0;

//////////////////////////////////////////GETCH FUNCTION////////////////////////////////////

static struct termios old, new;
 

void initTermios(int echo) 
{
  tcgetattr(0, &old); 
  new = old; 
  new.c_lflag &= ~ICANON; 
  new.c_lflag &= echo ? ECHO : ~ECHO; 
  tcsetattr(0, TCSANOW, &new); 
}
 

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 

char getch(void) 	
{
  return getch_(0);
}
 

char getche(void) 
{
  return getch_(1);
}

////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////CLRSCR FUNCTION////////////////////////////////////////////

void clrscr(void)
{
    system("clear");

}


////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////GOTOXY FUNCTION/////////////////////////////////////
	
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}







/////////////////////////////////////GAME FUNCTION//////////////////////////////////////////

void game(){



int a=70,b=20;
int e=1,f=1;

//POINTS COORDINATES

int p1a=100,p1b=10;
int p2a=110,p2b=12;
int p3a=60,p3b=2;
int p4a=15,p4b=15;
int p5a=65,p5b=5;
int p6a=35,p6b=17;
int p7a=135,p7b=22;
int p8a=40,p8b=27;
int p9a=10,p9b=22;
int p10a=70,p10b=25;
int p11a=50,p11b=30;



char ch;

clrscr();


gotoxy(a,b);
printf("x");

//POINTS

gotoxy(p1a,p1b);
printf("$");

gotoxy(p2a,p2b);
printf("$");

gotoxy(p3a,p3b);
printf("$");

gotoxy(p4a,p4b);
printf("$");

gotoxy(p5a,p5b);
printf("$");

gotoxy(p6a,p6b);
printf("$");

gotoxy(p7a,p7b);
printf("$");

gotoxy(p8a,p8b);
printf("$");

gotoxy(p9a,p9b);
printf("$");

gotoxy(p10a,p10b);
printf("$");

gotoxy(p11a,p11b);
printf("$");



while(1)
{
	//MOVEMENTS
	ch=getch();

	if(ch==97)		//PRESS A TO MOVE
	{
		gotoxy(a,b);
		printf(" ");
		--a;
		gotoxy(a,b);
		printf("x");

		if((a==p1a && b==p1b)||(a==p2a && b==p2b)||(a==p3a && b==p3b)||(a==p4a && b==p4b)||(a==p5a && b==p5b)||(a==p6a && b==p6b)||(a==p7a && b==p7b)||(a==p8a && b==p8b)||(a==p9a && b==p9b)||(a==p10a && b==p10b)||(a==p11a && b==p11b))
		{
			p=p+10;
			gotoxy(e,f);
			printf("Points:%d",p);
			if (p == 110){
			printf("GAME COMPLETED");
			exit(0);
			}
		}


	}

	else if (ch==100)		//PRESS D TO MOVE RIGHT
	{
	 	gotoxy(a,b);
		printf(" ");
		++a;
		gotoxy(a,b);
		printf("x");

				if((a==p1a && b==p1b)||(a==p2a && b==p2b)||(a==p3a && b==p3b)||(a==p4a && b==p4b)||(a==p5a && b==p5b)||(a==p6a && b==p6b)||(a==p7a && b==p7b)||(a==p8a && b==p8b)||(a==p9a && b==p9b)||(a==p10a && b==p10b)||(a==p11a && b==p11b))
		{
			p+=10;
			gotoxy(e,f);
			printf("Points:%d",p);
			if (p == 110){
			printf("\nGAME COMPLETED");
			exit(0);
			}
		}



	}

	else if (ch==119)		//PRESS W TO MOVE UP
	{

	
	 	gotoxy(a,b);
		printf(" ");
		--b;
		gotoxy(a,b);
		printf("x");

		if((a==p1a && b==p1b)||(a==p2a && b==p2b)||(a==p3a && b==p3b)||(a==p4a && b==p4b)||(a==p5a && b==p5b)||(a==p6a && b==p6b)||(a==p7a && b==p7b)||(a==p8a && b==p8b)||(a==p9a && b==p9b)||(a==p10a && b==p10b)||(a==p11a && b==p11b))
		{
			p=p+10;
			gotoxy(e,f);
			printf("Points:%d",p);
			if (p == 110){
			printf("GAME COMPLETED");
			exit(0);
			}
		}



	}

	else if (ch==115)		//PRESS S TO MOVE DOWN
	

	{
	 	gotoxy(a,b);
		printf(" ");
		++b;
		gotoxy(a,b);
		printf("x");

		if((a==p1a && b==p1b)||(a==p2a && b==p2b)||(a==p3a && b==p3b)||(a==p4a && b==p4b)||(a==p5a && b==p5b)||(a==p6a && b==p6b)||(a==p7a && b==p7b)||(a==p8a && b==p8b)||(a==p9a && b==p9b)||(a==p10a && b==p10b)||(a==p11a && b==p11b))
		{
			p=p+10;
			gotoxy(e,f);
			printf("Points:%d",p);
			if (p == 110){
			printf("GAME COMPLETED");
			exit(0);
			}
		}


	}

	

	else{
		clrscr();
		
	}


}



}


////////////////////////////////////////////////////////////////////////////////////////////




int main(){


clrscr();

printf("\n\n\t\t\t\t\tTry this wonderful game presented to you by anibs2171\n");
printf("\n\n\t\t\t\t\tTry collecting all Dollars as fast as you can.\n");
printf("\n\n\t\t\t\t\tPress SPACE when you are READY TO GO.\n");
printf("\n\n\t\t\t\t\tThe controls are 'w','a','s', and 'd' keys.\n");
printf("\n\n\t\t\t\t\tPress any other key to skip the game.\n");

char sp;
sp=getch();


if(sp==32)
{

	clrscr();

	game();

}
return 0;
}