#ifndef TEENY_RESPONSE_H_
#define TEENY_RESPONSE_H_

// Dependencies

#include <teeny/header.h>

// Definitions

typedef struct teeny_response_t_ {
    char *version, *status_code, *reason_phrase
    teeny_header_t *first_header;
    char *content;
} teeny_response_t;

// Public API

teeny_response_t * teeny_response_create            ();
void               teeny_response_destroy           (teeny_response_t *response);
const char       * teeny_response_get_version       (teeny_response_t *response);
const char       * teeny_response_get_status_code   (teeny_response_t *response);
const char       * teeny_response_get_reason_phrase (teeny_response_t *response);
teeny_header_t   * teeny_response_get_headers       (teeny_response_t *response);
teeny_header_t   * teeny_response_get_header        (teeny_response_t *response, const char *name);
const char       * teeny_response_get_header_value  (teeny_response_t *response, const char *name);
const char       * teeny_response_get_content       (teeny_response_t *response);
void               teeny_response_set_version       (teeny_response_t *response, const char *version);
void               teeny_response_set_status_code   (teeny_response_t *response, const char *status_code);
void               teeny_response_set_reason_phrase (teeny_response_t *response, const char *reason_phrase);
void               teeny_response_add_header        (teeny_response_t *response, const char *name, const char *value);
void               teeny_response_delete_header     (teeny_response_t *response, const char *name);
void               teeny_response_set               (teeny_response_t *response, const char *content);
void               teeny_response_set_f             (teeny_response_t *response, const char *format, ...);

#endif
