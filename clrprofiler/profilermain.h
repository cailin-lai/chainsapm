// profilermain.h : Declaration of the Cprofilermain
#ifndef PROFILERMAIN_H
#define PROFILERMAIN_H


EXTERN_C void FunctionEnter2_Wrapper_x64(FunctionID funcId, UINT_PTR clientData, COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_RANGE *argumentInfo);

EXTERN_C void FunctionLeave2_Wrapper_x64(FunctionID funcId, UINT_PTR clientData, COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_RANGE *argumentInfo);

EXTERN_C void FunctionTail2_Wrapper_x64(FunctionID funcId, UINT_PTR clientData, COR_PRF_FRAME_INFO func);

EXTERN_C void FunctionEnter2_CPP_STUB(FunctionID funcId, UINT_PTR clientData,
	COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo);

EXTERN_C void FunctionLeave2_CPP_STUB(FunctionID funcId, UINT_PTR clientData,
	COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_RANGE *argumentRange);

EXTERN_C void FunctionTail2_CPP_STUB(FunctionID funcId, UINT_PTR clientData,
	COR_PRF_FRAME_INFO func);

#pragma once
#include "resource.h"       // main symbols

//#include "ICorProlfileInfoCallbacks.h"
#include "commonstructures.h"
#include "clrprofiler_i.h"
#include <cor.h>
#include <corprof.h>

//#include "NetworkClient.h"
#include "MetadataHelpers.h"
#include "FunctionInfo.h"
#include "ThreadStackItem.h"
#include "TimerItem.h"
#include "CorProfilerCallbackImplementation.h"
#include <http.h>

struct ContainerClass;



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// Cprofilermain

