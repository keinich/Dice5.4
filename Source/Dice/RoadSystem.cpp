// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadSystem.h"

// Sets default values
ARoadSystem::ARoadSystem() {
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoadSystem::BeginPlay() {
  Super::BeginPlay();

}

bool ARoadSystem::ShouldTickIfViewportsOnly() const {
  if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor && UseEditorTick) {
    return true;
  }
  else {
    return false;
  }
}

// Called every frame
// Separated Tick functionality and making sure that it truly can only happen in the editor. Might be a bit overkill but you can easily consolidate if you'd like. 
void ARoadSystem::Tick(float DeltaTime) {
  if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor) {
//#if WITH_EDITOR
    BlueprintEditorTick(DeltaTime);
//#endif
  }
  else {
    //throw "This tick should not be called in a non-editor context.";    
    Super::Tick(DeltaTime);
  }
}

