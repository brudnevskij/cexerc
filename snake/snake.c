#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//1. передвижение буквы
//2. контроль выхода за границы экрана
//3. яблоко

int scrx;
int scry;
int appleflag;

int getrandomx(){
    float randomx= (int)rand()%scrx;
    return randomx;
}
int getrandomy(){
    int randomy = (int)rand()%scry;
    return randomy;
}

void mvd(int* y){
    *y = *y+1;
    if(*y > scry) *y=0;
}

void mvu(int* y){
    *y = *y-1;
    if(*y < 0) *y = scry-1; 
}

void mvr(int* x){
    *x = *x+1;
    if(*x > scrx) *x = 0;
}

void mvl(int* x){
    *x = *x-1;
    if(*x < 0) *x = scrx-1;
}


void spawnapple(int* x, int* y){
    *x = getrandomx();
    *y = getrandomy();
    appleflag = 1;
}


void killapple(){
    appleflag = 0;
}


int main(){
	int x = 0;
	int y = 0;
	int xapple;
	int yapple;
	time_t t;
	//appleflag = 1;
	char* snakesprite = "#";
	char* applesprite = "@";
	int inch =0;
	srand(time(&t));
	
	initscr();
	mvaddstr(y,x, snakesprite);
	getmaxyx(stdscr, scry, scrx);
	//xapple = getrandomx();
	//yapple = getrandomy();
	spawnapple(&xapple, &yapple);
	mvaddstr(yapple,xapple, applesprite);
	while(inch!= 48){
	    
	    inch =  getch();
		erase();
	    if(inch == 115) mvd(&y);
	    if(inch == 119) mvu(&y);
	    if(inch == 97) mvl(&x);
	    if(inch == 100) mvr(&x);
	    if(x == xapple && y == yapple) killapple();
		mvaddstr(y,x,snakesprite);
	    	    if(appleflag == 0)spawnapple(&xapple, &yapple);
	    if(appleflag == 1)mvaddstr(yapple, xapple, applesprite);

	}
	
	endwin();
	printf("x %d \n  y %d " , getrandomx(), getrandomy());
	return 0;
} 