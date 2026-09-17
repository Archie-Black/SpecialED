#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** Public isolate look. Not the private OS palette engine. */
struct OSV01DLOOK_API FOSV01DLook
{
	static constexpr float KappaMax = 0.41421356237f; // sqrt(2)-1

	static FLinearColor Vanta()
	{
		return FLinearColor(0.004f, 0.004f, 0.006f, 1.f);
	}

	static FLinearColor Cobalt()
	{
		return FLinearColor(0.02f, 0.18f, 0.72f, 1.f);
	}

	static FLinearColor Uranium()
	{
		return FLinearColor(0.62f, 0.78f, 0.12f, 1.f);
	}
};

class FOSV01DLookModule : public IModuleInterface
{
};
