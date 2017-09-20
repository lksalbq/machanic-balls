# Instrucao para instalar pacotes de OpenGL necessarios em Ubuntu:
# sudo apt-get install freeglut3 freeglut3-dev

all: test-ball test-ball-graphics test-springmass test-springmass-graphics
test-ball : ball.cpp ball.h test-ball.cpp
test-ball-graphics : graphics.cpp ball.cpp test-ball-graphics.cpp
test-springmass : springmass.cpp test-springmass.cpp
test-springmass-graphics : graphics.cpp springmass.cpp test-springmass-graphics.cpp

CXX=g++
LDLIBS=-lGL -lGLU -lglut
# LDFLAGS=-lGL -LGL
VPATH=GL

clean:
	find . -name '*~' -delete
	rm -f test-ball test-ball-graphics test-springmass test-springmass-graphics a.out

