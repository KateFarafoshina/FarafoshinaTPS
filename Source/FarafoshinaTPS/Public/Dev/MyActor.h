// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class FARAFOSHINATPS_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();
	virtual void Tick(float DeltaTime) override;

	//Нет значения по умолчанию, но его можно изменить
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UE|Name")
	FString Name;

	//Нет дефолтного значения, изменение через блупринты
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UE|Health")
	float HP; 

	//Для установки дефолного значения без последующего изменения
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UE|Health", meta = (UIMin = "100", UIMax = "1000", ClampMin = "100", ClampMax = "1000"))
	int MaxHP;

	//Для установки дефолтного значения и последующего его изменения
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UE|Damage")
	int Damage;

	UFUNCTION(BlueprintImplementableEvent)
	void MyPrintHP();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int ChangeSpeed(int MoveSpeed);

	UFUNCTION(BlueprintCallable)
	bool AreNumbersEqual(int A, int B, int& Sum);

protected:
	virtual void BeginPlay() override;



private:	

};
