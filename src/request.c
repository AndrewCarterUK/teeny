#include <stdlib.h>
#include <string.h>
#include <teeny/request.h>
#include <teeny/header.h>

teeny_request_t * teeny_request_create()
{
	return calloc(1, sizeof(teeny_request_t));
}

void teeny_request_destroy(teeny_request_t *request)
{
	free(request);
}

const char * teeny_request_get_method(teeny_request_t *request)
{
	return request->method;
}

const char * teeny_request_get_path(teeny_request_t *request)
{
	return request->path;
}

const char * teeny_request_get_version(teeny_request_t *request)
{
	return request->version;
}

teeny_header_t * teeny_request_get_headers(teeny_request_t *request)
{
	return request->first_header;
}

teeny_header_t * teeny_request_get_header(teeny_request_t *request, const char *name)
{
  return teeny_header_find(request->first_header, name);
}

const char * teeny_request_get_header_value(teeny_request_t *request, const char *name)
{
  teeny_header_t *header;

  header = teeny_request_get_header(request, name);

  if (NULL == header) {
    return NULL;
  }

  return teeny_header_get_name(header);
}

FILE * teeny_request_get_content(teeny_request_t *request)
{
  return request->content;
}

void teeny_request_set_method(teeny_request_t *request, const char *method)
{
  free(request->method);

  request->method = strdup(method);
}

void teeny_request_set_path(teeny_request_t *request, const char *path)
{
  free(request->path);

  request->path = strdup(path);
}

void teeny_request_set_version(teeny_request_t *request, const char *version)
{
  free(request->version);

  request->version = strdup(version);
}

teeny_header_t * teeny_request_add_header(teeny_request_t *request, const char *name, const char *value)
{
  teeny_header_t *header;

  // Header already exists
  if (NULL != teeny_request_get_header(request, name)) {
    return NULL;
  }

  header = teeny_header_create(name, value);

  if (NULL == header) {
    return NULL;
  }

  if (NULL != request->first_header) {
    request->first_header->prev = header;
  }

  header->next = request->first_header;
  request->first_header = header;

  return header;
}

void teeny_request_delete_header(teeny_request_t *request, const char *name)
{
  teeny_header_t *header;

  header = teeny_request_get_header(request, name);

  if (NULL == header) {
    return;
  }

  if (NULL != header->next) {
    header->next->prev = header->prev;
  }

  if (NULL != header->prev) {
    header->prev->next = header->next;
  }

  if (request->first_header == header) {
    request->first_header = header->next;
  }

  teeny_header_destroy(header);
}

void teeny_request_set_content(teeny_request_t *request, FILE *content)
{
  request->content = content;
}
