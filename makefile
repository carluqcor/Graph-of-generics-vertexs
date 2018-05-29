NAME=principalGrafo

#
OBJECTS = $(NAME).o funcionesAuxiliares.o Grafo.o Vertice.o Lado.o Punto.o

#
CPPFLAGS = -c -g -Wall -ansi -O2

INCLUDES = funcionesAuxiliares.hpp Grafo.hpp Vertice.hpp Lado.hpp Punto.hpp macros.hpp distancia.hpp

# Macros predefinidas
#
# $@: nombre del objetivo
# $^: todas las dependencias
# $<: primera dependencia
#

objetivo: $(NAME).exe

#Opciones para NO depurar los asertos
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

# Primer objetivo 
$(NAME).exe: $(OBJECTS)
			@echo "Generando " $@
			@g++ $^ -o $@
#
$(NAME).o: $(NAME).cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
funcionesAuxiliares.o: funcionesAuxiliares.cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
Punto.o: Punto.cpp Punto.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
Vertice.o: Vertice.cpp Vertice.hpp Punto.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
Lado.o: Lado.cpp Lado.hpp
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<


Grafo.o:   Grafo.cpp Grafo.hpp Vertice.hpp Punto.hpp Lado.hpp
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<





# Generación de la documentación
doc: Doxyfile 
	@echo "Generando la documentación con doxygen"
	@doxygen
  
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ *.exe *.png *.o *.dot Kruskal.txt Prim.txt Adyacencias.txt

