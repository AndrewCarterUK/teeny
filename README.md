# Teeny

A teeny tiny web application framework in C.

## Status

This project is currently under development and not finished.

## The Goal

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <teeny/app.h>
#include <teeny/request.h>
#include <teeny/response.h>

int hello_world_action(teeny_request_t *request, teeny_response_t *response, const char **route_params, int n_params)
{
    teeny_response_set(response, "<h1>Hello, World!</h1>");
}

int hello_name_action(teeny_request_t *request, teeny_response_t *response, const char **route_params, int n_params)
{
    teeny_response_set_f(response, "<h1>Hello, %s!</h1>", route_params[0]);
}

int main(int argc, char *argv[])
{
    teeny_app_t *app = teeny_app_create();

    teeny_app_get(app, "^/$",             hello_world_action);
    teeny_app_get(app, "^/name/([^/]+)$", hello_name_action);

    teeny_app_listen(app, 5000);

    teeny_app_destroy(app);
}
```


