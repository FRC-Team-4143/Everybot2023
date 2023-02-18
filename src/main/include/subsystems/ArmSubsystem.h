#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/XboxController.h>
class ArmSubsystem : public frc2::SubsystemBase {
public:
    ArmSubsystem(int motorNumber, frc::XboxController* controller);
private:
    double percentOutput = 0.40;
    rev::CANSparkMax armMotor;
    void setArmMotor();
    frc::XboxController* m_Controller;
};