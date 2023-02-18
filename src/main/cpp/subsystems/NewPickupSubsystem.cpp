#pragma once
#include <iostream>
#include "subsystems/NewPickupSubsystem.h"
#include "Constants.h"
using namespace std;
NewPickupSubsystem::NewPickupSubsystem(int motorNumber, frc::XboxController* controller)
: pickUpMotor{motorNumber, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, 
  m_Controller(controller)
{

}

void NewPickupSubsystem::setIntakeMotor(){
    if (m_Controller->GetRightTriggerAxis() > 0.1){
        pickUpMotor.Set(m_Controller->GetLeftTriggerAxis());
        std::cout<<"Pickup motor is currently operating ";
    }
    else if (m_Controller->GetLeftTriggerAxis() > 0.1){
        pickUpMotor.Set(-m_Controller->GetLeftTriggerAxis());
        std::cout<<"Pickup motor is currently operating ";
    }
    else{
        pickUpMotor.Set(0);
    }
    
}
