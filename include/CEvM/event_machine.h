#ifndef CEVM_EVENT_MACHINE_H_INCLUDED
#define CEVM_EVENT_MACHINE_H_INCLUDED

#include <CEvM/step_event_machine.h>

/*---------------------------------------------------------------------------*/

typedef uint8_t ( *event_sleeper_fn_t ) ();

/*---------------------------------------------------------------------------*/

typedef struct event_machine_tag
{
  const step_event_machine_t* step_machine;
  const event_sleeper_fn_t event_sleeper;
} event_machine_t;

/*---------------------------------------------------------------------------*/

void event_machine ( const event_machine_t* machine );

/*---------------------------------------------------------------------------*/

#endif /* CEVM_EVENT_MACHINE_H_INCLUDED */

