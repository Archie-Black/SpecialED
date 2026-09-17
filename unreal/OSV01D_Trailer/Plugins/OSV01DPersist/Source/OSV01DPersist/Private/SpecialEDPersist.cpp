#include "SpecialEDPersist.h"
#include "Kismet/GameplayStatics.h"

USpecialEDSaveGame* USpecialEDPersist::LoadOrCreate()
{
	if (USaveGame* Existing = UGameplayStatics::LoadGameFromSlot(USpecialEDSaveGame::Slot, 0))
	{
		if (USpecialEDSaveGame* Casted = Cast<USpecialEDSaveGame>(Existing))
		{
			return Casted;
		}
	}
	return Cast<USpecialEDSaveGame>(UGameplayStatics::CreateSaveGameObject(USpecialEDSaveGame::StaticClass()));
}

void USpecialEDPersist::Commit(USpecialEDSaveGame* Mem)
{
	if (!Mem)
	{
		return;
	}
	UGameplayStatics::SaveGameToSlot(Mem, USpecialEDSaveGame::Slot, 0);
}

void USpecialEDPersist::NotePlay(float T, bool bMuted)
{
	USpecialEDSaveGame* Mem = LoadOrCreate();
	Mem->Plays += 1;
	Mem->LastT = T;
	Mem->bMuted = bMuted;
	Commit(Mem);
}

void USpecialEDPersist::NoteLookFail()
{
	USpecialEDSaveGame* Mem = LoadOrCreate();
	Mem->LookFails += 1;
	Mem->Strength = FMath::Max(0.35f, Mem->Strength * 0.82f);
	Commit(Mem);
}

void USpecialEDPersist::NoteLookOk()
{
	USpecialEDSaveGame* Mem = LoadOrCreate();
	Mem->Strength = FMath::Min(1.f, Mem->Strength + 0.04f);
	Commit(Mem);
}

bool USpecialEDPersist::ShouldUseLook()
{
	return LoadOrCreate()->LookFails < 2;
}
