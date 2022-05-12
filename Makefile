CC=g+++
CPPFLAGS=-std=c++11
objects :tarjan_cut_vertices

all: $(objects)

$(objects): %: %.cpp
	$(CC) $ $(CPPFLAGS) -o $@ $<
