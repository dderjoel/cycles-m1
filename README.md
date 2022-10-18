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

  printf("diff in cycles  %lu \n", end - start);

  return 0;
}
```

## Requirements:

- Apple M1 system.
- Complete compiler system pre-installed.
