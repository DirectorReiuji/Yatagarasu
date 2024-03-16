#pragma once

#include "Core.h"

namespace Yatagarasu {
	class YATAGARASU_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined within a CLIENT
	Application* CreateApplication();
}
