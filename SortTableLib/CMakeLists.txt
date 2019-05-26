file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${SortTableLib} STATIC ${srcs} ${hdrs}) 

