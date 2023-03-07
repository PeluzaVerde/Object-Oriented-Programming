# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cuet_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cuet_autogen.dir\\ParseCache.txt"
  "cuet_autogen"
  )
endif()
