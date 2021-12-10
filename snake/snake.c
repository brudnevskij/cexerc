#include <ncurses.h>

//1. передвижение буквы
//2. контроль выхода за границы экрана
//3. яблоко

void mvd(int* y){
    *y = *y+1;
}

void mvu(int* y){
    *y = *y-1;
}

void mvr(int* x){
    *x = *x+1;
}

void mvl(int* x){
    *x = *x-1;
}

int main(){
	int x;
	int y;
	x = 0;
	y = 0;
	int inch =0;
	initscr();
	mvaddstr(y,x, "#");
	while(inch!= 48){
	    inch =  getch();
		erase();
	    if(inch == 115) mvd(&y);
	    if(inch == 119) mvu(&y);
	    if(inch == 97) mvl(&x);
	    if(inch == 100) mvr(&x);
		mvaddstr(y,x,"#");
	    
	}
	endwin();
	return 0;
} 