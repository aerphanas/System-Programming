#include <czmq.h>
#include <stdio.h>

int
main()
{
    zsock_t *request = zsock_new(ZMQ_REQ);
    zsock_connect(request, "tcp://0.0.0.0:5555");
    zstr_send(request, "hello");
    sleep(1);
    char *pstr = zstr_recv(request);
    printf("%s\n", pstr);
    zsock_destroy(&request);
    return 0;
}