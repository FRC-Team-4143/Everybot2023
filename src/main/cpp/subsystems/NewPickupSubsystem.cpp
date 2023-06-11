#pragma once
#include <iostream>
#include "subsystems/NewPickupSubsystem.h"
#include "Constants.h"
using namespace std;
NewPickupSubsystem::NewPickupSubsystem(frc::XboxController* controller)
: pickUpMotor{41, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
m_driverController(controller)
{

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
    if(m_driverController->GetLeftTriggerAxis() > 0.2){
		pickUpMotor.Set(-.25);
	} else if(m_driverController->GetRightTriggerAxis() > 0.2){
		pickUpMotor.Set(.25);
		} else{
		pickUpMotor.Set(0);
	}

}
