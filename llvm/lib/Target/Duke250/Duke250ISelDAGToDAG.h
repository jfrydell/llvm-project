//===---- Duke250ISelDAGToDAG.h - A Dag to Dag Inst Selector for Duke250 ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the Duke250 target.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Duke250_Duke250ISELDAGTODAG_H
#define LLVM_LIB_TARGET_Duke250_Duke250ISELDAGTODAG_H

#include "Duke250Subtarget.h"
#include "Duke250TargetMachine.h"
#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {
class Duke250DAGToDAGISel : public SelectionDAGISel {
public:
  explicit Duke250DAGToDAGISel(Duke250TargetMachine &TM, CodeGenOpt::Level OL)
      : SelectionDAGISel(TM, OL), Subtarget(nullptr) {}

  // Pass Name
  StringRef getPassName() const override {
    return "CPU0 DAG->DAG Pattern Instruction Selection";
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

  void Select(SDNode *Node) override;

#include "Duke250GenDAGISel.inc"

private:
  const Duke250Subtarget *Subtarget;
};
}

#endif // end LLVM_LIB_TARGET_Duke250_Duke250ISELDAGTODAG_H
