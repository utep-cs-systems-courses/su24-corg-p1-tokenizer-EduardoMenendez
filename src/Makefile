OBJ= ui_main.o tokenizer_imp.o history_imp.o

CFLAGS=-g -O3

all: tokenizer

tokenizer: $(OBJ)
	cc -o tokenizer $(CFLAGS) $(OBJ) && rm -f *.o

$(OBJ): tokenizer.h history.h

clean: 
	rm -f *.o tokenizer

run:tokenizer
	clear && ./tokenizer
