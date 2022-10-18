fastestrng: m1cycles.cpp benchmark.cpp
	clang++ -std=c++17 -O2 -fno-tree-vectorize -o benchmark m1cycles.cpp benchmark.cpp -Wall -Wextra
	sudo ./benchmark
clean:
	rm -r -f benchmark
