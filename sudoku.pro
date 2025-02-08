OBJDIR = build

DESTDIR = bin
MOC_DIR = build

TEMPLATE = app
TARGET = SUDOKU_MULTITHREAD
QT += widgets
INCLUDEPATH += inc
SOURCES += src/Main.cpp \
           src/Solve.cpp \
           src/Sudoku.cpp \
           src/SudokuSet.cpp \
           src/MyWindow.cpp
HEADERS+= inc/Solve.h \
          inc/Sudoku.h \
          inc/SudokuSet.h \
          inc/MyWindow.h

OBJECTS_DIR = $$OBJDIR
