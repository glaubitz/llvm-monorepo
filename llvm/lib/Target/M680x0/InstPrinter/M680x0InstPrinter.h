//===-- M680x0InstPrinter.h - Convert M680x0 MCInst to asm ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains declarations for an M680x0 MCInst printer.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_M680X0_INSTPRINTER_M680X0INSTPRINTER_H
#define LLVM_LIB_TARGET_M680X0_INSTPRINTER_M680X0INSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"

namespace llvm {

class TargetMachine;

class M680x0InstPrinter : public MCInstPrinter {
public:
  M680x0InstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                    const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  void printRegName(raw_ostream &OS, unsigned RegNo) const override;
  void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot,
                 const MCSubtargetInfo &STI) override;

  bool printAliasInstr(const MCInst *MI, raw_ostream &OS);
  void printCustomAliasOperand(const MCInst *MI, unsigned OpIdx,
                               unsigned PrintMethodIdx, raw_ostream &O);

private:
  void printOperand(const MCInst *MI, unsigned opNum, raw_ostream &O);
  void printImmediate(const MCInst *MI, int opNum, raw_ostream &O);
  /// Print register mask for MOVEM instruction in order D0-D7,A0-A7
  void printMoveMask(const MCInst *MI, int opNum, raw_ostream &O);
  /// Print register mask for MOVEM instruction in order A7-A0,D7-D0
  void printMoveMaskR(const MCInst *MI, int opNum, raw_ostream &O);
  void printDisp(const MCInst *MI, int opNum, raw_ostream &O);
  void printARIMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printARIPIMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printARIPDMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printARIDMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printARIIMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printAbsMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printPCDMem(const MCInst *MI, int opNum, raw_ostream &O);
  void printPCIMem(const MCInst *MI, int opNum, raw_ostream &O);

  //===----------------------------------------------------------------------===//
  // Specializations
  //===----------------------------------------------------------------------===//
  //
  void printPCRelImm(const MCInst *MI, int opNum, raw_ostream &O) {
    printOperand(MI, opNum, O);
  }

  void printARI8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIMem(MI, opNum, O);
  }
  void printARI16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIMem(MI, opNum, O);
  }
  void printARI32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIMem(MI, opNum, O);
  }

  void printARIPI8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIPIMem(MI, opNum, O);
  }
  void printARIPI16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIPIMem(MI, opNum, O);
  }
  void printARIPI32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIPIMem(MI, opNum, O);
  }

  void printARIPD8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIPDMem(MI, opNum, O);
  }
  void printARIPD16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIPDMem(MI, opNum, O);
  }
  void printARIPD32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIPDMem(MI, opNum, O);
  }

  void printARID8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIDMem(MI, opNum, O);
  }
  void printARID16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIDMem(MI, opNum, O);
  }
  void printARID32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIDMem(MI, opNum, O);
  }

  void printARII8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIIMem(MI, opNum, O);
  }
  void printARII16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIIMem(MI, opNum, O);
  }
  void printARII32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printARIIMem(MI, opNum, O);
  }

  void printAS8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printAbsMem(MI, opNum, O);
  }
  void printAS16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printAbsMem(MI, opNum, O);
  }
  void printAS32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printAbsMem(MI, opNum, O);
  }

  void printAL8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printAbsMem(MI, opNum, O);
  }
  void printAL16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printAbsMem(MI, opNum, O);
  }
  void printAL32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printAbsMem(MI, opNum, O);
  }

  void printPCD8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printPCDMem(MI, opNum, O);
  }
  void printPCD16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printPCDMem(MI, opNum, O);
  }
  void printPCD32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printPCDMem(MI, opNum, O);
  }

  void printPCI8Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printPCIMem(MI, opNum, O);
  }
  void printPCI16Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printPCIMem(MI, opNum, O);
  }
  void printPCI32Mem(const MCInst *MI, int opNum, raw_ostream &O) {
    printPCIMem(MI, opNum, O);
  }
};
} // end namespace llvm

#endif
