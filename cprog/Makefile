SRCDIR := src
BUILDDIR := build
BINDIR := bin

SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CC := gcc
CCFLAGS := -g -Wall -std=c99
LIB := -L lib
INC := -I include

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR)
	$(CC) $(CCFLAGS) $(INC) -c -o $@ $<

$(BINDIR)/stack_example: $(BUILDDIR)/stack.o $(BUILDDIR)/stack_example.o $(BUILDDIR)/linked_list.o
	mkdir -p $(BINDIR)
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	$(RM) -r $(BUILDDIR) $(BINDIR)
