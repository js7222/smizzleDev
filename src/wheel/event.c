#include <stdio.h>
#include <sys/time.h>
#include <event2/event.h>

void say_hello(int fd, short event, void *arg){
        printf("Hello\n");
}

int main(int argc, const char* argv[])
{


    int i;

    const char **methods = event_get_supported_methods();
    printf("Starting Libevent %s.  Available methods are:\n",
	   event_get_version());
    for (i=0; methods[i] != NULL; ++i) {
	printf("    %s\n", methods[i]);
    }

    struct event_base *base;
    struct event_config *cfg;
    enum event_method_feature f;

    cfg = event_config_new();


    
    base = event_base_new_with_config(cfg);
    if (!base) {
	puts("Couldn't get an event_base!");
    } else {
	printf("Using Libevent with backend method %s.",
	       event_base_get_method(base));
	f = event_base_get_features(base);
	if ((f & EV_FEATURE_ET))
	    printf("  Edge-triggered events are supported.");
	if ((f & EV_FEATURE_O1))
	    printf("  O(1) event notification is supported.");
	if ((f & EV_FEATURE_FDS))
	    printf("  All FD types are supported.");
	puts("");
    }





//    event_dispatch();

  return 0;
}



void cb_func(evutil_socket_t fd, short what, void *arg)
{
        const char *data = arg;
        printf("Got an event on socket %d:%s%s%s%s [%s]",
            (int) fd,
            (what&EV_TIMEOUT) ? " timeout" : "",
            (what&EV_READ)    ? " read" : "",
            (what&EV_WRITE)   ? " write" : "",
            (what&EV_SIGNAL)  ? " signal" : "",
            data);
}

void main_loop(evutil_socket_t fd1, evutil_socket_t fd2)
{
        struct event *ev1, *ev2;
        struct timeval five_seconds = {5,0};
        struct event_base *base = event_base_new();

        /* The caller has already set up fd1, fd2 somehow, and make them
           nonblocking. */

        ev1 = event_new(base, fd1, EV_TIMEOUT|EV_READ|EV_PERSIST, cb_func,
           (char*)"Reading event");
        ev2 = event_new(base, fd2, EV_WRITE|EV_PERSIST, cb_func,
           (char*)"Writing event");

        event_add(ev1, &five_seconds);
        event_add(ev2, NULL);
        event_base_dispatch(base);
}
