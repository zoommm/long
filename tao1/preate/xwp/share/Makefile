CFLAG = -Wall -c -I ./include
LDFLAG= -L ./lib -lstack
target= app
# src = a.c b.c c.c
# wildcard is find all .c de file;
src   =$(wildcard *.c)
# obj = find and ti huan cha zhao ba src zhong de .c ti huan cheng .o file;
# obj = a.o b.o c.o
CC    = gcc
obj   =$(patsubst %.c,%.o,$(src))

all:$(obj)
	$(CC) $(obj) $(LDFLAG) -o $(target)
#$@: biao shi  mu biao file,
#$<: biao shi yi lai dang zhong fist file;
%.o:%.c
	$(CC) $(CFLAG) -o $@ $<
.PHONY:clean
clean:
	rm -rf *.o
	rm -rf *.so
