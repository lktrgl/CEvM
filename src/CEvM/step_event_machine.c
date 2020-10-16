#include <CEvM/step_event_machine.h>

/*---------------------------------------------------------------------------*/

uint8_t step_event_machine ( const step_event_machine_t* machine )
{
  event_t ev;

  if ( machine
       && machine->event_puller
       && machine->event_puller ( &ev ) )
  {
    const event_handler_list_t* list = machine->list;

    if ( list )
    {
      const uint8_t nodes_count = list->nodes_count;
      const event_handler_node_t* node = list->node;

      for ( uint8_t i = 0; node && i < nodes_count; ++node, ++i )
      {
        const event_handler_fn_t handler = node->handler.handler;

        if ( handler )
        {
          handler ( &ev );
        }
      }
    }

    return 1;
  }

  return 0;
}
