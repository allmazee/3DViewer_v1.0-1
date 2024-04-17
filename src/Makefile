.PHONY: all clean tests install uninstall dvi dist gcov_report

CC=gcc 
CFLAGS = -Wall -Wextra -Werror -std=c11
GCOVFLAGS=-fprofile-arcs -ftest-coverage
# QMAKE = /Users/mac/QtFree/6.5.2/macos/bin/qmake 
QMAKE = qmake6  
C_FILES = *.c
O_FILES = *.o
TEST_FILE = Tests/tests.c
REPORT_FILE = report
OS = $(shell uname)

INST_DIR = build
DIST_DIR = dist
EXE_DIR = 3D_Viewer_1_0
TEST_DIR = Tests
REPORT_DIR = report

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
	EXE_FILE=3D_Viewer_1_0.app
else
	TEST_LIBS=-lcheck -lsubunit -pthread -lcheck_pic -lrt -lm
	EXE_FILE=3D_Viewer_1_0
endif

all: style install tests gcov_report dvi dist

install: uninstall clean
	mkdir -p $(INST_DIR)
	cd $(EXE_DIR) && \
	$(QMAKE) && \
	make && \
	mv $(EXE_FILE) ../$(INST_DIR)
	open $(INST_DIR)/3D_Viewer_1_0.app/Contents/MacOS/3D_Viewer_1_0

uninstall: 
	rm -rf $(INST_DIR)

clean:
	rm -rf Tests/tests.out
	rm -rf *.gcda *.gcno report *.info
	rm -rf *.out
	rm -rf *.h.gch
	rm -rf dvi_html $(DIST_DIR).tar
	rm -rf dvi
	rm -rf $(EXE_DIR)/$(EXE_FILE) $(EXE_DIR)/.qmake.stash
	rm -rf $(EXE_DIR)/*.o

dvi:
	makeinfo dvi.texi --html
	open ./dvi_html/index.html

dist:
	mkdir $(DIST_DIR)
	cp *.c *.h Makefile $(DIST_DIR)
	mkdir $(DIST_DIR)/$(EXE_DIR)
	cp $(EXE_DIR)/* $(DIST_DIR)/$(EXE_DIR)
	tar --totals -cvf $(DIST_DIR).tar $(DIST_DIR)
	rm -rf $(DIST_DIR)

tests: $(C_FILES) $(TEST_FILE)
	$(CC) $(CFLAGS) $^ -o $(TEST_DIR)/tests.out $(TEST_LIBS) $(GCOVFLAGS)
	./$(TEST_DIR)/tests.out

gcov_report: tests
	cd $(TEST_DIR)
	lcov -t "tests.out" -o 3D_Viewer_1_0.info -c -d .
	genhtml -o report/ 3D_Viewer_1_0.info
	open report/index.html

style:
	clang-format --verbose -style=Google -n *.c
	clang-format --verbose -style=Google -n *.h
	clang-format --verbose -style=Google -n 3D_Viewer_1_0/*.cpp
	clang-format --verbose -style=Google -n 3D_Viewer_1_0/*.h
	clang-format --verbose -style=Google -n Tests/*.c

lint:
	clang-format --verbose -style=Google -i *.c
	clang-format --verbose -style=Google -i *.h
	clang-format --verbose -style=Google -i 3D_Viewer_1_0/*.cpp
	clang-format --verbose -style=Google -i 3D_Viewer_1_0/*.h
	clang-format --verbose -style=Google -i Tests/*.c

3D_Viewer_1_0.a:
	$(CC) -c viewer.c affina.c Tests/tests.c viewer.h 
	ar rcs 3D_Viewer_1_0.a *.o
	ranlib 3D_Viewer_1_0.a

leaks: 
	CK_FORK=no leaks --atExit -- Tests/./tests.out