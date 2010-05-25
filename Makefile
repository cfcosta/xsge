LIBS=`pkg-config --libs --cflags sdl`
SOURCES=src/engine.cpp src/window.cpp
FLAGS=-Wall -Werror -pedantic

build:
	if [ ! -d output ]; then mkdir output ; fi
	$(CXX) $(CXXFLAGS) $(LIBS) $(SOURCES) $(FLAGS)
clean:
	rm -rf output
