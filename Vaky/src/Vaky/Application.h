#pragma once

#include "Core.h"

namespace Vaky {

	class VAKY_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}

