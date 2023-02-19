add_llvm_library( LLVMKarm MODULE BUILDTREE_ONLY
  Karm.cpp

  DEPENDS
  intrinsics_gen
  PLUGIN_TOOL
  opt
  )