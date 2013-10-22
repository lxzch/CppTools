#pragma once
#ifndef CTSAFEOBJECT_H
#define CTSAFEOBJECT_H

#include <common\CTObject.h>

namespace CppTools
{
	namespace CTData
	{
		class CPPTOOLS_API CTCountableObject
			: public CTObject
		{
		public:
			CTCountableObject();
			~CTCountableObject();

		public:
			static int getCount();

		private:
			static int _count;
		};

		class CPPTOOLS_API CTSoleObject
			: public CTCountableObject
		{
		public:
			CTSoleObject();
		};
	}
}

#endif