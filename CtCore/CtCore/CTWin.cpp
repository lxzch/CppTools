#include "stdafx.h"
#include <core\CTWin.h>

bool CppTools::CTWindows::RunExeFile(const std::string& exefile,
									 const std::string& cmdline,
									 CTWinStartInfoA* start_info,
									 CTWinProcessInfo* process_info,
									 CTWinStartSettingA* setting)
{
	if(!start_info)
	{
		CTWinStartInfoA t_si = { sizeof(t_si) };
		start_info = &t_si;
	}
	if(!process_info)
	{
		CTWinProcessInfo t_pi;
		process_info = &t_pi;
	}
	if(!setting)
	{
		CTWinStartSettingA t_ss;
		t_ss.p_process_security = NULL;
		t_ss.p_thread_security = NULL;
		t_ss.is_inherit_handle = FALSE;
		t_ss.create_flag = 0;
		t_ss.p_environment = NULL;
		t_ss.current_dir = "";
		setting = &t_ss;
	}
	if(setting->current_dir == "")
	{
		if(exefile.size() == 0)
		{
			return CTCreateProcess(NULL,
				cmdline.c_str(),
				setting->p_process_security,
				setting->p_thread_security,
				setting->is_inherit_handle,
				setting->create_flag,
				setting->p_environment,
				NULL,
				start_info,
				process_info);
		}
		else
		{
			return CTCreateProcess(exefile.c_str(),
				cmdline.c_str(),
				setting->p_process_security,
				setting->p_thread_security,
				setting->is_inherit_handle,
				setting->create_flag,
				setting->p_environment,
				NULL,
				start_info,
				process_info);
		}
	}
	else
	{
		if(exefile.size() == 0)
		{
			return CTCreateProcess(NULL,
				cmdline.c_str(),
				setting->p_process_security,
				setting->p_thread_security,
				setting->is_inherit_handle,
				setting->create_flag,
				setting->p_environment,
				setting->current_dir.c_str(),
				start_info,
				process_info);
		}
		else
		{
			return CTCreateProcess(exefile.c_str(),
				cmdline.c_str(),
				setting->p_process_security,
				setting->p_thread_security,
				setting->is_inherit_handle,
				setting->create_flag,
				setting->p_environment,
				setting->current_dir.c_str(),
				start_info,
				process_info);
		}
	}
	return false;
}

bool CppTools::CTWindows::WaitExeClose(const CTWinProcessInfo& process_info,
									   const DWORD max_wait_time,
									   const DWORD period)
{
	DWORD ExitCode;
	GetExitCodeProcess(process_info.hProcess, &ExitCode);
	if(max_wait_time == INFINITE)
	{
		while(ExitCode == STILL_ACTIVE)
		{
			Sleep(period);
			GetExitCodeProcess(process_info.hProcess, &ExitCode);
		}
	}
	else
	{
		DWORD t = 0;
		while(ExitCode == STILL_ACTIVE)
		{
			if(t > max_wait_time)
				return false;
			Sleep(period);
			GetExitCodeProcess(process_info.hProcess, &ExitCode);
			t += period;
		}
	}
	return true;
}