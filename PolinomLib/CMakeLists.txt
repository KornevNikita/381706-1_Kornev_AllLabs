file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${PolinomLib} ${srcs} ${hdrs})


