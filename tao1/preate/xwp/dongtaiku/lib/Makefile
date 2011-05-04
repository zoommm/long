all:is_empty.o pop.o push.o stack.o
	gcc is_empty.o pop.o push.o stack.o -shared -o libstack.so
is_empty.o:is_empty.c
	gcc is_empty.c -fPIC -c
pop.o:pop.c
	gcc pop.c -fPIC -c
push.o:push.c
	gcc push.c -fPIC -c
shack.o:stack.c
	gcc stack.c -fPIC -c
.PHONY:clean
clean:
	rm -rf *.o
	rm *.so
