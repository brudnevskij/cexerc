#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct list{

char* word;
struct list* link;

};

struct list* swaplist(struct list* list);

void freelist(struct list*);

int stringlen(char s[]){
    int r = 0;
    while(s[r]!='\0'){
	r++;
}
    return r;
}

int is_substring(char s1[], char s2[]){
    int sublen = stringlen(s1);
    int strlen = stringlen(s2);
    int dif = strlen - sublen;
    int counter = 0;
    if(dif >= 0){
	for(int i = 0; i <= dif; i++){
	    for(int j = 0; j < sublen; j++){
		printf("%c==%c\n", s2[i+j], s1[j]);
		if(s2[i+j] == s1[j]) counter++;
		if(counter == sublen){
		    return 1;
}
}
	    counter = 0;
}    
}
    
    return 0;
}


int is_substring_mod(char s1[], char s2[]){
    int sublen = stringlen(s1);
    int strlen = stringlen(s2);
    int dif = strlen - sublen;
    int counter = 0;
    if(dif >= 0 ){
	for(int i = 0; i<= dif; i++){
	    if(s1[0] == s2[i]){
		for(int j = 1; j < sublen; j++){
		    printf("%c==%c\n", s2[i+j], s1[j]);
		    if(s1[j] == s2[i+j]){
			 counter++;
		    }else{
			 break;
		    }

		    if(counter == sublen-1){
			return 1;
}
}
		counter = 0;
}
}
}



    return 0;
}





int is_beginning(char s1[], char s2[]){
    int counter;
    int sublen = stringlen(s1);
    int dif =stringlen(s2)-sublen;
    if(dif >= 0){
	for(int i =0; i < sublen; i++){
	    if(s1[i] == s2[i]){
		continue;
	}
	    return 0;
}
}

    return 1;
}


int is_polindrome(char s[]){
    int strlen = stringlen(s);
    int temp = strlen-1;
    for(int i = 0; i < strlen/2+1; i++){
	printf("s[%d]==s[%d]\n", i, temp);
	if(s[i] == s[temp]){
	    temp--;
	    continue;
}
	return 0;
}
    return 1;
}



char* upcase(char s[]){
    int i = 0;
    char *newstr;
    int strlen = stringlen(s);
    newstr = (char*)malloc( strlen * sizeof(char)+1);
    while(s[i] != '\0'){
	if(s[i]>96 && s[i]< 123){
	    newstr[i] = s[i] - 32;
}
	else{
	    newstr[i]= s[i];
}
	i++;
}
    newstr[strlen]='\0';
    return newstr;
}



char* swap_case(char s[]){
    int i = 0;
    char *newstr;
    int strlen = stringlen(s);
    newstr = (char*)malloc( strlen * sizeof(char)+1);
    while(s[i] != '\0'){
	if(s[i]>96 && s[i]< 123){
	    newstr[i] = s[i] - 32;
}
	else if(s[i] > 64 && s[i]< 91){
	    newstr[i] = s[i] + 32;
}
	else{
	    newstr[i]= s[i];
}
	i++;
}
    newstr[strlen]='\0';
    return newstr;
}


char * reverse(char s[]){
    char*ns;
    int strlen = stringlen(s);
    int i = 0;
    ns = (char*)malloc(strlen*sizeof(char)+1);
    strlen = strlen-1;
    while(s[i] != '\0'){
    ns[i] = s[strlen-i];
    i++;
}
    ns[strlen+1]='\0';
    return ns;
}


char * dupstring(char s[], int n){
    char*ns;
    int i;
    int strlen = stringlen(s);
    ns = (char*)malloc(strlen*sizeof(char)*n+1);
    for(i = 0; i < strlen*n; i+=strlen ){
	for(int j = 0; j< strlen; j++){
	    ns[i+j] = s[j];
}
}
    ns[strlen*n]='\0';
    return ns;
}

char* appendl_char(char s[], char c){
    char * ns;
    int strlen = stringlen(s);
    ns = (char*)malloc(strlen*sizeof(char)+2);
    ns[0]= c;
    for(int i = 1; i < strlen+1;i++){
	ns[i] = s[i-1];
}
    ns[strlen+1]='\0';
    free(s);
    return ns;
}

