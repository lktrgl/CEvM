#ifndef CEVM_EVENT_HANDLER_LIST_H_INCLUDED
#define CEVM_EVENT_HANDLER_LIST_H_INCLUDED

#include <stdint.h>

#include <CEvM/event_handler.h>

/*---------------------------------------------------------------------------*/

typedef struct event_handler_node_tag
{
  const event_handler_t handler;
} event_handler_node_t;

/*---------------------------------------------------------------------------*/

typedef struct event_handler_list_tag
{
  const event_handler_node_t* node;
  const uint8_t nodes_count;
} event_handler_list_t;

/*---------------------------------------------------------------------------*/

#endif /* CEVM_EVENT_HANDLER_LIST_H_INCLUDED */
