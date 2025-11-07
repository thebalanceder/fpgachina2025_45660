// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xexact_loam_feature_extraction.h"

extern XExact_loam_feature_extraction_Config XExact_loam_feature_extraction_ConfigTable[];

#ifdef SDT
XExact_loam_feature_extraction_Config *XExact_loam_feature_extraction_LookupConfig(UINTPTR BaseAddress) {
	XExact_loam_feature_extraction_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XExact_loam_feature_extraction_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XExact_loam_feature_extraction_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XExact_loam_feature_extraction_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XExact_loam_feature_extraction_Initialize(XExact_loam_feature_extraction *InstancePtr, UINTPTR BaseAddress) {
	XExact_loam_feature_extraction_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XExact_loam_feature_extraction_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XExact_loam_feature_extraction_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XExact_loam_feature_extraction_Config *XExact_loam_feature_extraction_LookupConfig(u16 DeviceId) {
	XExact_loam_feature_extraction_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XEXACT_LOAM_FEATURE_EXTRACTION_NUM_INSTANCES; Index++) {
		if (XExact_loam_feature_extraction_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XExact_loam_feature_extraction_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XExact_loam_feature_extraction_Initialize(XExact_loam_feature_extraction *InstancePtr, u16 DeviceId) {
	XExact_loam_feature_extraction_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XExact_loam_feature_extraction_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XExact_loam_feature_extraction_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