char* appendr_char(char s[], char c){
//    char* ns;
    int strlen = stringlen(s);
//    ns = (char*)malloc(strlen*sizeof(char)+2);
    char* ns  = "adwwadw";
    //char ns[strlen+1]="hfhgfgh";
    for(int i = 0; i < strlen+1;i++){
	ns[i] = s[i];
}
    ns[strlen]= c;
    ns[strlen+1]='\0';
    return ns;
    // уничтожит ns
}

int str_to_int(char s[]){
//БЕЗ ВАЛИДАЦИИ
    int r = 0;
    int i = 0;
    int strlen = stringlen(s)-1;
    while(s[i] != '\0'){
	r += (s[i]-48)*((int)pow( 10, strlen-i));
    i++;
}
    return r;
}

char * strcopy(char s[]){
    int len =stringlen(s);
    int i = 0;
    char * ns = (char*) malloc(len*sizeof(char)+1);
    while(s[i]!='\0'){
    ns[i] = s[i];
    i++;
}
    ns[len] = '\0';
    return ns;
}


char* int_to_str2(int n){
//    char* str ="";
    char* str = strcopy("");
    int i = 0;
    while(n/(int)pow(10, i) != 0){
        i++;
	char* temp = str;
    	str = appendl_char(str, n%(int)pow(10,i)/pow(10,i-1)+48 );
//	free(temp);
//  caller делает free - избегает лишних копирований
//  callee (внутри append_l) делает free - простой, лишние копирования
        //i++;
}
//    for(int i = 1; i<=3; i++){
//	str[counter-i]= n%(int)pow(10,i)/pow(10, i-1)+48;    
//	str = appendl_char(str, n%(int)pow(10,i)/pow(10,i-1)+48 );
//    }
    return str;
}

char* int_to_str(int n){
    int counter = 0;
    char* str;
    while(n/(int)pow(10,counter)!= 0){
	counter++;
}
    str = (char*)malloc(counter*sizeof(char)+1);
    str[counter] = '\0';
    for(int i = 1; i<=counter; i++){
	str[counter-i]= n%(int)pow(10,i)/pow(10, i-1)+48;    
}

    return str;
}

char* add1(char s1[], char s2[]){
    int str1len = stringlen(s1);
    char* r;
    r = (char*)malloc(str1len*sizeof(char)+1);
    for(int i =1; i <= str1len;i++){
	r[str1len-i] =(char)(s1[0]-48)+(s2[0]-48)+48;
}

    return r;
}

char* add2(char s1[], char s2[]){
    int str1len = stringlen(s1);
    int str2len = stringlen(s2);
    int reallen;
    int end1 =str1len-1;
    int end2 =str2len-1;
    int end3;
    char* r;
    int sum = 0;
    int flag = 0;

    //allocating memory for based on biggest string
    if(str1len > str2len){
	r = (char*)malloc(str1len*sizeof(char)+2);
	reallen = str1len+2;
	r[reallen-1] = '\0';
	end3 = reallen-2;
	
    }else{
	r = (char*)malloc(str2len*sizeof(char)+2);
	reallen= str2len +2;
	r[reallen-1] = '\0';
	end3 = reallen-2;
    }

	for(int i = reallen-2; i >= 0; i--){
	    if(end1 >= 0)sum+= s1[end1]-48;
	    if(end2 >= 0)sum+= s2[end2]-48;
	    if(flag > 0)sum++;
	    r[i] =(char)sum%10+48;
	    if(sum/10 > 0){
		flag = 1;
	    }else{
		flag = 0;
	    }
	    end1--;
	    end2--;
	    sum = 0;
	}
    if(r[0]<49||r[0]>57){
	for(int i = 0; i< reallen-1; i++){
	    r[i]= r[i+1];
	}
	r = realloc(r, reallen-1);
    }
    return r;
}

char* multiply(char s1[], char s2[]){
    char* r;
    
    return r;
}

//char* add2(char s1[], char s2[]){


//}


int isSorted(int ar[], int len){
    for(int i = 1; i < len; i++){
        if(ar[i-1]> ar[i]){
	    return 0;
        }
    }
    return 1;
}

