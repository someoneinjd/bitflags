set(warning_guard "")
if(NOT PROJECT_IS_TOP_LEVEL)
  option(
      alignment_INCLUDES_WITH_SYSTEM
      "Use SYSTEM modifier for alignment's includes, disabling warnings"
      ON
  )
  mark_as_advanced(alignment_INCLUDES_WITH_SYSTEM)
  if(alignment_INCLUDES_WITH_SYSTEM)
    set(warning_guard SYSTEM)
  endif()
endif()
