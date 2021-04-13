all:bin/main

bin/main: obj/src/main.o obj/lib/geometrylib.a
	gcc obj/src/main.o -Wall -Werror -L. obj/lib/geometrylib.a -o $@

obj/src/main.o:src/main.cpp
	gcc -c src/main.cpp -Wall -Werror -o $@

obj/src/wkt_check.o:src/lib/wkt_check.c
	gcc -c src/lib/wkt_check.c -Wall -Werror -o $@

obj/src/point_check.o:src/lib/point_check.c
	gcc -c src/lib/point_check.c -Wall -Werror -o $@

obj/lib/geometrylib.a: obj/src/wkt_check.o obj/src/point_check.o
	ar rcs $@ $^

run:
	./bin/main

clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "main" -exec rm {} \;

.PHONY: clean run all