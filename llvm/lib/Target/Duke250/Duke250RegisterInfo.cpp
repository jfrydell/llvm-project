//===-- Duke250RegisterInfo.cpp - Duke250 Register Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Duke250 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "Duke250RegisterInfo.h"
#include "Duke250Subtarget.h"
#include "llvm/Support/Debug.h"

#define GET_REGINFO_TARGET_DESC
#include "Duke250GenRegisterInfo.inc"

#define DEBUG_TYPE "Duke250-reginfo"

using namespace llvm;

Duke250RegisterInfo::Duke250RegisterInfo(const Duke250Subtarget &ST)
  : Duke250GenRegisterInfo(Duke250::r1, /*DwarfFlavour*/0, /*EHFlavor*/0,
                         /*PC*/0), Subtarget(ST) {}

const MCPhysReg *
Duke250RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return Duke250_CalleeSavedRegs_SaveList;
}

const TargetRegisterClass *Duke250RegisterInfo::intRegClass(unsigned Size) const {
  return &Duke250::GPRRegClass;
}

const uint32_t *
Duke250RegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                        CallingConv::ID) const {
  return Duke250_CalleeSavedRegs_RegMask;
}

BitVector Duke250RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());

  markSuperRegs(Reserved, Duke250::r0); // zero
  markSuperRegs(Reserved, Duke250::r6); // sp
  markSuperRegs(Reserved, Duke250::r7); // link

  return Reserved;
}

void Duke250RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                           int SPAdj,
                                           unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  llvm_unreachable("Unsupported eliminateFrameIndex");
}

bool
Duke250RegisterInfo::requiresRegisterScavenging(const MachineFunction &MF) const {
  return true;
}

bool
Duke250RegisterInfo::requiresFrameIndexScavenging(
                                            const MachineFunction &MF) const {
  return true;
}

bool
Duke250RegisterInfo::requiresFrameIndexReplacementScavenging(
                                            const MachineFunction &MF) const {
  return true;
}

bool
Duke250RegisterInfo::trackLivenessAfterRegAlloc(const MachineFunction &MF) const {
  return true;
}

Register Duke250RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  llvm_unreachable("Unsupported getFrameRegister");
}

