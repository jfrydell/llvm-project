//=== Duke250MachineFunctionInfo.h - Private data used for Duke250 ----*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Duke250 specific subclass of MachineFunctionInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Duke250_Duke250MACHINEFUNCTION_H
#define LLVM_LIB_TARGET_Duke250_Duke250MACHINEFUNCTION_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

/// Duke250FunctionInfo - This class is derived from MachineFunction private
/// Duke250 target-specific information for each MachineFunction.
class Duke250FunctionInfo : public MachineFunctionInfo {
private:
  MachineFunction &MF;

public:
  Duke250FunctionInfo(MachineFunction &MF) : MF(MF) {}
};

} // end of namespace llvm

#endif // end LLVM_LIB_TARGET_Duke250_Duke250MACHINEFUNCTION_H
