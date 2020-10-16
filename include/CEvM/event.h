#ifndef CEVM_EVENT_H_INCLUDED
#define CEVM_EVENT_H_INCLUDED

#include <stdint.h>

/*---------------------------------------------------------------------------*/

typedef struct event_msg_tag
{
  uint32_t code;
  uint32_t param;
} event_msg_t;

/*---------------------------------------------------------------------------*/

typedef struct event_ptr_tag
{
  void* data;
} event_ptr_t;

/*---------------------------------------------------------------------------*/

typedef union event_tag
{
  event_msg_t msg;
  event_ptr_t ptr;
} event_t;

/*---------------------------------------------------------------------------*/

#endif /* CEVM_EVENT_H_INCLUDED */
