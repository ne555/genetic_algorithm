CXX = g++
#CPPFLAGS = -Wall -pedantic-errors -ggdb -pg -O2
CPPFLAGS = -Wall -pedantic-errors -O2 
LIBRARIES_grapher = $(addprefix -l,GL GLU glut)
LIBRARIES = -O2

object_gen = $(addprefix obj/, cromosoma.o main.o poblacion.o simulator.o)
object_grapher = $(addprefix obj/,grapher.o)

objects = $(object_gen) $(object_grapher)

binaries = $(addprefix bin/,gen grapher) 

project: $(binaries)

all: $(objects)

bin/gen: $(object_gen)
	$(CXX) $(LIBRARIES) $(object_gen) -o $@

bin/grapher: $(object_grapher)
	$(CXX) $(LIBRARIES_grapher) $(object_grapher) -o $@

obj/cromosoma.o: $(addprefix header/,cromosoma.h util.h)
obj/main.o: $(addprefix header/,poblacion.h cromosoma.h simulator.h)
obj/grapher.o:
obj/poblacion.o: $(addprefix header/,poblacion.h cromosoma.h util.h)
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


