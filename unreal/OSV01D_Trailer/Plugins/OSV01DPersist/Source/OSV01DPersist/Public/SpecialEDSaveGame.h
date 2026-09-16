#pragma once

#include "GameFramework/SaveGame.h"
#include "SpecialEDSaveGame.generated.h"

UCLASS()
class OSV01DPERSIST_API USpecialEDSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY() int32 Plays = 0;
	UPROPERTY() float LastT = 0.f;
	UPROPERTY() bool bMuted = false;
	UPROPERTY() int32 LookFails = 0;
	UPROPERTY() float Strength = 1.f;

	static constexpr const TCHAR* Slot = TEXT("SpecialED");
};
