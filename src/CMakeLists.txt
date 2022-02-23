add_executable(${PROJECT_NAME})
file (GLOB cpps  *.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${cpps})

target_link_libraries(${PROJECT_NAME} PRIVATE ui)
target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_subdirectory(ui)
