#pragma once

#ifdef VK_PLATFORM_WINDOWS

extern Vaky::Application* Vaky::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Vaky Engine!");
	auto app = Vaky::CreateApplication();
	app->Run();
	delete app;
}

#endif