#include "fossil_delta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int64_t slurp(const char* filename, char** out) {
  FILE *fp;
  int64_t size;
  char *buffer;

  fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "file not found %s\n", filename);
    exit(1);
  }

  fseek(fp, 0L, SEEK_END);
  size = ftello(fp);
  rewind(fp);

  buffer = calloc(1, size+1);

  if (fread(buffer, size, 1, fp) != 1) {
    fclose(fp);
    fprintf(stderr, "error reading %s\n", filename);
    exit(1);
  }

  fclose(fp);

  *out = buffer;
  return size;
}

// allocated memory is never freed
int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "usage: fdelta original modified\ndelta is written to stdout\n");
    exit(1);
  }

  char* orig;
  int64_t orig_len = slurp(argv[1], &orig);
  char* mod;
  int64_t mod_len = slurp(argv[2], &mod);

  char* diff = calloc(1, mod_len + 1 + 60 + 1024); // add an extra K just because
  delta_create(orig, orig_len, mod, mod_len, diff);

  fputs(diff, stdout);

  return 0;
}
