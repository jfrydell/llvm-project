//===-- Duke250MCAsmInfo.h - Duke250 Asm Info ------------------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the Duke250MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250MCASMINFO_H
#define LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250MCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
  class Triple;

class Duke250MCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit Duke250MCAsmInfo(const Triple &TheTriple);
};

} // namespace llvm

#endif // end LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250MCASMINFO_H
