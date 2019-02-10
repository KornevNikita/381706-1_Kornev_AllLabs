file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Polinom} ${srcs} ${hdrs}) 

target_link_libraries(${Polinom} ${PolinomLib})