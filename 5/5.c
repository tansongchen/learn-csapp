typedef long data_t;
#define IDENT 0
#define OP +

typedef struct {
  long len;
  data_t *data;
} vec_rec, *vec_ptr;

long vec_length(vec_ptr v) {
  return v->len;
}

data_t *get_vec_start(vec_ptr v) {
  return v->data;
}

void combine5(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  long limit = length - (5 - 1);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for (i = 0; i < limit; i += 5) {
    acc = (acc OP data[i]) OP data[i + 1];
  }

  for (; i < length; i++) {
    acc = acc OP data[i];
  }

  *dest = acc;
}
