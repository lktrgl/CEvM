cmake_minimum_required(VERSION 3.5)

project ( CEvM )

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

if(NOT IS_SUBPROJECT)
	set ( CMAKE_C_STANDARD 99 )
	set ( CMAKE_CXX_STANDARD 17 )
	set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
	set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
else()
	set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNDEBUG" )
	set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG" )
endif()

add_subdirectory( contrib/lggm )

include_directories (
     include
     contrib/lggm/include
     )

set (libsources ${libsources}
     src/CEvM/event_machine.c
     include/CEvM/event_machine.h
     include/CEvM/event.h
     include/CEvM/event_handler.h
     include/CEvM/event_handler_list.h
     src/CEvM/step_event_machine.c
     include/CEvM/step_event_machine.h
     )

add_library ( cstm
    ${libsources}
     )

if(NOT IS_SUBPROJECT)
	add_executable(cstm_app
	     src/app/main.c
	     src/app/app_event_machine.c
	     include/app/app_event_machine.h
	     )
	
	target_link_libraries(cstm_app
	     cstm
	     lggm
	     )
endif()
