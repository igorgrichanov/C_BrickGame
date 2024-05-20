CC=gcc -std=c11
CFLAGS=-Wall -Wextra -Werror
FLAG_COV=--coverage -fprofile-arcs -ftest-coverage
FUNC_TESTS_C=tests/*_test.c
VALGRIND_FLAGS=--tool=memcheck --track-origins=yes
NCURSES=-lncurses
DOCS_FOLDER=doxygen
CLI=gui/cli/*.c

SOURCES=model/*.c

OS=$(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm -lrt
else
	TEST_LIBS=`pkg-config --cflags --libs check` -lm
endif

.PHONY: all install uninstall dvi dist test gcov_report format valgrind clean

all: clean install

install: clean
	mkdir build
	touch build/tetris_record.txt
	$(CC) $(CFLAGS) main.c $(CLI) $(SOURCES) -o build/tetris $(NCURSES)

uninstall:
	rm -rf build/

dvi:
	@doxygen
	@open $(DOCS_FOLDER)/html/index.html

dist: clean
	mkdir -p dist
	tar -czvf tetris.tar Makefile Doxyfile ./model/* ./gui/cli/* ../README.md ./tests/* main.c
	mv tetris.tar dist/

test: clean
	mkdir build
	touch build/tetris_record.txt
	$(CC) $(CFLAGS) -o test tests/main.c $(FUNC_TESTS_C) $(SOURCES) $(FLAG_COV) $(TEST_LIBS)
	./test

gcov_report: test
	lcov -c -d . -o gcov.info
	genhtml gcov.info -o gcov_report
	open gcov_report/index.html

format:
	@clang-format -i $(FUNC_TESTS_C) tests/*.h $(SOURCES) model/*.h gui/cli/*.h $(CLI) main.c
	@clang-format -n $(FUNC_TESTS_C) tests/*.h $(SOURCES) model/*.h gui/cli/*.h $(CLI) main.c

valgrind: clean
	$(CC) $(CFLAGS) -o tetris ../tests/main.c $(FUNC_TESTS_C) -g -O0 $(SOURCES) $(TEST_LIBS)
	valgrind $(VALGRIND_FLAGS) ./tetris

clean: uninstall
	rm -rf gcov_report/ doxygen/ dist/
	rm -f *.info test
	rm -f *.gcda *.gcno *.gcov *.o *.a *.out