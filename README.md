# Credit
[Lemire Blogpost on Counting cycles](https://lemire.me/blog/2021/03/24/counting-cycles-and-instructions-on-the-apple-m1-processor/)
Original code [here](https://github.com/lemire/Code-used-on-Daniel-Lemire-s-blog/tree/master/2021/03/24)

# Usage:
```
make
```

## Files:
- `m1cycles.h`: defines setup methos and `get_cycles`
- `m1cycles.c`: implements `m1cycles.h`
- `benchmark.c`: example usage of how to set up cycles counters and usage.


## Use in own project:
copy `m1cycles.{c,h}` into own project and use as in `./benchmark.c`.

Which in a nutshell:
```c


#include "m1cycles.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  setup_performance_counters();

  uint64_t start = get_cycles();

// work

  uint64_t end = get_cycles();

  printf("Diff in cycles  %" PRId64 " \n", end - start);

  return 0;
}
```

## Requirements:

- Apple M1 system.
- Complete compiler system pre-installed.
