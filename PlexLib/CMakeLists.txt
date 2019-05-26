file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${PlexLib} ${srcs} ${hdrs})


