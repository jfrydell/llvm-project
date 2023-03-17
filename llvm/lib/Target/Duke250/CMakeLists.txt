set(LLVM_TARGET_DEFINITIONS Duke250.td)

tablegen(LLVM Duke250GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM Duke250GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM Duke250GenCodeEmitter.inc -gen-emitter)
tablegen(LLVM Duke250GenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM Duke250GenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM Duke250GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM Duke250GenCallingConv.inc -gen-callingconv)
tablegen(LLVM Duke250GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM Duke250GenMCPseudoLowering.inc -gen-pseudo-lowering)

# Duke250CommonTableGen must be defined
add_public_tablegen_target(Duke250CommonTableGen)

# Duke250CodeGen should match with LLVMBuild.txt Duke250CodeGen
add_llvm_target(Duke250CodeGen
  Duke250AsmPrinter.cpp
  Duke250FrameLowering.cpp
  Duke250InstrInfo.cpp
  Duke250ISelLowering.cpp
  Duke250RegisterInfo.cpp
  Duke250Subtarget.cpp
  Duke250TargetObjectFile.cpp
  Duke250ISelDAGToDAG.cpp
  Duke250TargetMachine.cpp
)

# Should match with "subdirectories =  MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
