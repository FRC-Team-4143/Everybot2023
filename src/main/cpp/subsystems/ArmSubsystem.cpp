#pragma once
#include <iostream>
#include "subsystems/ArmSubsystem.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/SparkMaxRelativeEncoder.h>

using namespace std;

ArmSubsystem::ArmSubsystem(frc::XboxController* controller)
: armMotor{3, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
m_driverController(controller),
armEncoder(armMotor.GetEncoder())
{

armEncoder.SetPosition(0.0);
}

void ArmSubsystem::setArmMotor(double percentOutput){
          armMotor.Set(percentOutput);
          //std::cout<<"motor is doing something" << percentOutput<<endl;
}

void ArmSubsystem::setArmCurrent(double current){
          //std::cout<<"motor is doing something" << percentOutput<<endl;
}

void ArmSubsystem::Periodic() {
    if(m_driverController->GetLeftBumper()){
		//setArmMotor(-0.215);
	} else if(m_driverController->GetRightBumper()){
		//setArmMotor(0.225);
	} else{
		//setArmMotor(0);
	}

frc::SmartDashboard::PutNumber("Everybot arm position", armEncoder.GetPosition());
	
}
bool ArmSubsystem::isArmOut() {
	if(armEncoder.GetPosition() < -15.5) {return true;}
	else {return false;}
}

	

