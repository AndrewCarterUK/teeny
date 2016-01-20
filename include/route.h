#ifndef TEENY_REQUEST_H_
#define TEENY_REQUEST_H_

// Dependencies

#include <teeny/response.h>
#include <teeny/request.h>

// Definitions

typedef int (*teeny_action_t) (teeny_request_t *request, teeny_response_t * const char **route_params, int n_params);

typedef struct teeny_route_t_ {
    int method_flags;
    char *route_pattern;
    teeny_action_t *action;
    struct teeny_route_t_ *next;
} teeny_route_t;

typedef struct teeny_match_t_ {
    teeny_route_t *route;
    char **route_params;
    int n_params;
} teeny_match_t;

// Public API

teeny_route_t * teeny_route_create  (int method_flags, const char *route_pattern, teeny_action_t *action);
void            teeny_route_destroy (teeny_route_t *route);
teeny_match_t * teeny_route_match   (teeny_route_t *route, teeny_request_t *request);

