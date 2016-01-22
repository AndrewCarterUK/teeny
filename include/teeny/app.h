#ifndef TEENY_APP_H_
#define TEENY_APP_H_

// Dependencies

#include <teeny/route.h>

typedef struct teeny_app_t_ {
    teeny_route_t *first_route;
} teeny_app_t;

// Public API

teeny_app_t * teeny_app_create  ();
void          teeny_app_get     (teeny_app_t *app, const char *pattern, teeny_action_t *action);
void          teeny_app_post    (teeny_app_t *app, const char *pattern, teeny_action_t *action);
void          teeny_app_action  (teeny_app_t *app, int method_flags, const char *pattern, teeny_action_t *action);
void          teeny_app_listen  (teeny_app_t *app, int port);
void          teeny_app_destroy (teeny_app_t *app);

#endif

