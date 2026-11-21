
#include "Dev/MySpiralStairs.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"


AMySpiralStairs::AMySpiralStairs()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));


    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
    StepMesh = MeshAsset.Object;
   

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(
        TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));   
    CylinderMesh = CylinderAsset.Object;




    // «десь используютс€ значени€ C++ по умолчанию
   

}

void AMySpiralStairs::OnConstruction(const FTransform& Transform) {

    Super::OnConstruction(Transform);

    DestroyStairComponents();

    if (!StepMesh) return;

    const int32 TotalSteps = NumberOfTurns * StepsPerTurn;
    const float AngleStep = 360.0f / StepsPerTurn;

    UStaticMeshComponent* Cylinder = NewObject<UStaticMeshComponent>(this, TEXT ("Cylinder"));


    Cylinder->SetupAttachment(RootComponent);
    Cylinder->SetStaticMesh(CylinderMesh);
   

    const FBoxSphereBounds Bounds = CylinderMesh->GetBounds();
    const float BaseHeight = Bounds.BoxExtent.Z * 2.0f; // полна€ высота меша
    const float ScaledHeight = BaseHeight * CylinderHeight;  // высота цилиндра
   
    const float StairsHeight = FMath::Max(0.0f, (TotalSteps - 1) * HeightBetweenStep); // высота нашей лестницы
    const float DesiredHeight = CylinderHeight; // теперь в ёЌ»“ј’, не scale!
   
    if (BaseHeight > 0) {

        const float TargetHeight = FMath::Min(DesiredHeight, StairsHeight);

        const float ZScale = TargetHeight / BaseHeight; 
        FVector CylinderScale(CylinderRadius, CylinderRadius, ZScale);
        Cylinder->SetRelativeLocation(FVector(0, 0, TargetHeight / 2));
        Cylinder->SetRelativeScale3D(CylinderScale);
        Cylinder->RegisterComponent();
    }
    else {
        // ¬ырожденный меш Ч просто ставим без масштаба
        Cylinder->SetRelativeScale3D(FVector(CylinderRadius, CylinderRadius, 1.0f));
        Cylinder->SetRelativeLocation(FVector::ZeroVector);
    }


    for (int32 i = 0; i < TotalSteps; ++i)
    {
        const FName ComponentName(FString::Printf(TEXT("Step_%d"), i));

        UStaticMeshComponent* Step = NewObject<UStaticMeshComponent>(this, ComponentName);

        Step->SetupAttachment(RootComponent);

        if (StepMesh)
        {
            Step->SetStaticMesh(StepMesh);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("StepMesh is NULL"));
        }

        const float AngleDegrees = AngleStep * i;
        const float AngleRadians = FMath::DegreesToRadians(AngleDegrees);

        const float X = FMath::Cos(AngleRadians) * Radius;
        const float Y = FMath::Sin(AngleRadians) * Radius;
        const float Z = i * HeightBetweenStep;

        FVector Location(X, Y, Z);

        if (bIsClockwise)
        {
            Location = FVector(X, Y, Z);
        }
        else
        {
            Location = FVector(Y, X, Z);
        }

        Step->SetRelativeLocation(Location);
        Step->SetRelativeRotation(FRotator(0.0f, AngleDegrees, 0.0f));
        Step->SetRelativeScale3D(FVector(StepScaleX, StepScaleY, StepScaleZ));
        Step->RegisterComponent();            // ќЅя«ј“≈Ћ№Ќќ дл€ по€влени€ в мире

        mStepComponents.Add(Step);

    }


}

void AMySpiralStairs::DestroyStairComponents()
{
    for (UStaticMeshComponent* lComp : mStepComponents)
    {
        if (lComp)
        {
            lComp->DestroyComponent();

        }

    }

    mStepComponents.Empty();

}


void AMySpiralStairs::BeginPlay()
{
	Super::BeginPlay();
	
}

