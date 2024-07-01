#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int auxL = 0;
int get_string(char*);
int main(){
	char* p = (char *) malloc(MAX_LEN*sizeof(char));
  List *history = init_history();
	while(1){
    auxL = 0;
		int length;
		printf("\n\nWelcome to the tokenizer app (If you like to exit enter \"q\", if you like to see the history enter \"h\", if you like to access an item of the history enter \"!\" followed by the history number, otherwhise just  enter a word\n\n");
		putchar('>');
		length = get_string(p);
		if(p[0] == 'q' && length < 2){
			//Quit
			break;

		}else if(p[0]=='h' && length < 2){

		      //Call History
        print_history(history);

		}else if(p[0] == '!'){
      p[0] = ' ';
      int id = atoi(p);
      char* str = get_history(history, id);
      if(str == NULL){
        printf("Invalid history ID.\n\n");
      }else{
        char** tokens = tokenize(str);
        print_tokens(tokens);
        free_tokens(tokens);
      }

		}else{
			//Tokenize
      if(auxL-1<1) continue;
      char* str = copy_str(p, length+1);
      add_history(history, str);
      char** tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
      length = 0;
      auxL = 0;
		}

	}
  free(history);
	printf("Take care!");
	return 0;
}


int get_string(char* p){

	char curr;
	int i = 0;
	while(i<MAX_LEN){
		curr = getchar();
    if(curr != ' ' && curr != '\t') auxL++;
		if(curr==END_STR){
	 		p[i] = '\0';
			goto Terminate;
		}
		p[i++] = curr;

	}
	Terminate:
	 return i;

}
