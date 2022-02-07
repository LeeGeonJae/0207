#pragma once

class World;

class MyEngine
{
public:
	MyEngine();
	virtual ~MyEngine();

	void Run();

	void Stop();
	
	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

protected:
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool bIsRunning = true;

	//포인터로 메모리에 범위를 지정한다.
	//앞에 class World;를 입력하면 앞에 class를 쓰지 않아도 된다.
	class World* CurrentWorld;
};