class ATL_NO_VTABLE Cprofilermain :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Cprofilermain, &CLSID_profilermain>,
	public CorProfilerCallbackImplementation
{
public:

	Cprofilermain();
	~Cprofilermain();

	
	/*
	//MgdGetRequestBasics(
	class W3_MGD_HANDLER *,
	long *,
	long *,
	unsigned short const * *,
	unsigned long *,
	unsigned short const * *,
	unsigned long *,
	char const * *,
	struct _HTTP_COOKED_URL * *))
	*/
	//[DllImport("webengine4.dll", CharSet = CharSet.None, ExactSpelling = false)]
	//internal static extern int MgdGetRequestBasics(IntPtr pRequestContext, out int pContentType, 
	//out int pContentTotalLength, out IntPtr pPathTranslated, out int pcchPathTranslated, out IntPtr pCacheUrl, out int pcchCacheUrl, 
	//out IntPtr pHttpMethod, out IntPtr pCookedUrl);

	

	DECLARE_REGISTRY_RESOURCEID(IDR_PROFILERMAIN)


	BEGIN_COM_MAP(Cprofilermain)
		COM_INTERFACE_ENTRY(ICorProfilerCallback)
		COM_INTERFACE_ENTRY(ICorProfilerCallback2)
		COM_INTERFACE_ENTRY(ICorProfilerCallback3)
		COM_INTERFACE_ENTRY(ICorProfilerCallback4)
		COM_INTERFACE_ENTRY(ICorProfilerCallback5)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	// First method run when the CLR profiler spins up.
	STDMETHOD(Initialize)(IUnknown *pICorProfilerInfoUnk);

	STDMETHOD(AppDomainCreationStarted)(AppDomainID appDomainId);
	// Method that is run when we start a new .NET thread. This method will add our threads to the appropriate 
	STDMETHOD(ThreadCreated)(ThreadID threadId);
	STDMETHOD(ThreadDestroyed)(ThreadID threadId);
	STDMETHOD(ThreadNameChanged)(ThreadID threadId, ULONG cchName, _In_reads_opt_(cchName) WCHAR name[]);
	STDMETHOD(SetMask)();
	STDMETHOD(GetFullMethodName)(FunctionID functionID, std::string *methodName, int cMethod);
	STDMETHOD(GetFuncArgs)(FunctionID functionID, COR_PRF_FRAME_INFO frameinfo);
	STDMETHOD(ModuleLoadStarted)(ModuleID moduleId);
	STDMETHOD(ModuleLoadFinished)(ModuleID moduleId, HRESULT hrStatus);
	STDMETHOD(ClassLoadFinished)(ClassID classId, HRESULT hrStatus);

	STDMETHOD(GarbageCollectionStarted)(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason);
	STDMETHOD(GarbageCollectionFinished)(void);

	STDMETHOD(RuntimeThreadSuspended)(ThreadID threadId);
	STDMETHOD(RuntimeThreadResumed)(ThreadID threadId);

	STDMETHOD(RuntimeSuspendStarted)(COR_PRF_SUSPEND_REASON suspendReason);
	STDMETHOD(RuntimeSuspendFinished)(void);
	STDMETHOD(RuntimeSuspendAborted)(void);
	STDMETHOD(RuntimeResumeStarted)(void);
	STDMETHOD(RuntimeResumeFinished)(void);

	UINT_PTR MapFunction(FunctionID funcId, UINT_PTR clientData, BOOL *pbHookFunction);


	void WriteLogFile(int fileNum);
	void AddCommonFunctions();
	void SetProcessName();


	// Enter call back for ICorProfilerCallback
	void FunctionEnterHook2(FunctionID funcId, UINT_PTR clientData,
		COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo);
	// Leave call back for ICorProfilerCallback
	void FunctionLeaveHook2(FunctionID funcId, UINT_PTR clientData,
		COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_RANGE *argumentRange);
	// Tail call back for ICorProfilerCallback
	void FunctionTailHook2(FunctionID funcId, UINT_PTR clientData,
		COR_PRF_FRAME_INFO func);

	// Enter call back for ICorProfilerCallback
	void FunctionEnterHook3(FunctionID funcId, UINT_PTR clientData,
		COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo);
	// Leave call back for ICorProfilerCallback
	void FunctionLeaveHook3(FunctionID funcId, UINT_PTR clientData,
		COR_PRF_FRAME_INFO func, COR_PRF_FUNCTION_ARGUMENT_RANGE *argumentRange);
	// Tail call back for ICorProfilerCallback
	void FunctionTailHook3(FunctionID funcId, UINT_PTR clientData,
		COR_PRF_FRAME_INFO func);


	// Mapper call back for ICorProfilerCallback
	static UINT_PTR __stdcall Mapper1(FunctionID funcId, BOOL *pbHookFunction);
	// Mapper call back for ICorProfilerCallback, calls Mapper1
	static UINT_PTR __stdcall Mapper2(FunctionID funcId, UINT_PTR clientData, BOOL *pbHookFunction);


	static std::map<UINT_PTR, Cprofilermain*> * g_StaticContainerClass;
	
	//// Metadata interface for getting function information
	//static MetadataHelpers *  g_MetadataHelpers;

	//// As a function is mapped we want to keep a reference to it's specific details so we can 
	//// use it again when generating the call stack.
	//static std::map<FunctionID, FunctionInfo> * g_FunctionSet;
	//// Holds pointers to StackItemBase polymorphic class. This class is an extensible map of objects
	//// that describe the state of this thread.
	//static std::map<ThreadID, std::queue<StackItemBase*>> * g_ThreadStackMap;
	//// Holds the current depth of the stack based on the Enter / Leave / Tail calls
	//static std::map<ThreadID, volatile unsigned int> * g_ThreadStackDepth;
	//// Holds the current sequence of the stack items
	//static std::map<ThreadID, volatile unsigned int> * g_ThreadStackSequence;
	//// Holds the current number of functions that we've entered and exited. This will be used to stop
	//// further additions to the stack. This really won't change performance too drastically, however it
	//// will allow us to save memory
	//static std::map<ThreadID, volatile unsigned int> * g_ThreadFunctionCount;
	//// This map is used to link together two threads as a parent and child. 
	//static std::map<ThreadID, UINT_PTR> * g_ThreadSpawnMap;

	//// This is a structure to hold two or more instances of the Cprofilermain class that will
	//// spawn the ICorProfiler* classes. This is used in instances where a SxS scenario is active
	//// As of 08/16/2014 we have not implemented this.
	//static std::map<DWORD, Cprofilermain*> * g_InstanceMap;

	//// **************************************** TESTING CLASSES ****************************************
	//// This collection is used to validate that we should be mapping this function. As of right now,
	//// for testing, we have this in both the mapper function and the ELT functions. Once we're out of
	//// the testing phase this collection will only be used in the mapper and we can remove the extraneous
	//// call to the find() method in the hooks.
	//static std::unordered_set<std::wstring> * g_FunctionNameSet;
	//// This collection is used to validate that we should be mapping this entire class. As of right now,
	//// for testing, we have this in both the mapper function and the ELT functions. Once we're out of
	//// the testing phase this collection will only be used in the mapper and we can remove the extraneous
	//// call to the find() method in the hooks.
	//static std::unordered_set<std::wstring> * g_ClassNameSet;
	//// **************************************** TESTING CLASSES ****************************************

	/************************************************************************************
	!!!NOTE!!!!

	Starting with version 4.0 .NET now allows side-by-side loading of the CLR. In order
	to be a good profiling citizen we are going to support "profile many" from the
	following link:
	http://msdn.microsoft.com/en-us/library/ee461607(v=vs.110).aspx

	In order to do this we need to account for what possible versions of the CLR can be
	loaded and we need to make sure that we don't "cross the streams." So, in order
	to do that cleanly I will implement MULTIPLE structures.

	This will cause some application bloat but will allow for clean operation.
	************************************************************************************/

private:
	// Highest available API
	byte m_HighestProfileInfo;
	// container for ICorProfilerInfo reference
	std::shared_ptr<ICorProfilerInfo> m_pICorProfilerInfo;
	// container for ICorProfilerInfo2 reference
	std::shared_ptr<ICorProfilerInfo2> m_pICorProfilerInfo2;
	// container for ICorProfilerInfo3 reference
	std::shared_ptr<ICorProfilerInfo3> m_pICorProfilerInfo3;
	// container for ICorProfilerInfo4 reference
	std::shared_ptr<ICorProfilerInfo4> m_pICorProfilerInfo4;


	// container for IL allocation
	std::shared_ptr<IMethodMalloc> m_pIMethodMalloc;
	//std::map<FunctionID, FunctionInfo> m_FunctionInfoMap;
	COR_PRF_SUSPEND_REASON m_CurrentSuspendReason;
	COR_PRF_GC_REASON m_CurrentGCReason;
	BOOL m_IsRuntimeSuspended;
	std::wstring m_ProcessName;
	DWORD m_ProcessId;
	HMODULE m_webengineHandle;

	// This is the all encompasing container class used by this class
	ContainerClass * m_Container;

	//NetworkClient *m_NetworkClient = NULL;

};

OBJECT_ENTRY_AUTO(__uuidof(profilermain), Cprofilermain)

class NetworkClient
{
public:
	NetworkClient(Cprofilermain *profMain, std::wstring hostName, std::wstring port);
	~NetworkClient();
	static SOCKET m_SocketConnection;

private:
	// Create a singleton socket so we can control what happens if this
	// class is instantiated more than once.

	std::wstring m_HostName;
	std::wstring m_HostPort;
	// This is the main loop that will be used for sending and receving data. When a call comes in we will have a callback to a correct processor
	void ControllerLoop();
public:
	// Start the network client when we're ready.
	void Start();
	HRESULT SendData(const char& packet);
	HRESULT RecvData(char& packet);
	LPWSAOVERLAPPED_COMPLETION_ROUTINE m_DataSent;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE m_DataReceived;
};



#endif