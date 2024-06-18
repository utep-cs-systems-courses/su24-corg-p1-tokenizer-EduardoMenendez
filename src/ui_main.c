#include <stdio.h>

#define MAX_LEN  500
#define END_STR '\n'
int get_string(char*);
int main(){
	char word[MAX_LEN];
	char* p = word;
	while(1){
		int length;
		printf("\n\nWelcome to the tokenizer app (If you like to exit enter \"q\", if you like to see the history enter \"h\", if you like to access an item of the history enter \"!\" followed by the history number, otherwhise just  enter a word\n\n");
		putchar('>');
		length = get_string(p);
		if(p[0] == 'q' && length < 2){
			//Quit
			break;

		}else if(p[0]=='h' && length < 2){

		      //Call History
		      printf("Calling to history");

		}else if(p[0] == '!'){
		
		      //Bring History
		      printf("Bring history token");
		
		}else{
			//Tokenize
		       printf("%s", p);
		
		}

	}
	printf("Take care!");
	return 0;
}


int get_string(char* p){
	
	char curr;
	int i = 0;
	while(i<MAX_LEN){
		curr = getchar();
		if(curr==END_STR){
			goto Terminate;
		}
		p[i++] = curr;
		
	}
	Terminate:
	 return i;

}
