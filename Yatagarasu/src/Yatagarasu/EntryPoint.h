#pragma once

#ifdef YG_PLATFORM_WINDOWS

extern Yatagarasu::Application* Yatagarasu::CreateApplication();

int main(int argc, char** argv)
{
	Yatagarasu::Log::Init();
	YG_CORE_WARN("Initialized Log!");
	int a = 42;
	YG_INFO("Unyu! The answer to life, the universe, and everything is {0}", a);

	auto app = Yatagarasu::CreateApplication();
	app->Run();
	delete app;
}

#endif