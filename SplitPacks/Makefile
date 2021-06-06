# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = setlocal enableextensions enabledelayedexpansion mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	OUTPUT_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	OUTPUT_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../Unity/

PROJ_NAME=splitpacks

CFLAGS=-std=c11
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

OUTPUT_BASE=bin/output

OUTPUT = $(OUTPUT_BASE)$(OUTPUT_EXTENSION)

SRC_FILES1=./src/main.c ./src/$(PROJ_NAME).c

INC_DIRS=-Isrc -Iinclude
SYMBOLS=

all: default

default: $(SRC_FILES1)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(OUTPUT)
	- $(OUTPUT)

clean:
	$(CLEANUP) bin/*.out bin/*.exe

ci: CFLAGS += -Werror
ci: default
