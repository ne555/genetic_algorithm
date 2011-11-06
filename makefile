CXX = g++
#CPPFLAGS = -Wall -pedantic-errors -ggdb -pg -O2
CPPFLAGS = -Wall -pedantic-errors -O2 
LIBRARIES_grapher = $(addprefix -l,GL GLU glut)
LIBRARIES = -O2

object_gen = $(addprefix obj/, cromosoma.o poblacion.o simulator.o fenotipo.o)
object_grapher = $(addprefix obj/,grapher.o)

objects = $(object_gen) $(object_grapher)

binaries = $(addprefix bin/,gen_1 gen_2 grapher) 

project: $(binaries)

all: $(objects)

bin/gen_1: $(object_gen) obj/main_ej1.o
	$(CXX) $(LIBRARIES) $^ -o $@
	
bin/gen_2: $(object_gen) obj/main_ej2.o obj/agente_viajero.o
	$(CXX) $(LIBRARIES) $^ -o $@

bin/grapher: $(object_grapher)
	$(CXX) $(LIBRARIES_grapher) $(object_grapher) -o $@

obj/agente_viajero.o: $(addprefix header/,fenotipo.h)
obj/cromosoma.o: $(addprefix header/,cromosoma.h util.h)
obj/fenotipo.o: 
obj/grapher.o:
obj/main_ej1.o: $(addprefix header/,poblacion.h cromosoma.h simulator.h fenotipo.h)
obj/main_ej2.o: $(addprefix header/,poblacion.h cromosoma.h simulator.h fenotipo.h)
obj/poblacion.o: $(addprefix header/,poblacion.h cromosoma.h util.h fenotipo.h)
obj/simulator.o: $(addprefix header/,simulator.h poblacion.h cromosoma.h)

obj/%.o: src/%.cpp
	@$(CXX) $< -c $(CPPFLAGS) -Iheader -o $@

$(objects): | obj

$(binaries): | bin

obj:
	mkdir $@

bin:
	mkdir $@


.PHONY: clean test

clean:
	-rm $(objects) $(binaries)
	-rmdir bin obj


