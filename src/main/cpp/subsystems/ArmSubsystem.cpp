#pragma once
#include <iostream>
#include "subsystems/ArmSubsystem.h"
#include "Constants.h"
using namespace std;
ArmSubsystem::ArmSubsystem(int motorNumber, frc::XboxController* controller)
: armMotor{motorNumber, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, 
  m_Controller(controller)
{

}

void ArmSubsystem::setArmMotor(){
    if(m_Controller->GetRightBumper()){
            armMotor.Set(percentOutput);
            std::cout<<"motor output " << percentOutput<<endl;
    }
    else if(m_Controller->GetLeftBumper()){
            armMotor.Set(-percentOutput);
            std::cout<<"motor output " << percentOutput<<endl;
    }
    else{
        armMotor.Set(0);
    }
    
}

