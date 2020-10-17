#include <CEvM/step_event_machine.h>

#include <CEvM/impl/event_cfg.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

uint8_t step_event_machine ( const step_event_machine_t* machine )
{
  LGGM_CALL_IN_C ( 1 );

  event_t ev;

  if ( machine
       && machine->event_puller
       && machine->event_puller ( &ev ) )
  {
    LGGM_PRINT_MSG_C ( 1, "The event obtained" );

    const event_handler_list_t* list = machine->list;

    if ( list )
    {
      LGGM_PRINT_MSG_C ( 1, "Activating handlers chain" );

      const uint8_t nodes_count = list->nodes_count;
      const event_handler_node_t* node = list->node;

      for ( uint8_t i = 0; node && i < nodes_count; ++node, ++i )
      {
        const event_handler_fn_t handler = node->handler.handler;

        if ( handler )
        {
          LGGM_PRINT_INT_C ( 1, i );

          handler ( &ev );
        }
      }
    }

    LGGM_CALL_OUT_C ( 1 );
    return 1;
  }

  LGGM_CALL_OUT_C ( 1 );
  return 0;
}
