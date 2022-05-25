#include "cachelab.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct line {
  bool valid;
  long tag;
  unsigned last_accessed;
} line_t;

typedef line_t *set;

int main(int argc, char **argv) {
  bool verbose = false;
  int s = -1, E = -1, b = -1, S = -1;
  FILE *trace;
  for (int i = 1; i < argc; ++i) {
    switch (argv[i][1]) {
    case 'v':
      verbose = true;
      break;
    case 'h':
      printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\nOptions:\n  -h         Print this help message.\n  -v         Optional verbose flag.\n  -s <num>   Number of set index bits.\n  -E <num>   Number of lines per set.\n  -b <num>   Number of block offset bits.\n  -t <file>  Trace file.\n\nExamples:\n  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
      exit(0);
    case 's':
      ++i;
      sscanf(argv[i], "%d", &s);
      S = 1 << s;
      break;
    case 'E':
      ++i;
      sscanf(argv[i], "%d", &E);
      break;
    case 'b':
      ++i;
      sscanf(argv[i], "%d", &b);
      // B = 1 << b;
      break;
    case 't':
      ++i;
      trace = fopen(argv[i], "r");
      break;
    default:
      printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
      exit(1);
    }
  }

  char line[40];
  char operation;
  unsigned long address, size;
  unsigned epoch = 0;
  unsigned hits = 0, misses = 0, evictions = 0;
  line_t (*cache)[E] = malloc(sizeof(line_t[S][E]));

  while (fgets(line, 40, trace) != NULL) {
    if (line[0] != ' ') continue;
    sscanf(line, " %c %lx,%lx", &operation, &address, &size);
    // long offset = address & ((1 << b) - 1);
    long index = (address >> b) & ((1 << s) - 1);
    long tag = address >> (s + b);
    line_t *set = cache[index];
    bool hit = false, eviction = true;
    for (int i = 0; i != E; ++i) {
      if (set[i].valid && set[i].tag == tag) {
        hit = true;
        set[i].last_accessed = epoch;
        break;
      }
    }
    if (hit) {
      ++hits;
    } else {
      ++misses;
      for (int i = 0; i != E; ++i) {
        if (!set[i].valid) {
          eviction = false;
          set[i].valid = true;
          set[i].tag = tag;
          set[i].last_accessed = epoch;
          break;
        }
      }
      if (eviction) {
        ++evictions;
        unsigned recency = epoch, lru = -1;
        for (int i = 0; i != E; ++i) {
          if (set[i].last_accessed < recency) {
            recency = set[i].last_accessed;
            lru = i;
          }
        }
        set[lru].tag = tag;
        set[lru].last_accessed = epoch;
      }
    }
    if (operation == 'M') ++hits;
    if (verbose) {
      printf("%c %lx,%lx", operation, address, size);
      hit ? printf(" hit") : printf(" miss");
      if (!hit && eviction) printf(" eviction");
      if (operation == 'M') printf(" hit");
      printf("\n");
    }
    ++epoch;
  }

  printSummary(hits, misses, evictions);
  return 0;
}
