#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

int space_char(char c){

	return (c == '\t' || c == ' ');

}
int non_space_char(char c){

	return (c!='\t' && c!= ' ' && c!= '\n' && c!='\0');

}

char *token_start(char *str){

	char* p_tmp = str;
	char start = *p_tmp;
	int size = sizeof(str);
	while(space_char(start)){

		p_tmp++;
	        start = *p_tmp;

	}

	return p_tmp;

}

char *token_terminator(char *token){

	char *terminator = token;
	while(non_space_char(*terminator)){

		terminator++;

	}
	return terminator;

}

int count_tokens(char *str){
        char *tmp = str;
	int count = 1;
	while(*tmp!='\0'){

		if(space_char(*tmp)) count++;

		tmp++;

	}
	return count;

}

char *copy_str(char *inStr, short len){
	char *str = (char*)calloc(len+1, sizeof(char));
	int i = 0;
	for(;i<len;i++){
		str[i] = inStr[i];
        if(inStr[i] == '\0'){
            return str;
        }
	}
	return str;

}


char **tokenize(char *str){
	int num_tokens = count_tokens(str);
	char **tokens = (char**)calloc((num_tokens+1)*sizeof(char*), 1);
	char* start;
    char* end;
    for(int i = 0; i<num_tokens; i++){
       start = token_start(str);
       str = token_terminator(start);
        tokens[i] = copy_str(start, str-start);
        if(tokens[i] == NULL){
            return tokens;
        }
	}
    return tokens;
}

void print_tokens(char **tokens){

    int i = 0;
    while(tokens[i] != NULL){

        printf("%s\n", tokens[i]);
        i++;

    }

}

void free_tokens(char** tokens){

    int i = 0;
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);

}
