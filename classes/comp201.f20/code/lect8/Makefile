# A simple makefile for building a program composed of C source files.
# Refer to CS107 guide to Make for background info on makefiles

PROGRAMS = diamond verify_password

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -g3 -O0 -std=gnu99 -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wshadow -Winit-self -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean::
	rm -f $(PROGRAMS) *.o

.PHONY: clean all
