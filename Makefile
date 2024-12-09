UNAME_S = $(shell uname -s)

CC = clang
CFLAGS = -std=c11 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS += -Ilib/cglm/include -Ilib/glad/include -Ilib/glfw/include
CFLAGS += -Ilib/openal-soft/include -Ilib/openal-soft/build -Ilib/astera/include -I-fbracket-depth=1024
LDFLAGS = lib/glad/src/glad.o lib/cglm/libcglm.a lib/glfw/src/libglfw3.a 
LDFLAGS += lib/openal-soft/build/libalsoft.common.a lib/openal-soft/build/libalsoft.excommon.a -lm 

# GLFW required frameworks on Linux
LDFLAGS += -ldl -lpthread


SRC  = $(wildcard src/**/*.c) $(wildcard src/*.c) $(wildcard src/**/**/*.c) $(wildcard src/**/**/**/*.c)
OBJ  = $(SRC:.c=.o)
BIN = bin

.PHONY: all clean

all: dirs libs game

libs:
	cd lib/cglm && cmake -S . -B . -DCGLM_STATIC=ON && make
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/gl.c
	cd lib/glfw && cmake -S . -B . && make
	cd lib/openal-soft/build && cmake .. && cmake --build .
#	cd lib/astera && cmake -DLIBTYPE=STATIC -Bbuild -S.
#	cmake --build build

dirs:
	mkdir -p ./$(BIN)

run: all
	$(BIN)/game

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS) -v

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)