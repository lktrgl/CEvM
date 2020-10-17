#include <app/app_event_machine.h>

#include <app/app_cfg.h>

#include <lggm/dbgprn.h>

/*---------------------------------------------------------------------------*/

static uint8_t s_event_sleeper()
{
  LGGM_CALL_IN_C ( 1 );

  static uint8_t s_count = SLEEPER_COUNT;

  LGGM_PRINT_INT_C ( 1, s_count );
  LGGM_CALL_OUT_C ( 1 );

  return s_count--;
}

/*---------------------------------------------------------------------------*/

static uint8_t s_app_event_puller ( event_t* result )
{
  LGGM_CALL_IN_C ( 1 );

  static uint8_t s_count = SLEEPER_COUNT;

  if ( result )
  {

    ( *result ).msg.code = s_count--;

    LGGM_PRINT_INT_C ( 1, s_count );
    LGGM_CALL_OUT_C ( 1 );

    return ( *result ).msg.code;
  }
  else
  {
    LGGM_CALL_OUT_C ( 1 );
    return 0;
  }
}

/*---------------------------------------------------------------------------*/

static void s_app_event_handler_1 ( const event_t* event )
{
  LGGM_CALL_IN_C ( 1 );
  LGGM_PRINT_INT_C ( 1, ( *event ).msg.code );
  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

static void s_app_event_handler_2 ( const event_t* event )
{
  LGGM_CALL_IN_C ( 1 );
  LGGM_PRINT_INT_C ( 1, ( *event ).msg.code );
  LGGM_CALL_OUT_C ( 1 );
}

/*---------------------------------------------------------------------------*/

static const event_handler_node_t s_event_hanlders[] =
{
  {{s_app_event_handler_1}},
  {{s_app_event_handler_2}}
};

/*---------------------------------------------------------------------------*/

static const event_handler_list_t s_event_handler_iist =
{
  .node = s_event_hanlders,
  .nodes_count = sizeof ( s_event_hanlders ) / sizeof ( event_handler_node_t )
};

/*---------------------------------------------------------------------------*/

static const step_event_machine_t s_app_step_event_machine =
{
  .list = &s_event_handler_iist,
  .event_puller = s_app_event_puller
};

/*---------------------------------------------------------------------------*/

const event_machine_t app_event_machine =
{
  .step_machine = &s_app_step_event_machine,
  .event_sleeper = s_event_sleeper
};
