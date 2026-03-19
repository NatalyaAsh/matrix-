TARGET_A = s21_matrix.a
TARGET_C = internal/funcs/*.c

.PHONY: all test $(TARGET_A) clang clean cppcheck rebuild

FLAG_GCC = -Wall -Wextra -Werror -std=gnu11
FLAG_TEST = -fprofile-arcs -ftest-coverage -pedantic -std=gnu11
OS=$(shell uname -s)
LINUX=-lsubunit -lrt
LIBS=-lcheck -lm -lpthread

ifeq ($(OS), Linux)
	OPEN = xdg-open
	LIB = $(LIBS) $(LINUX)
else
	OPEN = open
	LIB = $(LIBS)
endif

all: clean $(TARGET_A)

test: clean $(TARGET_A)
	gcc $(FLAG_GCC) $(FLAG_TEST) -g tests/*.c $(TARGET_A) -o unit_test $(LIB) 
	./unit_test
 

gcov_report: clean s21_matrix.a
	gcc $(FLAG_GCC) $(FLAG_TEST) -g $(TARGET_C) tests/*.c $(TARGET_A) -o unit_test $(LIB) 
	./unit_test
	lcov -t "unit_test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN) report/index.html

$(TARGET_A):
	gcc -c $(TARGET_C)
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

clean_obj:
	rm -rf *.o

clean_lib:
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.dSYM

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test

rebuild: clean all

clang:
	clang-format -i $(TARGET_C)
	clang-format -i tests/*.c
	clang-format -i s21_matrix.h

cppcheck:
	cppcheck --enable=all --suppress=missingSystemInclude $(TARGET_C)

leaks: test
ifeq ($(OS), Linux)
	valgrind --tool=memcheck --leak-check=yes ./unit_test
else
	leaks -atExit -- ./unit_test
endif

miniverter:
	@bash ../materials/build/run.sh