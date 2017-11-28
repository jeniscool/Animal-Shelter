OBJECTS = animalshelter.o lab11.o
HEADERS = animalshelter.h
PROGRAM = Lab11
$(PROGRAM): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o $(PROGRAM)
