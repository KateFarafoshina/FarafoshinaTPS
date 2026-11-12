// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev/MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


int AMyActor::ChangeSpeed_Implementation(int Speed)
{
	return Speed = 50;
}

bool AMyActor::AreNumbersEqual(int A, int B, int& Sum)
{
	Sum = A + B;
	return A == B;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MyPrintHP();
}

