cmake_minimum_required(VERSION 2.8)
project(swarm_robotics)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIR} )
include_directories( include )


set(SHARED_SRC 
	src/voronoi_diagram_generator.cpp
	src/coverage.cpp
	src/patrolling.cpp
	src/graphs.cpp
	include/voronoi_diagram_generator.h
	include/coverage.h
	include/patrolling.h
	include/utils.h
	include/graphs.h
	)

set( VORONOI_MAIN src/voronoi_main.cpp ${SHARED_SRC})

add_executable( voronoi_main ${VORONOI_MAIN})

target_link_libraries(voronoi_main ${OpenCV_LIBS})
