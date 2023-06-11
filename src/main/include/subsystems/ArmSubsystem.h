#pragma once
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/XboxController.h>
class ArmSubsystem : public frc2::SubsystemBase {
public:
    ArmSubsystem(frc::XboxController* controller);
    void setArmMotor(double percentOutput);
private:
   frc::XboxController* m_driverController;
    rev::CANSparkMax armMotor;
    void Periodic() override;

    
    
};