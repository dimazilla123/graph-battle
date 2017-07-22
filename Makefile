LIBS=-lncurses
CXX=g++

HEADERS=src/headers/
SOURCES=src/
OBJDIR=obj/

OBJS=

CXXFLAGS=-I $(HEADERS) -w -g

OBJLIST=$(addprefix $(OBJDIR),$(OBJS))
OUTPUT=main
.SUFFIXES:
.SUFFIXES: .cpp .c .h .hpp .o

$(OBJDIR)%.o: $(SOURCES)%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@
$(OUTPUT): $(OBJLIST)
	$(CXX) $(OBJLIST) $(LIBS) $(LDFLAGS) -o $@
all: $(OUTPUT)
clean:
	rm obj/*
	rm $(OUTPUT)
