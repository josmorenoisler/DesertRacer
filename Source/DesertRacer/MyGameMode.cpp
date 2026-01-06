#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMyGameMode::ResetLevel(bool bIsWin)
{
	float resetTime = LoseResetTime;
	if (bIsWin)
	{
		resetTime = WinResetTime;
	}

	GetWorldTimerManager().SetTimer(ResetGameTimer, this, &AMyGameMode::OnResetGameTimerTimeout, 1.0f, false, resetTime);
	
}

void AMyGameMode::OnResetGameTimerTimeout()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainLevel"));
}
