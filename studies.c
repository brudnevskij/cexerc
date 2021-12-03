#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    for(int i = 0; i < strlen; i++){
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
    return ns;
}

char* appendr_char(char s[], char c){
    char* ns;
    int strlen = stringlen(s);
    ns = (char*)malloc(strlen*sizeof(char)+2);

    for(int i = 0; i < strlen+1;i++){
	ns[i] = s[i];
}
    ns[strlen]= c;
    ns[strlen+1]='\0';
    return ns;
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

int main(){

//    printf("%d",is_beginning("sss", "sssas"));
//    printf("%d",is_beginning("sss", "sss"));
//    printf("%d",is_beginning("sss", "ssasa"));
    printf("aaasass %s\n", upcase("aaasass"));
    printf("asasab %s\n", swap_case("asasab"));
    printf("aaa %s\n", dupstring("aaa", 3));
    printf("laaa1233AAA15 %s %d\n", appendr_char("aaa1233AAA15",'l'),(int)pow(10, 2) );
    printf("%d %d", str_to_int("696969"), '1');
    return 0;
}