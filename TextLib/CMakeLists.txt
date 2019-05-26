file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${TextLib} ${srcs} ${hdrs})


