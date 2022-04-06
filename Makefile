CXX=g++
CXXFLAGS=-arch arm64 -std=c++11 `sdl2-config --cflags | sed -e 's/include\/SDL2/include/'`
LDFLAGS=`sdl2-config --libs`
OBJS=main.o
EXECUTABLE=dist/spacedude

all: make-dist $(EXECUTABLE) 

clean:
	rm -rf dist
	rm -f src/*.o

make-dist:
	mkdir -p dist

src/%.o: src/%.cpp src/*.hpp
	${CXX} -c $(CXXFLAGS) $< -o $@

$(EXECUTABLE): src/main.o
	g++ $(LDFLAGS) $(CXXFLAGS) src/main.o -o $(EXECUTABLE)

