#ifndef CEVM_EVENT_HANDLER_H_INCLUDED
#define CEVM_EVENT_HANDLER_H_INCLUDED

#include <CEvM/event.h>

/*---------------------------------------------------------------------------*/

typedef void ( *event_handler_fn_t ) ( const event_t* );

/*---------------------------------------------------------------------------*/

typedef struct event_handler_tag
{
  const event_handler_fn_t handler;
} event_handler_t;

/*---------------------------------------------------------------------------*/

#endif /* CEVM_EVENT_HANDLER_H_INCLUDED */
