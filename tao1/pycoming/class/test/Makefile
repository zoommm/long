all:main.o test.o 
	gcc main.o test.o  -shared -o libstack.so
main.o:main.c
	gcc main.c -fPIC -c
test.o:test.c
	gcc test.c -fPIC -c
#push.o:push.c
#	gcc push.c -fPIC -c
#shack.o:stack.c
#	gcc stack.c -fPIC -c
.PHONY:clean
clean:
	rm -rf *.o
	rm *.so
