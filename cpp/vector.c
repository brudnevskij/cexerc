#include <iostream>
using namespace std;

class Vector {
    public:
	int* repo;
	int capacitance;
	int occupied;
	Vector(){
	    capacitance = 10;
	    repo = (int*)malloc(capacitance*sizeof(int));
	    occupied = 0;
	}
	void addElement(int e){
	    if(occupied == capacitance-1)addCap();
	    repo[occupied] = e;
	    occupied++;
	}
	void pop(){
	    occupied--;
	}
	void pushElement(int e, int n){
	    if(occupied == capacitance-1)addCap();
	    if(n > capacitance){
		do{
		    addCap();
		}while(n > capacitance);
	    }
	    for(int i = occupied; i >= n; i--){
		repo[i+1] = repo[i];
	    }
	    repo[n] = e;
	    occupied++;
	}
	void deleteElement(int n){
	    if(n > occupied){
		cout << "Index is out of scope\n";
		return;
	    }
	    for(int i = n; i < occupied; i++){
		repo[i] = repo[i+1];
	    }
	    occupied--;
	}
	void printAr(){
	    for(int i = 0; i < occupied; i++) cout << repo[i] << " ";
	    cout << "\n";
	}
	int getElement(int n){
	    if(n > occupied) cout << "Index is out of scope" << "\n";
	    return repo[n];
	}
    private:
	void addCap(){
	    capacitance = capacitance*2;
	    repo = (int*)realloc(repo, capacitance);
	}
};

int main(){

    Vector vector;
    vector.addElement(16);
    vector.addElement(5);
    vector.addElement(7);
    vector.addElement(2);
    vector.addElement(5);
    vector.addElement(7);
    vector.pushElement(3, 0);
    vector.printAr();
    vector.deleteElement(1000);
    vector.deleteElement(0);
    vector.printAr();
    cout << vector.getElement(0);
    return 0;
}