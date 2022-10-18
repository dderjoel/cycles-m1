all: run

benchmark: m1cycles.c benchmark.c
	$(CC) -O2 -o ${@} ${^} -Wall -Wextra

clean:
	rm -rf benchmark

run: benchmark
	sudo ./benchmark
