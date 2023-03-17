//===-- Duke250MCTargetDesc.cpp - Duke250 Target Descriptions -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Duke250 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "Duke250MCTargetDesc.h"
#include "Duke250InstPrinter.h"
#include "Duke250MCAsmInfo.h"
#include "TargetInfo/Duke250TargetInfo.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "Duke250GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "Duke250GenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "Duke250GenRegisterInfo.inc"

static MCInstrInfo *createDuke250MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitDuke250MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createDuke250MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  return X;
}

static MCSubtargetInfo *
createDuke250MCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  std::string CPUName = CPU;
  if (CPUName.empty())
    CPUName = "generic";
  return createDuke250MCSubtargetInfoImpl(TT, CPUName, FS);
}

static MCInstPrinter *createDuke250MCInstPrinter(const Triple &T,
                                               unsigned SyntaxVariant,
                                               const MCAsmInfo &MAI,
                                               const MCInstrInfo &MII,
                                               const MCRegisterInfo &MRI) {
  return new Duke250InstPrinter(MAI, MII, MRI);
}

static MCAsmInfo *createDuke250MCAsmInfo(const MCRegisterInfo &MRI,
                                       const Triple &TT,
                                       const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new Duke250MCAsmInfo(TT);

  unsigned WP = MRI.getDwarfRegNum(Duke250::r6, true);
  MCCFIInstruction Inst = MCCFIInstruction::createDefCfa(nullptr, WP, 0);
  MAI->addInitialFrameState(Inst);

  return MAI;
}

extern "C" void LLVMInitializeDuke250TargetMC() {
  for (Target *T : {&getTheDuke250Target()}) {
    // Register the MC asm info.
    TargetRegistry::RegisterMCAsmInfo(*T, createDuke250MCAsmInfo);

    // Register the MC instruction info.
    TargetRegistry::RegisterMCInstrInfo(*T, createDuke250MCInstrInfo);

    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(*T, createDuke250MCRegisterInfo);

    // Register the MC subtarget info.
    TargetRegistry::RegisterMCSubtargetInfo(*T, createDuke250MCSubtargetInfo);

    // Register the MCInstPrinter.
    TargetRegistry::RegisterMCInstPrinter(*T, createDuke250MCInstPrinter);
  }
}
