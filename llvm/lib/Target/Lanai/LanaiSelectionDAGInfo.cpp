//===-- LanaiSelectionDAGInfo.cpp - Lanai SelectionDAG Info -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the LanaiSelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#include "LanaiSelectionDAGInfo.h"

#define GET_SDNODE_DESC
#include "LanaiGenSDNodeInfo.inc"

#define DEBUG_TYPE "lanai-selectiondag-info"

using namespace llvm;

LanaiSelectionDAGInfo::LanaiSelectionDAGInfo()
    : SelectionDAGGenTargetInfo(LanaiGenSDNodeInfo) {}

SDValue LanaiSelectionDAGInfo::EmitTargetCodeForMemcpy(
    SelectionDAG & /*DAG*/, const SDLoc & /*dl*/, SDValue /*Chain*/,
    SDValue /*Dst*/, SDValue /*Src*/, SDValue Size, Align /*Alignment*/,
    bool /*isVolatile*/, bool /*AlwaysInline*/,
    MachinePointerInfo /*DstPtrInfo*/,
    MachinePointerInfo /*SrcPtrInfo*/) const {
  ConstantSDNode *ConstantSize = dyn_cast<ConstantSDNode>(Size);
  if (!ConstantSize)
    return SDValue();

  return SDValue();
}
