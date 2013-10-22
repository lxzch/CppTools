#include <cuda\CTCuda.h>
#include <CTGLEW>
#include <cudaGL.h>
#include <cuda_gl_interop.h>

#pragma comment(lib, "cufft.lib")
#pragma comment(lib, "cutil32D.lib")
#pragma comment(lib, "cudart.lib")

#ifdef _DEBUG
#pragma comment(lib, "ctgld.lib")
#endif

#ifdef NDEBUG
#pragma comment(lib, "ctgl.lib")
#endif

typedef GLuint CTCudaGLHandle;
typedef void** CTCudaBuffer;

namespace CppTools
{
	namespace CTCuda
	{
		CPPTOOLS_INLINEFUNC_API inline void cuRegBO(CTCudaGLHandle cugl_handle)
		{
			cudaGLRegisterBufferObject(cugl_handle);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuUnregBO(CTCudaGLHandle cugl_handle)
		{
			cudaGLUnregisterBufferObject(cugl_handle);
			glDeleteBuffers(1, &cugl_handle);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuUseBO(CTCudaBuffer cugl_buffer, CTCudaGLHandle cugl_handle)
		{
			cudaGLMapBufferObject(cugl_buffer, cugl_handle);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuUnuseBO(CTCudaGLHandle cugl_handle)
		{
			cudaGLUnmapBufferObject(cugl_handle);
		}

		CPPTOOLS_API void cuStartVBO(CTCudaGLHandle* cugl_handle, UINT memory_size);
		CPPTOOLS_API CTCudaGLHandle cuCreateVBO(UINT memory_size);
	}
}
