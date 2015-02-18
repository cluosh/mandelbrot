CFLAGS=-O3 -std="c++11" -fopenmp
LFLAGS=-lSDL2 -lSDL2_image

mandelbrot: main.cpp Display.cpp Complex.cpp Mandelbrot.cpp
	g++ main.cpp Display.cpp Complex.cpp Mandelbrot.cpp $(CFLAGS) $(LFLAGS) -o mandelbrot
	strip mandelbrot
