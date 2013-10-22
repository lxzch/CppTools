#pragma once
#ifndef CTWIN_H
#define CTWIN_H

#include <windows.h>
#include <CTBase>
#include <exception\CTWinException.h>

#define CTWIN_SUPPORT
#define CTWIN_SUPPORT_VERSION 0x01

struct CPPTOOLS_TYPE_API CTWinStartSettingA
{
	LPSECURITY_ATTRIBUTES p_process_security;
	LPSECURITY_ATTRIBUTES p_thread_security;
	BOOL is_inherit_handle;
	DWORD create_flag;
	LPVOID p_environment;
	std::string current_dir;
};

struct CPPTOOLS_TYPE_API CTWinStartSettingW
{
	LPSECURITY_ATTRIBUTES p_process_security;
	LPSECURITY_ATTRIBUTES p_thread_security;
	BOOL is_inherit_handle;
	DWORD create_flag;
	LPVOID p_environment;
	std::wstring current_dir;
};

typedef STARTUPINFOA		CTWinStartInfoA;
typedef STARTUPINFOW		CTWinStartInfoW;
typedef PROCESS_INFORMATION	CTWinProcessInfo;

_CT_WINDOWS_BEGIN

CPPTOOLS_INLINEFUNC_API inline
	bool CTCreateProcess(
		__ct_in_opt LPCSTR lpApplicationName,
		__ct_in_opt LPCSTR lpCommandLine,
		__ct_in_opt LPSECURITY_ATTRIBUTES lpProcessAttributes,
		__ct_in_opt LPSECURITY_ATTRIBUTES lpThreadAttributes,
		__ct_in BOOL bInheritHandles,
		__ct_in DWORD dwCreationFlags,
		__ct_in_opt LPVOID lpEnvironment,
		__ct_in_opt LPCSTR lpCurrentDirectory,
		__ct_in LPSTARTUPINFOA lpStartupInfo,
		__ct_out LPPROCESS_INFORMATION lpProcessInformation)
{			
	char* t_cmd = new char[strlen(lpCommandLine) + 1];
	strcpy(t_cmd, lpCommandLine);
	BOOL result;
	result = CreateProcessA(lpApplicationName,
		t_cmd,
		lpProcessAttributes,
		lpThreadAttributes,
		bInheritHandles,
		dwCreationFlags,
		lpEnvironment,
		lpCurrentDirectory,
		lpStartupInfo,
		lpProcessInformation);
	delete[] t_cmd;
	if(result == TRUE)
		return true;
	else
		return false;
}

CPPTOOLS_INLINEFUNC_API inline
	CTWinStartSettingA SetStartSetting(
		LPSECURITY_ATTRIBUTES p_process_security,
		LPSECURITY_ATTRIBUTES p_thread_security,
		BOOL is_inherit_handle,
		DWORD create_flag,
		LPVOID p_environment,
		const std::string& current_dir)
{
	CTWinStartSettingA wss =
	{
		p_process_security,
		p_thread_security,
		is_inherit_handle,
		create_flag,
		p_environment,
		current_dir
	};
	return wss;
}

CPPTOOLS_API CTWIN_SUPPORT
bool RunExeFile(
	const std::string& exefile,
	const std::string& cmdline,
	CTWinStartInfoA* start_info = NULL,
	CTWinProcessInfo* process_info = NULL,
	CTWinStartSettingA* setting = NULL);

CPPTOOLS_API CTWIN_SUPPORT
bool WaitExeClose(
	const CTWinProcessInfo& process_info,
	const DWORD max_wait_time = INFINITE,
	const DWORD period = 200);

_CT_WINDOWS_END

#endif /* CTWin.h */

