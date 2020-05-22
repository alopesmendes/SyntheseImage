#
# Les variables d'environnement libG3X, incG3X
# sont definies dans le fichier ~/.bashrc par le script ../install.sh
#
#compilateur
CC = g++

#compil en mode 'debug' ou optmis�e (-O2)
DBG = no

ifeq ($(DBG),yes) #en mode debug
  CFLAGS = -g -Wpointer-arith -Wall -ansi -std=c++11 -openmp
else              #en mode normal
  CFLAGS = -O2 -ansi -std=c++11 -openmp
endif

# assemblage des infos de lib. et inc.
lib =   $(libG3X)

# fichiers *.c locaux
src = src/

# fichiers *.h locaux et lib.
inc = -I./include $(incG3X) 


exec = lray

all : $(exec) clean

# r�gle g�n�rique de cr�ation de xxx.o � partir de src/xxx.c
%.o : $(src)%.cpp
	@echo "module $@ $<"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@
	@echo "------------------------"

# r�gle g�n�rique de cr�ation de l'executable xxx � partir de src/xxx.c (1 seul module)
lray : lray.o Parser.o StandardFigure.o Shape.o Sphere.o Color.o Vector.o Utils.o Camera.o Ray.o Scene.o Image.o Light.o Hit.o Material.o Cube.o Plane.o Triangle.o Box.o
	@echo "assemblage [$^]->$@"
	@$(CC) $^ $(lib) -o $@
	@echo "------------------------"

.PHONY : clean cleanall ?

# informations sur les param�tres de compilation       
? :
	@echo "---------compilation informations----------"
	@echo "  processor      : $(PROCBIT)"
	@echo "  compiler       : $(CC)"
	@echo "  options        : $(CFLAGS)"
	@echo "  lib g2x/OpenGl : $(libG2X)$(COMP)"
	@echo "  headers        : $(incG2X)"
clean : 
	@rm -f *.o
cleanall :
	@rm -f *.o $(exec)
	