void bubbleSort(int s[], int len){
    int temp;
    while(isSorted(s, len) == 0){
        for(int i =1; i < len;i++){
    	    if(s[i-1]>s[i]){
	    temp = s[i-1];
	    s[i-1]=s[i];
	    s[i]=temp;
	    }
	}
    }
}

void printArray(int s[], int len){
    for(int i =0; i< len; i++ ){
	    printf("%d", s[i]);
    }
}



char* multonechar(char* s, char c, int lens){
    char* ns;
    int cval = c-48;
    ns = (char*)malloc(lens*sizeof(char)+2);
    ns[lens+1] = '\0';
    int carry= 0;
    int prod = 0;
    int end = lens -1;
    for(int i = 0; i < lens+1; i++){
	if(end>=0)prod = cval*(s[end]-48);
	prod+=carry;
	ns[lens-i]= (prod%10)+48;
	carry = prod/10;
	prod=0;
	end--;
    }

    if(ns[0]<49||ns[0]>57){
	for(int j = 0; j<lens+1; j++){
	    ns[j]= ns[j+1];
	}
	ns = realloc(ns, lens);
    }

    return ns;
}


char* multonten(char* s, int n){
    char* ns;
    int len = stringlen(s);
    ns = (char*)malloc(len*sizeof(char)+n+1);
    ns[len+n]='\0';
    for(int i =0; i< len+n; i++){
	if(i<len)ns[i]=s[i];
	if(i>=len)ns[i]='0';
    }
    return ns;
}

char* mult(char s1[], char s2[]){
    char* ns ="0";
    int lens1 = stringlen(s1);
    int lens2 = stringlen(s2);
    for(int i = 0; i< lens1; i++){
	ns = add2(multonten(multonechar(s2, s1[lens1-1-i], lens2) , i),ns);
    }

    return ns;
}


struct list* addlist(struct list* start, char* value){
    struct list* nm;
    struct list* end;
    while(start!=NULL){
	if(start->link==NULL)end = start;
	start = start->link;
    }
    nm = (struct list*) malloc(sizeof(struct list));
    nm->word = value;
    nm->link = NULL;
    end->link = nm;
    return start;
}

struct list* addlist2(struct list* start, char* value){
    struct list* newmember;
    newmember = (struct list*)malloc(sizeof(struct list));
    newmember->word = value;
    newmember->link = start;
    return newmember;
}

void printlist(struct list* list){
    while(list!=NULL){
	printf("%s\n", list->word);
	list = list->link;
    }

}

char* copytilspace(char* s, int start){
    int counter = 0;
    int i = start;
    while((s[i] != ' ')&&(s[i] != '\0') ){
	counter++;
	i++;
    }
    char* ns;
    ns = (char*)malloc(counter*sizeof(char)+1);
    ns[counter]='\0';
    i = start;
    for(int j = 0; j < counter; j++){
	ns[j] = s[start+j];
    }
    return ns;
}

struct list* split(char* s){
    int i =-1;
    int start = 0;
    struct list* list = NULL;
    struct list* temp;
    do{
	i++;
	if(s[i]==' '|| s[i] == '\0'){
	    list = addlist2(list, copytilspace(s, start));
	    start = i+1;
	}
	
	}while(s[i] != '\0');
	temp = swaplist(list);
	freelist(list);
    return temp;
}

struct list* swaplist(struct list* list){
    struct list* nl =NULL;
    while(list!=NULL){
	nl = addlist2(nl, list->word);
	list = list->link;
    }
    return nl;
}

void freelist(struct list* list){
    struct list* temp = list;
    while(list != NULL){
	list = list->link;
	if(list->link == NULL){
	    free(list);
	    list = NULL;
	}else{
	    free(temp);
	temp = list;
	}
    }
    free(list);
}



char* compare(char* s1, char* s2){
    int len1 = stringlen(s1);
    int len2 = stringlen(s2);
    if(len1> len2)return s1;
    if(len2> len1)return s2;
    for(int i = 0; i<len1; i++){
	if(s1[i]>s2[i])return s1;
	if(s2[i]>s1[i])return s2;
    }
    return "equal";
}

int main(){

    printf("%s", compare("1923", "1099"));
    return 0;
}
