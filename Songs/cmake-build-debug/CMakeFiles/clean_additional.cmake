# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\L11L12_songs_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\L11L12_songs_autogen.dir\\ParseCache.txt"
  "L11L12_songs_autogen"
  )
endif()
