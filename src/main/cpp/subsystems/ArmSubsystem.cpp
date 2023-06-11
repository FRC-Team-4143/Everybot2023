#pragma once
#include <iostream>
#include "subsystems/ArmSubsystem.h"
#include "Constants.h"
using namespace std;

ArmSubsystem::ArmSubsystem(frc::XboxController* controller)
: armMotor{3, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
m_driverController(controller)
{

}

void ArmSubsystem::setArmMotor(double percentOutput){
          armMotor.Set(percentOutput);
          std::cout<<"motor is doing something" << percentOutput<<endl;

    
    
}

void ArmSubsystem::Periodic() {
    if(m_driverController->GetLeftBumper()){
		setArmMotor(-0.215);
		std::cout<<"getLeftBumper"<< endl;
	} else if(m_driverController->GetRightBumper()){
		setArmMotor(0.225);
		std::cout<<"getRightBumper"<< endl;
	} else{
		setArmMotor(0);
		std::cout<<"Nothing"<<endl;
	}
}
