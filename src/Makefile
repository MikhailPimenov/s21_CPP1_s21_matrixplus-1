CC = g++
# STRICT_CFLAGC = -Wall
STRICT_CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic
STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -Werror

# GCOVR_CFLAGS=$(shell pkg-config --cflags gcovr)
GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC

all: build

#TODO
# s21_matrix_oop.a:
s21_matrix_oop.a: s21_matrix_oop.oa 
		ar rcs $@ $^

#TODO
test:

s21_matrix_oop.o: s21_matrix_oop.cpp s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@

s21_transpose.o: s21_transpose.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

s21_matrix_oop.oa: s21_matrix_oop.cpp s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@


# s21_create_matrix.oa: s21_create_matrix.c s21_matrix.h
# 		$(CC) -c $(STRICT_CFLAGS) $< -o $@


clean:
		rm -rf *.o *.exe *.out *.oa
		rm -rf tests/*.o tests/*.exe tests/*.out