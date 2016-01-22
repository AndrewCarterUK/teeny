#include <stdlib.h>
#include <teeny/request.h>

teeny_request_t * teeny_request_create()
{
	return calloc(1, sizeof(teeny_request_t));
}

void teeny_request_destroy(teeny_request_t *request)
{
	free(request);
}

char * teeny_request_get_method(teeny_request_t *request)
{
	return request->method;
}

char * teeny_request_get_path(teeny_request_t *request)
{
	return request->path;
}

char * teeny_request_get_version(teeny_request_t *request)
{
	return request->version;
}

teeny_header_t * teeny_request_get_headers(teeny_request_t *request)
{
	return request->first_header;
}

/* TODO
teeny_header_t * teeny_request_get_header(teeny_request_t *request, const char *name);
char * teeny_request_get_header_value(teeny_request_t *request, const char *name);
char * teeny_request_get_content(teeny_request_t *request);
char * teeny_request_set_method(teeny_request_t *request, const char *method);
char * teeny_request_set_path(teeny_request_t *request, const char *path);
char * teeny_request_set_version(teeny_request_t *request, const char *version);
teeny_header_t * teeny_request_add_header(teeny_request_t *request, const char *name, const char *value);
teeny_header_t * teeny_request_delete_header(teeny_request_t *request, const char *name);
char * teeny_request_set_content(teeny_request_t *request, const char *content); */

