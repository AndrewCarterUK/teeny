#ifndef TEENY_HEADER_H_
#define TEENY_HEADER_H_

// Definitions

typedef struct teeny_header_t_ {
    char *name, *value;
    struct teeny_header_t_ *prev, *next;
} teeny_header_t;

// Public API

teeny_header_t * teeny_header_create    (const char *name, const char *value);
void             teeny_header_destroy   (teeny_header_t *header);
teeny_header_t * teeny_header_find      (teeny_header_t *header, const char *name);
const char     * teeny_header_get_name  (teeny_header_t *header);
const char     * teeny_header_get_value (teeny_header_t *header);
void             teeny_header_set_name  (teeny_header_t *header, const char *name);
void             teeny_header_set_value (teeny_header_t *header, const char *value);

#endif
