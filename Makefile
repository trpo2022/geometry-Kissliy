CFLAGS = -Wall -Wextra -Werror

all: main

main: bin/main

bin/main: obj/src/main/main.o obj/src/libmain/libmain.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/main/main.o: src/main/main.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/libmain.a: obj/src/libmain/circle.o obj/src/libmain/triangle.o 
	ar rcs $@ $^


obj/src/libmain/circle.o: src/libmain/circle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/triangle.o: src/libmain/triangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

	
.PHONY: clean

clean:
	rm obj/src/libmain/*.a obj/src/libmain/*.o obj/src/main/*.o bin/main
