#include <stdio.h>
#include <czmq.h>
#include <stdlib.h>

int
main()
{
    zsock_t *response = zsock_new(ZMQ_REP);
    int r = zsock_bind(response, "tcp://0.0.0.0:5555");
    if (r != 5555)
      printf("bind to port 5555 failed \n");
    
    while (true) {
        char* msg = zstr_recv(response);
        if (!strcmp(msg, "hello"))
          zstr_send(response, "world");
        free(msg);
    }

    zsock_destroy(&response);

    return 0;
}