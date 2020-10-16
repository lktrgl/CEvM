#include <CEvM/event_machine.h>

/*---------------------------------------------------------------------------*/

void event_machine ( const event_machine_t* machine )
{
  if ( machine )
  {
    const event_sleeper_fn_t event_sleeper = machine->event_sleeper;
    const step_event_machine_t* step_machine = machine->step_machine;

    if ( event_sleeper )
    {
      while ( event_sleeper() )
      {
        ( void ) step_event_machine ( step_machine );
      }
    }
    else
    {
      for ( ;; )
      {
        ( void ) step_event_machine ( step_machine );
      }
    }
  }
}
