// Fill out your copyright notice in the Description page of Project Settings.


#include "GridMap.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AGridMap::AGridMap()
{
    PrimaryActorTick.bCanEverTick = false;
    Width = 100;
    Height = 100;
    CellSize = 100.0f;
}

void AGridMap::InitializeGrid()
{
    for (int32 y = 0; y < Height; ++y)
    {
        for (int32 x = 0; x < Width; ++x)
        {
            FVector worldPos = GetActorLocation() + FVector(x * CellSize, y * CellSize, 0);
            FActorSpawnParameters spawnParams;
            spawnParams.Owner = this;
            AGridCell* cell = GetWorld()->SpawnActor<AGridCell>(worldPos, FRotator::ZeroRotator, spawnParams);
            cell->bIsWalkable = !IsObstacle(worldPos);
            cell->GridX = x;
            cell->GridY = y;
            Cells.Add(cell);
        }
    }
}

AGridCell* AGridMap::GetCellFromWorld(const FVector& WorldPosition)
{
    int32 x = FMath::FloorToInt((WorldPosition.X - GetActorLocation().X) / CellSize);
    int32 y = FMath::FloorToInt((WorldPosition.Y - GetActorLocation().Y) / CellSize);
    if (x >= 0 && x < Width && y >= 0 && y < Height)
    {
        return Cells[y * Width + x];
    }
    return nullptr;
}

bool AGridMap::IsObstacle(const FVector& WorldPosition)
{
    FHitResult hitResult;
    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(this);

    FVector start = WorldPosition + FVector::UpVector * 100;
    FVector end = WorldPosition + FVector::DownVector * 100;

    bool hit = GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECC_Visibility, queryParams);
    return !hit || hitResult.GetActor()->ActorHasTag("Obstacle");

    return false;
}

// Called when the game starts or when spawned
void AGridMap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

