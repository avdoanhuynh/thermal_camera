#############################################################################
# Makefile for building: Thermal_Camera_App
# Generated by qmake (2.01a) (Qt 4.8.7) on: Thu Apr 30 23:39:58 2020
# Project:  ../Thermal_Camera_App/Thermal_Camera_App.pro
# Template: app
# Command: /usr/lib/arm-linux-gnueabihf/qt4/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile ../Thermal_Camera_App/Thermal_Camera_App.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I../Thermal_Camera_App -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I../MLX90640_API -I`pkg-config -I--cflags -Iopencv` -I. -I. -I../Thermal_Camera_App -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/arm-linux-gnueabihf -L/home/pi/Desktop/Thermal_Camera/build-Thermal_Camera_App-Desktop-Debug/../MLX90640_API/ -lMLX90640_API `pkg-config --libs opencv` -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/arm-linux-gnueabihf/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../Thermal_Camera_App/main.cpp \
		../Thermal_Camera_App/window.cpp \
		../Thermal_Camera_App/fb.c \
		../Thermal_Camera_App/interpolate.c moc_window.cpp
OBJECTS       = main.o \
		window.o \
		fb.o \
		interpolate.o \
		moc_window.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		../Thermal_Camera_App/Thermal_Camera_App.pro
QMAKE_TARGET  = Thermal_Camera_App
DESTDIR       = 
TARGET        = Thermal_Camera_App

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): /home/pi/Desktop/Thermal_Camera/build-Thermal_Camera_App-Desktop-Debug/../MLX90640_API/libMLX90640_API.a ui_window.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: ../Thermal_Camera_App/Thermal_Camera_App.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/arm-linux-gnueabihf/libQtGui.prl \
		/usr/lib/arm-linux-gnueabihf/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile ../Thermal_Camera_App/Thermal_Camera_App.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/arm-linux-gnueabihf/libQtGui.prl:
/usr/lib/arm-linux-gnueabihf/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile ../Thermal_Camera_App/Thermal_Camera_App.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Thermal_Camera_App1.0.0 || $(MKDIR) .tmp/Thermal_Camera_App1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Thermal_Camera_App1.0.0/ && $(COPY_FILE) --parents ../Thermal_Camera_App/window.h ../Thermal_Camera_App/fb.h ../Thermal_Camera_App/interpolate.h .tmp/Thermal_Camera_App1.0.0/ && $(COPY_FILE) --parents ../Thermal_Camera_App/main.cpp ../Thermal_Camera_App/window.cpp ../Thermal_Camera_App/fb.c ../Thermal_Camera_App/interpolate.c .tmp/Thermal_Camera_App1.0.0/ && $(COPY_FILE) --parents ../Thermal_Camera_App/window.ui .tmp/Thermal_Camera_App1.0.0/ && (cd `dirname .tmp/Thermal_Camera_App1.0.0` && $(TAR) Thermal_Camera_App1.0.0.tar Thermal_Camera_App1.0.0 && $(COMPRESS) Thermal_Camera_App1.0.0.tar) && $(MOVE) `dirname .tmp/Thermal_Camera_App1.0.0`/Thermal_Camera_App1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Thermal_Camera_App1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_window.cpp
moc_window.cpp: ../Thermal_Camera_App/window.h
	/usr/lib/arm-linux-gnueabihf/qt4/bin/moc $(DEFINES) $(INCPATH) ../Thermal_Camera_App/window.h -o moc_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_window.h
compiler_uic_clean:
	-$(DEL_FILE) ui_window.h
ui_window.h: ../Thermal_Camera_App/window.ui
	/usr/lib/arm-linux-gnueabihf/qt4/bin/uic ../Thermal_Camera_App/window.ui -o ui_window.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ../Thermal_Camera_App/main.cpp ../Thermal_Camera_App/window.h \
		../MLX90640_API/MLX90640_API.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../Thermal_Camera_App/main.cpp

window.o: ../Thermal_Camera_App/window.cpp ../Thermal_Camera_App/window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o window.o ../Thermal_Camera_App/window.cpp

fb.o: ../Thermal_Camera_App/fb.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o fb.o ../Thermal_Camera_App/fb.c

interpolate.o: ../Thermal_Camera_App/interpolate.c ../Thermal_Camera_App/interpolate.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o interpolate.o ../Thermal_Camera_App/interpolate.c

moc_window.o: moc_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_window.o moc_window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

