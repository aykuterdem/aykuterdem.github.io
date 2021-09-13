#
# A simple makefile for building project composed of C source files.
#
# Julie Zelenski, for CS107, Sept 2014
#

# It is likely that default C compiler is already gcc, but be explicit anyway
CC = gcc

# The CFLAGS variable sets the flags for the compiler.  CS107 adds these flags:
#  -g          compile with debug information
#  -O0         do not optimize generated code
#  -std=gnu99  use the C99 standard language definition with GNU extensions
#  -Wall       turn on optional warnings (warnflags configures specific diagnostic warnings)
CFLAGS = -g3 -std=gnu99 -Wall $$warnflags -fno-stack-protector
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -fno-diagnostics-show-option -Winit-self

# The LDFLAGS variable sets flags for the linker and the LDLIBS variable lists
# additional libraries being linked. The standard libc is linked by default.
LDFLAGS = -include assert.h -include limits.h -include math.h -include stdbool.h
LDLIBS = -lm

# The line below defines the variable 'PROGRAMS' to name all of the executables
# to be built by this makefile
PROGRAMS = constant_folding subexp dead_code strength limitations mult
OPT_PROGRAMS = $(PROGRAMS:%=%_opt)
CACHE_PROGRAMS = cache

# The line below defines a target named 'all', configured to trigger the
# build of everything named in the 'PROGRAMS' variable. The first target
# defined in the makefile becomes the default target. When make is invoked
# without any arguments, it builds the default target.
all: $(PROGRAMS) $(OPT_PROGRAMS) $(CACHE_PROGRAMS)

# The entry below is a pattern rule. It defines the general recipe to make
# the 'name.o' object file by compiling the 'name.c' source file.
%.o: %.c
	$(COMPILE.c) $< -o $@

# This pattern rule defines the general recipe to make the executable 'name'
# by linking the 'name.o' object file and any other .o prerequisites. The
# rule is used for all executables listed in the PROGRAMS definition above.

fcyc.o : fcyc.c
	$(CC) -O2 $(CFLAGS) -c $(LDFLAGS) $^ $(LDLIBS) -o $@


$(PROGRAMS): %:%.o fcyc.o
	$(LINK.o) $(filter %.o,$^) $(LDLIBS) -o $@
$(OPT_PROGRAMS): %:%.o fcyc.o 
	$(LINK.o) $(filter %.o,$^) $(LDLIBS) -o $@
$(CACHE_PROGRAMS): %:%.o fcyc.o
	$(LINK.o) $(filter %.o,$^) $(LDLIBS) -o $@

%:
	$(error No rule to make target '$@')

# Specific per-target customizations and prerequisites can be listed here

%_opt.o: %.c
	$(COMPILE.c) $< -o $@
.INTERMEDIATE: $(OPT_PROGRAMS:%=%.o)

$(PROGRAMS) $(OPT_PROGRAMS): 

$(PROGRAMS): CFLAGS += -O0 -fno-builtin
$(CACHE_PROGRAMS): CFLAGS += -O2
$(OPT_PROGRAMS): CFLAGS += -O2



# The line below defines the clean target to remove any previous build results
clean::
	rm -f $(PROGRAMS) $(OPT_PROGRAMS) $(CACHE_PROGRAMS) core *.o callgrind.out.* cachegrind.out.* a.out

spartan:: clean
	rm -f *~

# PHONY is used to mark targets that don't represent actual files/build products
.PHONY: spartan clean all
