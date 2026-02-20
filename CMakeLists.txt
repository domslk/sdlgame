cmake_minimum_required(VERSION 3.16)

project(
  GAME
  VERSION 1.0
  DESCRIPTION "sdl game"
)



#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")


#add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)


find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(Game 
  src/main.cpp
  src/Game.cpp
)


if(APPLE)
  set_target_properties(Game PROPERTIES
    INSTALL_RPATH "@executable_path;@loader_path"
    BUILD_WITH_INSTALL_RPATH TRUE
    MACOSX_RPATH TRUE
  )
elseif(UNIX)
  set_target_properties(Game PROPERTIES
    INSTALL_RPATH "$ORIGIN"
    BUILD_WITH_INSTALL_RPATH TRUE
  )
endif()


target_link_libraries(
  Game PRIVATE SDL3::SDL3
  SDL3_image::SDL3_image
)
