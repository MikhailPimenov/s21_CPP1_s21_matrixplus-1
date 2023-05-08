CC=g++
# STRICT_CFLAGC = -Wall
STRICT_CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic
STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -Werror


# GCOVR_CFLAGS=$(shell pkg-config --cflags gcovr)
# GCOVR_CFLAGS=$(shell pkg-config --libs gcovr)
GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_LFLAGS=-lgcov


# GTEST_CFLAGS=$(shell pkg-config --cflags gtest)
# GTEST_LFLAGS=$(shell pkg-config --libs gtest)
GTEST_LFLAGS=-lgtest -lgtest_main

REPORT_DIRECTORY=report


all: build

#TODO
# s21_matrix_oop.a:
s21_matrix_oop.a: s21_matrix_oop.oa 
		ar rcs $@ $^

tests/tests_constructor_assignment.o: tests/tests_constructor_assignment.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_getset.o: tests/tests_getset.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_brace.o: tests/tests_brace.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_multiply.o: tests/tests_multiply.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_subtract.o: tests/tests_subtract.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_sum.o: tests/tests_sum.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_inverse.o: tests/tests_inverse.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_calc_complements.o: tests/tests_calc_complements.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_determinant.o: tests/tests_determinant.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_sum_subscript.o: tests/tests_sum_subscript.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_subtract_subscript.o: tests/tests_subtract_subscript.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_multiply_subscript.o: tests/tests_multiply_subscript.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_equal.o: tests/tests_equal.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/tests_transpose.o: tests/tests_transpose.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)

tests/tests_main.o: tests/tests_main.cpp s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)

#TODO
test: tests/tests_main.exe
		./tests/tests_main.exe

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY)/coverage_report.html
		START "" $(REPORT_DIRECTORY)/coverage_report.functions.html  
# open $(REPORT_DIRECTORY)/coverage_report.functions.html


tests/tests_main.exe: s21_matrix_oop.o tests/tests_main.o tests/tests_sum_subscript.o tests/tests_subtract_subscript.o tests/tests_multiply_subscript.o tests/tests_equal.o tests/tests_transpose.o tests/tests_determinant.o tests/tests_calc_complements.o tests/tests_inverse.o tests/tests_sum.o tests/tests_subtract.o tests/tests_multiply.o tests/tests_brace.o tests/tests_getset.o tests/tests_constructor_assignment.o
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS)
		

s21_matrix_oop.o: s21_matrix_oop.cpp s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

s21_transpose.o: s21_transpose.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

s21_matrix_oop.oa: s21_matrix_oop.cpp s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@


# s21_create_matrix.oa: s21_create_matrix.c s21_matrix.h
# 		$(CC) -c $(STRICT_CFLAGS) $< -o $@


clean:
		rm -rf *.o *.exe *.out *.oa
		rm -rf tests/*.o tests/*.exe tests/*.out
		rm -rf *.gcno *.gcda