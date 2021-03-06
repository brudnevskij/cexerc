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
int snakelength = 0;
int* xcoordinates;
int* ycoordinates;
int x = 0;
int y = 0;
	int xapple;
	int yapple;
	time_t t;
	char* snakesprite = "#";
	char* applesprite = "@";
	int inputchar =0;
	int coordinates;


int getrandomint(int max){
    int random = (int)rand()%max;
    return random;
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
    *x = getrandomint(scrx);
    *y = getrandomint(scry);
    appleflag = 1;
}


void killapple(){
    appleflag = 0;
    
}

// O(1)
void addlength(){
     snakelength++;
    xcoordinates[snakelength] = x;
    ycoordinates[snakelength] = y;
}

// O(snakelength)
void removelength(){
    for(int i = 0; i < snakelength; i++){
	xcoordinates[i] = xcoordinates[i+1];
	ycoordinates[i] = ycoordinates[i+1];
    }
    snakelength--;
}

void writebody(){
    for(int i = 0; i < snakelength; i++){
	mvaddstr(ycoordinates[i], xcoordinates[i], snakesprite);
    }
}

int main(){

	srand(time(&t));
	initscr();
	mvaddstr(y,x, snakesprite);
	getmaxyx(stdscr, scry, scrx);
	coordinates = scrx*scry;
	spawnapple(&xapple, &yapple);
	xcoordinates = (int*)malloc(coordinates*sizeof(int));
	ycoordinates = (int*)malloc(coordinates*sizeof(int));
	addlength();
	mvaddstr(yapple,xapple, applesprite);
	while(inputchar!= 48){
	    inputchar =  getch();
	    erase();
	    if(inputchar == 115) mvd(&y);
	    if(inputchar == 119) mvu(&y);
	    if(inputchar == 97) mvl(&x);
	    if(inputchar == 100) mvr(&x);
	    if(x == xapple && y == yapple) killapple();
	    addlength();
	    if(appleflag == 1) removelength();
	    if(appleflag == 0)spawnapple(&xapple, &yapple);
	    if(appleflag == 1)mvaddstr(yapple, xapple, applesprite);
	    writebody();
	}
	endwin();
	return 0;
} 