// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XEXACT_LOAM_FEATURE_EXTRACTION_H
#define XEXACT_LOAM_FEATURE_EXTRACTION_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xexact_loam_feature_extraction_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XExact_loam_feature_extraction_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XExact_loam_feature_extraction;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XExact_loam_feature_extraction_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XExact_loam_feature_extraction_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XExact_loam_feature_extraction_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XExact_loam_feature_extraction_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XExact_loam_feature_extraction_Initialize(XExact_loam_feature_extraction *InstancePtr, UINTPTR BaseAddress);
XExact_loam_feature_extraction_Config* XExact_loam_feature_extraction_LookupConfig(UINTPTR BaseAddress);
#else
int XExact_loam_feature_extraction_Initialize(XExact_loam_feature_extraction *InstancePtr, u16 DeviceId);
XExact_loam_feature_extraction_Config* XExact_loam_feature_extraction_LookupConfig(u16 DeviceId);
#endif
int XExact_loam_feature_extraction_CfgInitialize(XExact_loam_feature_extraction *InstancePtr, XExact_loam_feature_extraction_Config *ConfigPtr);
#else
int XExact_loam_feature_extraction_Initialize(XExact_loam_feature_extraction *InstancePtr, const char* InstanceName);
int XExact_loam_feature_extraction_Release(XExact_loam_feature_extraction *InstancePtr);
#endif

void XExact_loam_feature_extraction_Start(XExact_loam_feature_extraction *InstancePtr);
u32 XExact_loam_feature_extraction_IsDone(XExact_loam_feature_extraction *InstancePtr);
u32 XExact_loam_feature_extraction_IsIdle(XExact_loam_feature_extraction *InstancePtr);
u32 XExact_loam_feature_extraction_IsReady(XExact_loam_feature_extraction *InstancePtr);
void XExact_loam_feature_extraction_EnableAutoRestart(XExact_loam_feature_extraction *InstancePtr);
void XExact_loam_feature_extraction_DisableAutoRestart(XExact_loam_feature_extraction *InstancePtr);

void XExact_loam_feature_extraction_Set_point_count(XExact_loam_feature_extraction *InstancePtr, u32 Data);
u32 XExact_loam_feature_extraction_Get_point_count(XExact_loam_feature_extraction *InstancePtr);

void XExact_loam_feature_extraction_InterruptGlobalEnable(XExact_loam_feature_extraction *InstancePtr);
void XExact_loam_feature_extraction_InterruptGlobalDisable(XExact_loam_feature_extraction *InstancePtr);
void XExact_loam_feature_extraction_InterruptEnable(XExact_loam_feature_extraction *InstancePtr, u32 Mask);
void XExact_loam_feature_extraction_InterruptDisable(XExact_loam_feature_extraction *InstancePtr, u32 Mask);
void XExact_loam_feature_extraction_InterruptClear(XExact_loam_feature_extraction *InstancePtr, u32 Mask);
u32 XExact_loam_feature_extraction_InterruptGetEnabled(XExact_loam_feature_extraction *InstancePtr);
u32 XExact_loam_feature_extraction_InterruptGetStatus(XExact_loam_feature_extraction *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
