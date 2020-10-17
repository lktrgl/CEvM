#include <CEvM/event_machine.h>

#include <CEvM/impl/event_cfg.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

void event_machine ( const event_machine_t* machine )
{
  LGGM_CALL_IN_C ( 1 );

  if ( machine )
  {
    const event_sleeper_fn_t event_sleeper = machine->event_sleeper;
    const step_event_machine_t* step_machine = machine->step_machine;

    if ( event_sleeper )
    {
      LGGM_PRINT_MSG_C ( 1, "Running event machine with sleeper" );

      while ( event_sleeper() )
      {
        ( void ) step_event_machine ( step_machine );
      }
    }
    else
    {
      LGGM_PRINT_MSG_C ( 1, "Running event machine without sleeper" );

      for ( ;; )
      {
        ( void ) step_event_machine ( step_machine );
      }
    }
  }

  LGGM_CALL_OUT_C ( 1 );
}
