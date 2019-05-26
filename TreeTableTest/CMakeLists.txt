
file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


add_executable(${TreeTableTest} ${srcs} ${hdrs}) 
target_link_libraries(${TreeTableTest} ${TreeTabLib} gtest )
