#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
//	세가지 방법 모두 똑같은 것으로 최대한 줄여서 쓴 것이 아래에 있는 방법입니다.
//	메모리에 할당된 액터를 찾아 메모리를 해제하는 코드입니다.
// 	1.
//	for (int i = 0; i < ActorList.size(); ++i)
//	{
//		delete ActorList[i];
//		ActorList[i] = nullptr;
//	}
//
//	2.
	for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
//	for (std::vector<actor*>::iterator iter = actorlist.begin(); iter != actorlist.end(); ++iter)
	{
		delete* iter;
		*iter = nullptr;
	}
//	
// 	3.
//	range for
//	액터를 찾아서 메모리 해제
	//for (auto CurrentActor : ActorList)
	//{
	//	delete CurrentActor;
	//	CurrentActor = nullptr;
	//}

	ActorList.clear();
}

void World::SpawnActor(Actor* NewActor)
{
	ActorList.push_back(NewActor);
}

void World::DestroyActor(Actor* DestroyActor)
{
	//세가지 방법 모두 똑같은 방법.
	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	if (*iter == DestroyActor)
	//	{
	//		delete *iter;
	//		*iter = nullptr;
	//		iter = ActorList.erase(iter);
	//		break;
	//	}
	//}

	//auto DestroyIter = find(ActorList.begin(), ActorList.end(), DestroyActor);
	//ActorList.erase(DestroyIter);

	//자료 구조 Actor리스트에서 관리 리스트에서 삭제
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//메모리에서 실제로 삭제
	delete DestroyActor;
	DestroyActor = nullptr;
}

void World::Tick()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick();
	}
}

void World::Render()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render();
	}
}

void World::Input()
{

}

void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}
