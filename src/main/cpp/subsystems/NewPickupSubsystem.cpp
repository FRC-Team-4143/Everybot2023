#pragma once
#include <iostream>
#include "subsystems/NewPickupSubsystem.h"
#include "Constants.h"
using namespace std;
NewPickupSubsystem::NewPickupSubsystem(frc::XboxController* controller)
: pickUpMotor{41},
m_driverController(controller)
{
    //sets motor direction of intake for cube intake
    isCubePickup = 1;
}


void NewPickupSubsystem::setIntakeMotor(double axis){
    if (axis > 0.1){
        pickUpMotor.Set(axis);
        std::cout<<"Pickup motor is currently operating ";
    }
    else{
        pickUpMotor.Set(0);
    }
}
    
    void NewPickupSubsystem::Periodic() {

    if(m_driverController->GetBButton()){
        isCubePickup = 1;
    }

    if(m_driverController->GetYButton()){
        isCubePickup = -1;
    }

    if(m_driverController->GetLeftTriggerAxis() > 0.2){
		pickUpMotor.Set(-.75 * isCubePickup);
	} else if(m_driverController->GetRightTriggerAxis() > 0.2){
		pickUpMotor.Set(.75 * isCubePickup);
		} else{
		pickUpMotor.Set(0);
	}

    

}

void NewPickupSubsystem::autoOut (bool isArmOut) {
        if (isArmOut) {pickUpMotor.Set(-0.75* isCubePickup);}
}

