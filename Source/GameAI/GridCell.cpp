// Fill out your copyright notice in the Description page of Project Settings.


#include "GridCell.h"

// Sets default values
AGridCell::AGridCell()
{
    PrimaryActorTick.bCanEverTick = false;
    bIsWalkable = true;
    GridX = 0;
    GridY = 0;
}

// Called when the game starts or when spawned
void AGridCell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

