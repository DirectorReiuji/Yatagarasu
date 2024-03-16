#pragma once

#ifdef YG_PLATFORM_WINDOWS

extern Yatagarasu::Application* Yatagarasu::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Yatagarasu::CreateApplication();
	app->Run();
	delete app;
}

#endif