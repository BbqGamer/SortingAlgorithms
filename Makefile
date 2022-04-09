SDIR=src
ODIR=build
CC=g++
CFLAGS = -std=c++11
LIBS = -static-libstdc++ -shared-libgcc -xc++

_DEPS = algorithms.h includes.h utils.h
DEPS = $(patsubst %,$(SDIR)/%,$(_DEPS))

_OBJ = algorithms.o experiment.o utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bin/experiment: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f build/*.o bin/*