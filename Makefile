ARCH=
CXX=g++
CXXFLAGS=$(ARCH) -std=c++11 `sdl2-config --cflags | sed -e 's/include\/SDL2/include/'` -framework OpenGL -I/opt/X11/include
LDFLAGS=`sdl2-config --libs` -lSDL2_image
SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:.cpp=.o)
HEADERS=${wildcard src/*.hpp}
EXECUTABLE=dist/spacedude

all: make-dist copy-assets $(EXECUTABLE) 

clean:
	rm -rf dist
	rm -f src/*.o

make-dist:
	mkdir -p dist

copy-assets:
	cp -pr assets dist

src/%.o: src/%.cpp src/*.hpp
	${CXX} -c $(CXXFLAGS) $< -o $@

$(EXECUTABLE): $(OBJS) ${HEADERS}
	g++ $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(EXECUTABLE)

