// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xexact_loam_feature_extraction.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XExact_loam_feature_extraction_CfgInitialize(XExact_loam_feature_extraction *InstancePtr, XExact_loam_feature_extraction_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XExact_loam_feature_extraction_Start(XExact_loam_feature_extraction *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL) & 0x80;
    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XExact_loam_feature_extraction_IsDone(XExact_loam_feature_extraction *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XExact_loam_feature_extraction_IsIdle(XExact_loam_feature_extraction *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XExact_loam_feature_extraction_IsReady(XExact_loam_feature_extraction *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XExact_loam_feature_extraction_EnableAutoRestart(XExact_loam_feature_extraction *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XExact_loam_feature_extraction_DisableAutoRestart(XExact_loam_feature_extraction *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_AP_CTRL, 0);
}

void XExact_loam_feature_extraction_Set_point_count(XExact_loam_feature_extraction *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_POINT_COUNT_DATA, Data);
}

u32 XExact_loam_feature_extraction_Get_point_count(XExact_loam_feature_extraction *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_POINT_COUNT_DATA);
    return Data;
}

void XExact_loam_feature_extraction_InterruptGlobalEnable(XExact_loam_feature_extraction *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_GIE, 1);
}

void XExact_loam_feature_extraction_InterruptGlobalDisable(XExact_loam_feature_extraction *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_GIE, 0);
}

void XExact_loam_feature_extraction_InterruptEnable(XExact_loam_feature_extraction *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_IER);
    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_IER, Register | Mask);
}

void XExact_loam_feature_extraction_InterruptDisable(XExact_loam_feature_extraction *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_IER);
    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_IER, Register & (~Mask));
}

void XExact_loam_feature_extraction_InterruptClear(XExact_loam_feature_extraction *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XExact_loam_feature_extraction_WriteReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_ISR, Mask);
}

u32 XExact_loam_feature_extraction_InterruptGetEnabled(XExact_loam_feature_extraction *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_IER);
}

u32 XExact_loam_feature_extraction_InterruptGetStatus(XExact_loam_feature_extraction *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XExact_loam_feature_extraction_ReadReg(InstancePtr->Control_BaseAddress, XEXACT_LOAM_FEATURE_EXTRACTION_CONTROL_ADDR_ISR);
}

