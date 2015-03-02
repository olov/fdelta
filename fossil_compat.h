typedef uint16_t u16;
typedef uint32_t u32;
void* fossil_malloc(int size) {
  return calloc(1, size);
}
#define fossil_free free
