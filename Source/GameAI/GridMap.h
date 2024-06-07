// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCell.h"
#include "GridMap.generated.h"

UCLASS()
class GAMEAI_API AGridMap : public AActor
{
	GENERATED_BODY()
	
public:
    AGridMap();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
    int32 Width;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
    int32 Height;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
    float CellSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
    TArray<AGridCell*> Cells;

    UFUNCTION(BlueprintCallable, Category = "Grid")
    void InitializeGrid();

    UFUNCTION(BlueprintCallable, Category = "Grid")
    AGridCell* GetCellFromWorld(const FVector& WorldPosition);

private:
    bool IsObstacle(const FVector& WorldPosition);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
