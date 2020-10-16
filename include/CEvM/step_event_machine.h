#ifndef CEVM_STEP_EVENT_MACHINE_H_INCLUDED
#define CEVM_STEP_EVENT_MACHINE_H_INCLUDED

#include <stdint.h>

#include <CEvM/event_handler_list.h>

/*---------------------------------------------------------------------------*/

typedef uint8_t ( *event_puller_fn_t ) ( event_t* result );

/*---------------------------------------------------------------------------*/

typedef struct step_event_machine_tag
{
  const event_handler_list_t* list;
  const event_puller_fn_t event_puller;
} step_event_machine_t;

/*---------------------------------------------------------------------------*/

uint8_t step_event_machine ( const step_event_machine_t* machine );

/*---------------------------------------------------------------------------*/

#endif /* INCLUDE_CEVM_STEP_EVENT_MACHINE_H_ */
