#include <app/app_event_machine.h>

#include <CEvM/event_machine.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

int main ( int argc, char** argv )
{
  LGGM_CALL_IN_C ( 1 );
  ( void ) argc;
  ( void ) argv;

  event_machine ( &app_event_machine );

  LGGM_CALL_OUT_C ( 1 );
  return 0;
}
