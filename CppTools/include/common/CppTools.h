// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CPPTOOLS_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CPPTOOLS_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef CPPTOOLS_EXPORTS
#define CPPTOOLS_API __declspec(dllexport)
#define CPPTOOLS_TYPE_API CPPTOOLS_API
#define CPPTOOLS_TCLASS_API CPPTOOLS_API
#define CPPTOOLS_TFUNC_API CPPTOOLS_API
#define CPPTOOLS_INLINEFUNC_API CPPTOOLS_API
#define CPPTOOLS_INLINE_TFUNC_API CPPTOOLS_API
#else
#define CPPTOOLS_API
#define CPPTOOLS_TYPE_API
#define CPPTOOLS_TCLASS_API
#define CPPTOOLS_TFUNC_API
#define CPPTOOLS_INLINEFUNC_API
#define CPPTOOLS_INLINE_TFUNC_API
#endif