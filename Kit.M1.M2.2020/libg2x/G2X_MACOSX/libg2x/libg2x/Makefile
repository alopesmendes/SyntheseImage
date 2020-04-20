CC = gcc

ifeq ($(CC),g++)
  EXT = .$(PROC)++
else
  EXT = .$(PROC)
endif

ifeq ($(DEBUG),yes)
  CFLAGS  = -O2 -g -Wpointer-arith -Wall -ansi
  EXT2 = $(EXT).gdb
else
  CFLAGS = -O2 -ansi
  EXT2 = $(EXT)
endif

lib = -L/usr/lib -lm
inc = -I/usr/include -I./include
src =  src/

# cible pour les binaires (.a,.so) 
bin = .

modules = g2x_window.o g2x_tools.o g2x_capture.o g2x_draw.o

%.o : $(src)%.c
	@echo "module $@"
	@$(CC) -fpic $(CFLAGS) $(inc) -c $< -o $@ -Wno-deprecated -framework GLUT -framework OpenGL

	@echo "------------------------"

all : g2x clean

g2x :    $(modules)
	@echo "massemblage bibliotheque dynamique $(bin)/lib$@$(EXT2).so"
	@$(CC) -fpic -shared $^ $(lib) -o $(bin)/lib$@$(EXT2).so -framework GLUT -framework OpenGL

	#$(VERS)
#	@ln -fs lib$@$(EXT2).so$(VERS) $(bin)/lib$@$(EXT2).so
#	@echo "massemblage bibliotheque d'archive $(bin)/lib$@$(EXT2).a"
#	@ar r $(bin)/lib$@$(EXT2).a $^
	@echo "------------------------                                "

% : %.o
	@echo "assemblage [$^]->$@"
	@$(CC) $^ $(lib) -o $@
	@echo "------------------------"

.PHONY : clean
clean : 
	rm -f *.o 
