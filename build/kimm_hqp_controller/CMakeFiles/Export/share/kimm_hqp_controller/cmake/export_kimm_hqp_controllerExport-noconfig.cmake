#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "kimm_hqp_controller::kimm_hqp_controller" for configuration ""
set_property(TARGET kimm_hqp_controller::kimm_hqp_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(kimm_hqp_controller::kimm_hqp_controller PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libkimm_hqp_controller.so"
  IMPORTED_SONAME_NOCONFIG "libkimm_hqp_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS kimm_hqp_controller::kimm_hqp_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_kimm_hqp_controller::kimm_hqp_controller "${_IMPORT_PREFIX}/lib/libkimm_hqp_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
