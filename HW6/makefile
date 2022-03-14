all:main.o Shape.o Circle.o Rectangle.o Triangle.o 
	g++ -g Shape.o Circle.o Rectangle.o Triangle.o main.o -o main
Shape.o:Shape.h
	g++ -c Shape.cpp -o Shape.o
Circle.o:Circle.h
	g++ -c Circle.cpp -o Circle.o
Rectangle.o :Rectangle.h
	g++ -c Rectangle.cpp -o Rectangle.o
Triangle.o:Triangle.h
	g++ -c Triangle.cpp -o Triangle.o
main.o:
	g++ -c main.cpp -o main.o
clean:
	rm -rf Shape.o Circle.o Rectangle.o Triangle.o main.o main
