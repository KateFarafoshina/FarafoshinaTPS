// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpiralStairs.generated.h"

UCLASS()
class FARAFOSHINATPS_API AMySpiralStairs : public AActor
{
	GENERATED_BODY()
	
public:	
	AMySpiralStairs();

	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	float HeightBetweenStep = 30.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	float Radius = 300.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	int32 NumberOfTurns = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	int32 StepsPerTurn = 15;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	UStaticMesh* StepMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	bool bIsClockwise = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE13")
	float StepScaleX = 1.0f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE13")
	float StepScaleY = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE13")
	float StepScaleZ = 1.0f;



	// Цилиндр
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE13")
	UStaticMesh* CylinderMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE13")
	float CylinderRadius = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE13", 
		meta = (ClampMin = "0.0", UIMin = "0.0"))
	float CylinderHeight = 10.0f;

	
private:
	TArray<UStaticMeshComponent*> mStepComponents;


protected:
	virtual void BeginPlay() override;

public:	
	//virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	void DestroyStairComponents();
};
