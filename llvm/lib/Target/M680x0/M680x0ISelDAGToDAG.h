//===---- M680x0ISelDAGToDAG.h - A Dag to Dag Inst Selector for M680x0 --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the M680X0 target.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_M680X0_M680X0ISELDAGTODAG_H
#define LLVM_LIB_TARGET_M680X0_M680X0ISELDAGTODAG_H

#include "M680x0.h"
#include "M680x0Subtarget.h"
#include "M680x0TargetMachine.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/Debug.h"

//===----------------------------------------------------------------------===//
// Instruction Selector Implementation
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// M680x0DAGToDAGISel - M680X0 specific code to select M680X0 machine
// instructions for SelectionDAG operations.
//===----------------------------------------------------------------------===//
namespace llvm {

class M680x0DAGToDAGISel : public SelectionDAGISel {
public:
  explicit M680x0DAGToDAGISel(M680x0TargetMachine &TM)
      : SelectionDAGISel(TM), Subtarget(nullptr) {}

  const char *getPassName() const override {
    return "M680X0 DAG->DAG Pattern Instruction Selection";
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

private:
  /// Keep a pointer to the X86Subtarget around so that we can
  /// make the right decision when generating code for different targets.
  const M680x0Subtarget *Subtarget;

  // Include the pieces autogenerated from the target description.
  #include "M680x0GenDAGISel.inc"

  /// getTargetMachine - Return a reference to the TargetMachine, casted
  /// to the target-specific type.
  const M680x0TargetMachine &getTargetMachine() {
    return static_cast<const M680x0TargetMachine &>(TM);
  }

  void Select(SDNode *N) override;

  // Insert instructions to initialize the global base register in the
  // first MBB of the function.
  // HMM... do i need this?
  void initGlobalBaseReg(MachineFunction &MF);

  std::pair<bool, SDNode*> selectNode(SDNode *Node);

  // Complex Patterns
  bool selectARIPI(SDNode *Parent, SDValue N, SDValue &Base);

  bool selectARID(SDNode *Parent, SDValue N, SDValue &Imm, SDValue &Base);

  bool selectARIIw(SDNode *Parent, SDValue N,
                    SDValue &Imm, SDValue &Base, SDValue &Index);
  bool selectARIIl(SDNode *Parent, SDValue N,
                    SDValue &Imm, SDValue &Base, SDValue &Index);

};

FunctionPass *createM680x0ISelDag(M680x0TargetMachine &TM);

}

#endif
