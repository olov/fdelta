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
    fprintf(stderr, "fapply original delta\n");
    exit(1);
  }

  char* orig;
  int64_t orig_len = slurp(argv[1], &orig);
  char* delta;
  int64_t delta_len = slurp(argv[2], &delta);

  int64_t mod_len = delta_output_size(delta, delta_len);
  char* mod = calloc(1, mod_len + 1);
  delta_apply(orig, orig_len, delta, delta_len, mod);

  fputs(mod, stdout);

  return 0;
}
