
CC=clang++
CFLAGS=-std=c++23 -g -Wall -Werror -Wextra

BUILDDIR=build

all: ${BUILDDIR} ${BUILDDIR}/demo ${BUILDDIR}/bubble_sort

${BUILDDIR}:
	mkdir $@

${BUILDDIR}/demo: ${BUILDDIR}/demo.o
	${CC} ${CFLAGS} ${LDFLAGS} $< -o $@

${BUILDDIR}/demo.o: demo.cc nm_pairs.hh
	${CC} ${CFLAGS} -c $< -o $@

${BUILDDIR}/bubble_sort: ${BUILDDIR}/bubble_sort.o
	${CC} ${CFLAGS} ${LDFLAGS} $< -o $@

${BUILDDIR}/bubble_sort.o: bubble_sort.cc nm_pairs.hh
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ./${BUILDDIR}/*
