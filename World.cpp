#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
//	������ ��� ��� �Ȱ��� ������ �ִ��� �ٿ��� �� ���� �Ʒ��� �ִ� ����Դϴ�.
//	�޸𸮿� �Ҵ�� ���͸� ã�� �޸𸮸� �����ϴ� �ڵ��Դϴ�.
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
//	���͸� ã�Ƽ� �޸� ����
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
	//������ ��� ��� �Ȱ��� ���.
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

	//�ڷ� ���� Actor����Ʈ���� ���� ����Ʈ���� ����
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//�޸𸮿��� ������ ����
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
