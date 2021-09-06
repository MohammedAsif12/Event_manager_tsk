#define set_bit(n,k) (n)=(n)|(1<<(k-1))
#define get_bit(n,k) (n)&(1<<(k-1))

#include<stdbool.h>

bool get_events(int,void(*)());
void trigger_event(int);


