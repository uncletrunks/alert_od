CROSS_COMPILE = /opt/gcw0-toolchain/bin/mipsel-gcw0-linux-uclibc-
SDL_BASE = /opt/gcw0-toolchain/mipsel-gcw0-linux-uclibc/sysroot/usr/bin/

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)ld
STRIP = $(CROSS_COMPILE)strip
PKG-CONFIG = /opt/gcw0-toolchain/mipsel-linux-uclibc/usr/bin/pkg-config

LDFLAGS = --verbose
CFLAGS = `$(SDL_BASE)sdl-config --cflags` -O2 -Wall -DGP2X
CXXFLAGS = `$(SDL_BASE)sdl-config --cflags` -O2 -Wall -DGP2X
LIBS = `$(SDL_BASE)sdl-config --libs`  -L/opt/gcw0-toolchain/mipsel-gcw0-linux-uclibc/sysroot/usr/lib -lSDL_gfx -lSDL_ttf -lfreetype  -lSDL_image -ljpeg -lz -lSDL_mixer -lvorbisidec -lmikmod -lSDL -lgcc -lm -lc -lpthread -ldl

SOURCE_TARGET = ../dist/alert
SOURCE_OBJS = main.o font.o file.o dconv.o block.o title.o piecekn.o work.o act_main.o act_bg.o act_effect.o act_ship.o act_enemy.o util_act.o util_ascii.o util_grp.o util_sdl.o util_snd.o util_pad.o

all : $(SOURCE_TARGET)

$(SOURCE_TARGET) : $(SOURCE_OBJS)
	$(CXX) $(LDFLAGS) -o $(SOURCE_TARGET) $(SOURCE_OBJS) $(LIBS)
	$(STRIP) $(SOURCE_TARGET)

clean:
	rm -f $(ALL_TARGETS) *.o *~
