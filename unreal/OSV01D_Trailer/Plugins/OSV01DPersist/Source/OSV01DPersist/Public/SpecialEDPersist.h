#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpecialEDSaveGame.h"
#include "SpecialEDPersist.generated.h"

UCLASS()
class OSV01DPERSIST_API USpecialEDPersist : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SpecialED")
	static USpecialEDSaveGame* LoadOrCreate();

	UFUNCTION(BlueprintCallable, Category = "SpecialED")
	static void Commit(USpecialEDSaveGame* Mem);

	UFUNCTION(BlueprintCallable, Category = "SpecialED")
	static void NotePlay(float T, bool bMuted);

	UFUNCTION(BlueprintCallable, Category = "SpecialED")
	static void NoteLookFail();

	UFUNCTION(BlueprintCallable, Category = "SpecialED")
	static void NoteLookOk();

	UFUNCTION(BlueprintPure, Category = "SpecialED")
	static bool ShouldUseLook();
};
