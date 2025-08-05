#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pak_hqp_controller::pak_hqp_controller" for configuration ""
set_property(TARGET pak_hqp_controller::pak_hqp_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pak_hqp_controller::pak_hqp_controller PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpak_hqp_controller.so"
  IMPORTED_SONAME_NOCONFIG "libpak_hqp_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pak_hqp_controller::pak_hqp_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_pak_hqp_controller::pak_hqp_controller "${_IMPORT_PREFIX}/lib/libpak_hqp_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
