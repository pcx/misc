SRCDIR := src
BUILDDIR := build
BINDIR := bin

SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CC := gcc
CCFLAGS := -g -Wall -std=gnu99
LIB := -L lib
INC := -I include

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR) $(BUILDDIR)/bgnet
	$(CC) $(CCFLAGS) $(INC) -c -o $@ $<

$(BINDIR)/stack_example: $(BUILDDIR)/stack.o $(BUILDDIR)/stack_example.o $(BUILDDIR)/linked_list.o
	mkdir -p $(BINDIR)
	$(CC) $(CCFLAGS) $^ -o $@

$(BINDIR)/max_subarray: $(BUILDDIR)/max_subarray.o
	mkdir -p $(BINDIR)
	$(CC) $(CCFLAGS) $^ -o $@

$(BINDIR)/bgnet/showip: $(BUILDDIR)/bgnet/showip.o
	mkdir -p $(BINDIR)/bgnet
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	$(RM) -r $(BUILDDIR) $(BINDIR)
