#include <stdlib.h>
#include <string.h>
#include <teeny/header.h>

teeny_header_t * teeny_header_create(const char *name, const char *value)
{
	teeny_header_t *header;

  header = calloc(1, sizeof(teeny_header_t));

  if (NULL == header) {
    return NULL;
  }

  header->name = strdup(name);
  header->value = strdup(value);

  return header;
}

void teeny_header_destroy(teeny_header_t *header)
{
  free(header->name);
  free(header->value);
	free(header);
}

teeny_header_t * teeny_header_find(teeny_header_t *header, const char *name)
{
  while (NULL != header) {
    if (0 == strcasecmp(header->name, name)) {
      return header;
    }

    header = header->next;
  }

  return NULL;
}

const char * teeny_header_get_name(teeny_header_t *header)
{
  return header->name;
}

const char * teeny_header_get_value(teeny_header_t *header)
{
  return header->value;
}

void teeny_header_set_name(teeny_header_t *header, const char *name)
{
  free(header->name);

  header->name = strdup(name);
}

void teeny_header_set_value (teeny_header_t *header, const char *value)
{
  free(header->value);

  header->value = strdup(value);
}
