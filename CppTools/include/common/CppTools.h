// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CPPTOOLS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CPPTOOLS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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