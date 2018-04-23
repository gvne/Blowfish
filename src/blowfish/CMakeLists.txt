add_library(blowfish
  ${src}/blowfish/blowfish.cpp
  ${src}/blowfish/blowfish.h
)

install(TARGETS blowfish
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(FILES
  ${src}/blowfish/blowfish.h
  DESTINATION include/blowfish
)

if (${blowfish_enable_tests})
  add_executable(blowfish_test
    ${src}/blowfish/blowfish_test.cpp
  )
  add_dependencies(blowfish_test
    external_googletest
  )
  target_link_libraries(blowfish_test
    optimized gtest
    optimized gtest_main
    debug gtestd
    debug gtest_maind
    blowfish
  )
  target_include_directories(blowfish_test
    PUBLIC
      ${gtest_install_dir}/include
  )
endif()
