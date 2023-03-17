//===-- Duke250BaseInfo.h - Top level definitions for Duke250 MC ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains small standalone enum definitions for the Duke250 target
// useful for the compiler back-end and the MC libraries.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250BASEINFO_H
#define LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250BASEINFO_H

#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/SubtargetFeature.h"

namespace llvm {

// Duke250II - This namespace holds all of the target specific flags that
// instruction info tracks. All definitions must match Duke250InstrFormats.td.
namespace Duke250II {
enum {
  InstFormatPseudo = 0,
  InstFormatR = 1,
  InstFormatR4 = 2,
  InstFormatI = 3,
  InstFormatS = 4,
  InstFormatB = 5,
  InstFormatU = 6,
  InstFormatJ = 7,
  InstFormatCR = 8,
  InstFormatCI = 9,
  InstFormatCSS = 10,
  InstFormatCIW = 11,
  InstFormatCL = 12,
  InstFormatCS = 13,
  InstFormatCA = 14,
  InstFormatCB = 15,
  InstFormatCJ = 16,
  InstFormatOther = 17,

  InstFormatMask = 31
};

} // namespace Duke250II

namespace Duke250Op {
enum OperandType : unsigned {
  OPERAND_FIRST_Duke250_IMM = MCOI::OPERAND_FIRST_TARGET,
  OPERAND_UIMM4 = OPERAND_FIRST_Duke250_IMM,
  OPERAND_UIMM5,
  OPERAND_UIMM6,
  OPERAND_SIMM6,
  OPERAND_SIMM13_LSB0,
  OPERAND_UIMM20,
  OPERAND_SIMM21_LSB0,
  OPERAND_UIMMLOG2WSIZE,
  OPERAND_LAST_Duke250_IMM = OPERAND_UIMMLOG2WSIZE
};
} // namespace Duke250Op

} // namespace llvm

#endif
