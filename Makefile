build:
	g++ -std=c++17 -Wall ./src/*.cpp ./src/Physics/*.cpp -lm -lSDL2 -lSDL2_image -lSDL2_gfx -o app.exe

run:
	./app.exe

clean:
	rm app.exe
