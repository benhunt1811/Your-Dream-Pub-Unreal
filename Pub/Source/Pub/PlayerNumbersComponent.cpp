// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerNumbersComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UPlayerNumbersComponent::UPlayerNumbersComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	NPCMoneyAmount = 150;

	LevelUpSound = CreateDefaultSubobject<USoundBase>(TEXT("LevelUpSound"));
}


// Called when the game starts
void UPlayerNumbersComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerNumbersComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentXP >= MaxXP)
	{
		IncreaseLevel();
	}

	// ...
}

void UPlayerNumbersComponent::IncreaseLevel()
{
	CurrentLevel++;
	CurrentXP -= MaxXP;
	MaxXP += 10;

	OnLevelUp.Broadcast();

	if (LevelUpSound)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), LevelUpSound, 1, 1, 0, NULL, NULL, true);
	}
}

