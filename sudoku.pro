OBJDIR = build

DESTDIR = bin

TEMPLATE = app
TARGET = SUDOKU_MULTITHREAD

INCLUDEPATH += inc
SOURCES += src/Main.cpp \
           src/Solve.cpp \
           src/Sudoku.cpp \
           src/SudokuSet.cpp
HEADERS+= inc/Solve.h \
          inc/Sudoku.h \
          inc/SudokuSet.h

OBJECTS_DIR = $$OBJDIR
