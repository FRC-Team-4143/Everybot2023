#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/XboxController.h>
#include <rev/SparkMaxRelativeEncoder.h>
class ArmSubsystem : public frc2::SubsystemBase {
public:
    ArmSubsystem(frc::XboxController* controller);
    void setArmMotor(double percentOutput);
    void setArmCurrent(double current);
    bool isArmOut();
    int autoArmCount;
private:
   frc::XboxController* m_driverController;
    rev::CANSparkMax armMotor;
    void Periodic() override;
    rev::SparkMaxRelativeEncoder armEncoder;

    
    
};