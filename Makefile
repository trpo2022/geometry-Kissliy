CFLAGS = -Wall -Wextra -Werror

all: geometry

geometry: bin/geometry

bin/geometry: obj/src/geometry/geometry.o obj/src/libgeo/libgeo.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/geometry/geometry.o: src/geometry/geometry.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/libgeo.a: obj/src/libgeo/circle.o obj/src/libgeo/triangle.o 
	ar rcs $@ $^


obj/src/libgeo/circle.o: src/libgeo/circle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/triangle.o: src/libgeo/triangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

	
	

.PHONY: clean

clean:
	rm obj/src/libgeo/*.a obj/src/libgeo/*.o obj/src/geometry/*.o bin/geometry
