set(LIB_NAME ui)
add_library(${LIB_NAME} OBJECT)
file (GLOB cpps  *.cpp)

target_sources(${LIB_NAME} PRIVATE ${cpps})
target_link_libraries(${LIB_NAME} PUBLIC pthread)
target_link_libraries(${LIB_NAME} PUBLIC ${wxWidgets_LIBRARIES})

