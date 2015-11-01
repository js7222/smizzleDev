#include <stdio.h>
#include <sys/time.h>
#include <event2/event.h>

void say_hello(int fd, short event, void *arg){
    printf("Hello\n");
}

int main(int argc, const char* argv[])
{

    struct event_config *cfg;
    struct event_base *base;
    int i;

    enum event_method_feature flags;
    flags =EV_FEATURE_O1;  /*|EV_FEATURE_FDS; */
/* My program wants to use edge-triggered events if at all possible.  So
   I'll try to get a base twice: Once insisting on edge-triggered IO, and
   once not. */
    for (i=0; i<2; ++i) {
	cfg = event_config_new();

	/* I don't like select. */
	/*event_config_avoid_method(cfg, "select");*/


	if (i == 0)
	    flags |= EV_FEATURE_ET;

	
/*	event_config_require_features(cfg, flags);*/

	base = event_base_new_with_config(cfg);
	event_config_free(cfg);
	if (base)
	{
	    const char* base_method;
	    base_method = event_base_get_method(base);
	    puts(base_method);
	    printf("managed to find event base i=%u", i);
	    break;
	}
	/* If we get here, event_base_new_with_config() returned NULL.  If
	   this is the first time around the loop, we'll try again without
	   setting EV_FEATURE_ET.  If this is the second time around the
	   loop, we'll give up. */
    }

}
