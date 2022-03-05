CC=gcc

OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
	OPEN=xdg-open
else
	LIBS=shell brew config | grep HOMEBREW_PREFIX | cut -d' ' -f2-/include/Cellar/Chek/0-15-2/libs
	OPEN=open
endif


all: 
	make clean
	make s21_string.a
	make test

s21_string.a:
	$(CC) -c s21_string.c -o s21_string.o
	$(CC) -c s21_sprintf.c -o s21_sprintf.o
	$(CC) -c s21_sscanf.c -o s21_sscanf.o
	ar rcs libs21_string.a s21_string.o s21_sprintf.o s21_sscanf.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.a

test: 
	make s21_string.a
	$(CC) -o s21_string_test.out s21_string_test.c -L. -ls21_string -lcheck
	make run

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report

rebuild:
	make clean
	make all

run:
	./s21_string_test.out

code_check:                                    
	@echo ================CPPCHECK_TEST=================
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	@echo ==============================================

code_style:
	@echo =================CPPLINT_TEST=================
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	@echo ==============================================

debug:
	$(CC) -o s21_string_test_debug.out -g s21_string_test.c s21_string.c -lcheck

gcov_report:
	$(CC) -o s21_string_test.out --coverage s21_string_test.c s21_string.c s21_sprintf.c s21_sscanf.c -lcheck
	make run
	lcov -t "s21_string_test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN) ./report/index.html

leaks: 
	make test
	CK_FORK=no leaks --atExit -- ./s21_string_test.out
	make clean

	
