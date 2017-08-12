LIBS=
CXX=g++

HEADERS=src/headers/
SOURCES=src/
OBJDIR=obj/

OBJS=main.o room.o item.o unit.o monster.o player.o

CXXFLAGS=-I $(HEADERS)  -w -g

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
	rm $(OBJLIST)
	rm $(OUTPUT)
