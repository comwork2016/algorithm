vpath %.cpp src
vpath %.h include

main:main.o ListUDG.o
	g++ -std=c++11 $^ -o $@

main.o:main.cpp
	g++ -std=c++11 -o $@ -c $^ -Iinclude
%.o:%.cpp
	g++ -std=c++11 -o $@ -c $^ -Iinclude

.PHONY:clean

clean:
	-rm -rf *.o main
