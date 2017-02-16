// Fill out your copyright notice in the Description page of Project Settings.

#include "OnTheRun.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "PatrolRouteComponent.h"
#include "BehaviorTree/blackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// TODO protect against no Patrol Route Component
	// 

	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	
	// Warn about protect against empty patrol routes
	auto PatrolPoints = PatrolRoute->GetPatrolRoute();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A Guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), Index);

	// TODO protect against empty patrol routes

	return EBTNodeResult::Succeeded;
}


