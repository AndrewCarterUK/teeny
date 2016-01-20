#ifndef TEENY_REQUEST_H_
#define TEENY_REQUEST_H_

// Dependencies

#include <teeny/header.h>

// Definitions

#define TEENY_OPTIONS 0x0001
#define TEENY_GET     0x0002
#define TEENY_HEAD    0x0004
#define TEENY_POST    0x0008
#define TEENY_PUT     0x0010
#define TEENY_DELETE  0x0020
#define TEENY_TRACE   0x0040
#define TEENY_CONNECT 0x0080

typedef struct teeny_request_t_ {
    char *method, *path, *version;
    teeny_header_t *first_header;
    char *content;
} teeny_request_t;

// Public API

teeny_request_t * teeny_request_create           ();
void              teeny_request_destroy          (teeny_request_t *request);
char            * teeny_request_get_method       (teeny_request_t *request);
char            * teeny_request_get_path         (teeny_request_t *request);
char            * teeny_request_get_version      (teeny_request_t *request);
teeny_header_t  * teeny_request_get_headers      (teeny_request_t *request);
teeny_header_t  * teeny_request_get_header       (teeny_request_t *request, const char *name);
char            * teeny_request_get_header_value (teeny_request_t *request, const char *name);
char            * teeny_request_get_content      (teeny_request_t *request);
char            * teeny_request_set_method       (teeny_request_t *request, const char *method);
char            * teeny_request_set_path         (teeny_request_t *request, const char *path);
char            * teeny_request_set_version      (teeny_request_t *request, const char *version);
teeny_header_t  * teeny_request_add_header       (teeny_request_t *request, const char *name, const char *value);
teeny_header_t  * teeny_request_delete_header    (teeny_request_t *request, const char *name);
char            * teeny_request_set_content      (teeny_request_t *request, const char *content);

