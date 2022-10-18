all: run

benchmark: m1cycles.cpp benchmark.cpp
	clang++ -std=c++17 -O2  -o ${@} ${^} -Wall -Wextra

clean:
	rm -rf benchmark

run: benchmark
	sudo ./benchmark
