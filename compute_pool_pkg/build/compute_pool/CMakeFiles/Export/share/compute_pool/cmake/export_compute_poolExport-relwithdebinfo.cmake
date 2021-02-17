#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "compute_pool::compute_job" for configuration "RelWithDebInfo"
set_property(TARGET compute_pool::compute_job APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(compute_pool::compute_job PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcompute_job.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libcompute_job.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS compute_pool::compute_job )
list(APPEND _IMPORT_CHECK_FILES_FOR_compute_pool::compute_job "${_IMPORT_PREFIX}/lib/libcompute_job.so" )

# Import target "compute_pool::compute_orch" for configuration "RelWithDebInfo"
set_property(TARGET compute_pool::compute_orch APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(compute_pool::compute_orch PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcompute_orch.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libcompute_orch.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS compute_pool::compute_orch )
list(APPEND _IMPORT_CHECK_FILES_FOR_compute_pool::compute_orch "${_IMPORT_PREFIX}/lib/libcompute_orch.so" )

# Import target "compute_pool::onnx_yolov3" for configuration "RelWithDebInfo"
set_property(TARGET compute_pool::onnx_yolov3 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(compute_pool::onnx_yolov3 PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libonnx_yolov3.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libonnx_yolov3.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS compute_pool::onnx_yolov3 )
list(APPEND _IMPORT_CHECK_FILES_FOR_compute_pool::onnx_yolov3 "${_IMPORT_PREFIX}/lib/libonnx_yolov3.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
